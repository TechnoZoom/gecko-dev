/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "nsFormData.h"
#include "nsIVariant.h"
#include "nsIInputStream.h"
#include "mozilla/dom/File.h"
#include "mozilla/dom/HTMLFormElement.h"

using namespace mozilla;
using namespace mozilla::dom;

nsFormData::nsFormData(nsISupports* aOwner)
  : nsFormSubmission(NS_LITERAL_CSTRING("UTF-8"), nullptr)
  , mOwner(aOwner)
{
}

// -------------------------------------------------------------------------
// nsISupports

NS_IMPL_CYCLE_COLLECTION_CLASS(nsFormData)

NS_IMPL_CYCLE_COLLECTION_UNLINK_BEGIN(nsFormData)
  NS_IMPL_CYCLE_COLLECTION_UNLINK(mOwner)

  for (uint32_t i = 0, len = tmp->mFormData.Length(); i < len; ++i) {
    ImplCycleCollectionUnlink(tmp->mFormData[i].fileValue);
  }

  NS_IMPL_CYCLE_COLLECTION_UNLINK_PRESERVED_WRAPPER
NS_IMPL_CYCLE_COLLECTION_UNLINK_END

NS_IMPL_CYCLE_COLLECTION_TRAVERSE_BEGIN(nsFormData)
  NS_IMPL_CYCLE_COLLECTION_TRAVERSE(mOwner)

  for (uint32_t i = 0, len = tmp->mFormData.Length(); i < len; ++i) {
   ImplCycleCollectionTraverse(cb,tmp->mFormData[i].fileValue,
                               "mFormData[i].fileValue", 0);
  }

  NS_IMPL_CYCLE_COLLECTION_TRAVERSE_SCRIPT_OBJECTS
NS_IMPL_CYCLE_COLLECTION_TRAVERSE_END

NS_IMPL_CYCLE_COLLECTION_TRACE_WRAPPERCACHE(nsFormData)

NS_IMPL_CYCLE_COLLECTING_ADDREF(nsFormData)
NS_IMPL_CYCLE_COLLECTING_RELEASE(nsFormData)

NS_INTERFACE_MAP_BEGIN_CYCLE_COLLECTION(nsFormData)
  NS_WRAPPERCACHE_INTERFACE_MAP_ENTRY
  NS_INTERFACE_MAP_ENTRY(nsIDOMFormData)
  NS_INTERFACE_MAP_ENTRY(nsIXHRSendable)
  NS_INTERFACE_MAP_ENTRY_AMBIGUOUS(nsISupports, nsIDOMFormData)
NS_INTERFACE_MAP_END

// -------------------------------------------------------------------------
// nsFormSubmission
nsresult
nsFormData::GetEncodedSubmission(nsIURI* aURI,
                                 nsIInputStream** aPostDataStream)
{
  NS_NOTREACHED("Shouldn't call nsFormData::GetEncodedSubmission");
  return NS_OK;
}

void
nsFormData::Append(const nsAString& aName, const nsAString& aValue)
{
  AddNameValuePair(aName, aValue);
}

void
nsFormData::Append(const nsAString& aName, File& aBlob,
                   const Optional<nsAString>& aFilename)
{
  nsString filename;
  if (aFilename.WasPassed()) {
    filename = aFilename.Value();
  } else {
    filename.SetIsVoid(true);
  }
  AddNameFilePair(aName, &aBlob, filename);
}

void
nsFormData::Delete(const nsAString& aName)
{
  // We have to use this slightly awkward for loop since uint32_t >= 0 is an
  // error for being always true.
  for (uint32_t i = mFormData.Length(); i-- > 0; ) {
    if (aName.Equals(mFormData[i].name)) {
      mFormData.RemoveElementAt(i);
    }
  }
}

void
nsFormData::ExtractValue(const FormDataTuple& aTuple,
                         OwningFileOrUSVString* aOutValue)
{
  if (aTuple.valueIsFile) {
    aOutValue->SetAsFile() = aTuple.fileValue;
  } else {
    aOutValue->SetAsUSVString() = aTuple.stringValue;
  }
}

void
nsFormData::Get(const nsAString& aName,
                Nullable<OwningFileOrUSVString>& aOutValue)
{
  for (uint32_t i = 0; i < mFormData.Length(); ++i) {
    if (aName.Equals(mFormData[i].name)) {
      ExtractValue(mFormData[i], &aOutValue.SetValue());
      return;
    }
  }

  aOutValue.SetNull();
}

void
nsFormData::GetAll(const nsAString& aName,
                   nsTArray<OwningFileOrUSVString>& aValues)
{
  for (uint32_t i = 0; i < mFormData.Length(); ++i) {
    if (aName.Equals(mFormData[i].name)) {
      OwningFileOrUSVString* element = aValues.AppendElement();
      ExtractValue(mFormData[i], element);
    }
  }
}

bool
nsFormData::Has(const nsAString& aName)
{
  for (uint32_t i = 0; i < mFormData.Length(); ++i) {
    if (aName.Equals(mFormData[i].name)) {
      return true;
    }
  }

  return false;
}

nsFormData::FormDataTuple*
nsFormData::RemoveAllOthersAndGetFirstFormDataTuple(const nsAString& aName)
{
  FormDataTuple* lastFoundTuple = nullptr;
  uint32_t lastFoundIndex = mFormData.Length();
  // We have to use this slightly awkward for loop since uint32_t >= 0 is an
  // error for being always true.
  for (uint32_t i = mFormData.Length(); i-- > 0; ) {
    if (aName.Equals(mFormData[i].name)) {
      if (lastFoundTuple) {
        // The one we found earlier was not the first one, we can remove it.
        mFormData.RemoveElementAt(lastFoundIndex);
      }

      lastFoundTuple = &mFormData[i];
      lastFoundIndex = i;
    }
  }

  return lastFoundTuple;
}

void
nsFormData::Set(const nsAString& aName, File& aBlob,
                const Optional<nsAString>& aFilename)
{
  FormDataTuple* tuple = RemoveAllOthersAndGetFirstFormDataTuple(aName);
  if (tuple) {
    nsAutoString filename;
    if (aFilename.WasPassed()) {
      filename = aFilename.Value();
    } else {
      filename.SetIsVoid(true);
    }

    SetNameFilePair(tuple, aName, &aBlob, filename);
  } else {
    Append(aName, aBlob, aFilename);
  }
}

void
nsFormData::Set(const nsAString& aName, const nsAString& aValue)
{
  FormDataTuple* tuple = RemoveAllOthersAndGetFirstFormDataTuple(aName);
  if (tuple) {
    SetNameValuePair(tuple, aName, aValue);
  } else {
    Append(aName, aValue);
  }
}

// -------------------------------------------------------------------------
// nsIDOMFormData

NS_IMETHODIMP
nsFormData::Append(const nsAString& aName, nsIVariant* aValue)
{
  uint16_t dataType;
  nsresult rv = aValue->GetDataType(&dataType);
  NS_ENSURE_SUCCESS(rv, rv);

  if (dataType == nsIDataType::VTYPE_INTERFACE ||
      dataType == nsIDataType::VTYPE_INTERFACE_IS) {
    nsCOMPtr<nsISupports> supports;
    nsID *iid;
    rv = aValue->GetAsInterface(&iid, getter_AddRefs(supports));
    NS_ENSURE_SUCCESS(rv, rv);

    nsMemory::Free(iid);

    nsCOMPtr<nsIDOMBlob> domBlob = do_QueryInterface(supports);
    nsRefPtr<File> blob = static_cast<File*>(domBlob.get());
    if (domBlob) {
      Optional<nsAString> temp;
      Append(aName, *blob, temp);
      return NS_OK;
    }
  }

  char16_t* stringData = nullptr;
  uint32_t stringLen = 0;
  rv = aValue->GetAsWStringWithSize(&stringLen, &stringData);
  NS_ENSURE_SUCCESS(rv, rv);

  nsString valAsString;
  valAsString.Adopt(stringData, stringLen);

  Append(aName, valAsString);
  return NS_OK;
}

/* virtual */ JSObject*
nsFormData::WrapObject(JSContext* aCx)
{
  return FormDataBinding::Wrap(aCx, this);
}

/* static */ already_AddRefed<nsFormData>
nsFormData::Constructor(const GlobalObject& aGlobal,
                        const Optional<NonNull<HTMLFormElement> >& aFormElement,
                        ErrorResult& aRv)
{
  nsRefPtr<nsFormData> formData = new nsFormData(aGlobal.GetAsSupports());
  if (aFormElement.WasPassed()) {
    aRv = aFormElement.Value().WalkFormElements(formData);
  }
  return formData.forget();
}

// -------------------------------------------------------------------------
// nsIXHRSendable

NS_IMETHODIMP
nsFormData::GetSendInfo(nsIInputStream** aBody, uint64_t* aContentLength,
                        nsACString& aContentType, nsACString& aCharset)
{
  nsFSMultipartFormData fs(NS_LITERAL_CSTRING("UTF-8"), nullptr);

  for (uint32_t i = 0; i < mFormData.Length(); ++i) {
    if (mFormData[i].valueIsFile) {
      fs.AddNameFilePair(mFormData[i].name, mFormData[i].fileValue,
                         mFormData[i].filename);
    }
    else {
      fs.AddNameValuePair(mFormData[i].name, mFormData[i].stringValue);
    }
  }

  fs.GetContentType(aContentType);
  aCharset.Truncate();
  *aContentLength = 0;
  NS_ADDREF(*aBody = fs.GetSubmissionBody(aContentLength));

  return NS_OK;
}

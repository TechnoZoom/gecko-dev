/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "NPL"); you may not use this file except in
 * compliance with the NPL.  You may obtain a copy of the NPL at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the NPL is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL
 * for the specific language governing rights and limitations under the
 * NPL.
 *
 * The Initial Developer of this code under the NPL is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation.  All Rights
 * Reserved.
 */
/* AUTO-GENERATED. DO NOT EDIT!!! */

#include "jsapi.h"
#include "nscore.h"
#include "nsIScriptContext.h"
#include "nsIJSScriptObject.h"
#include "nsIScriptObjectOwner.h"
#include "nsIScriptGlobalObject.h"
#include "nsIPtr.h"
#include "nsString.h"
#include "nsIDOMHTMLElement.h"
#include "nsIDOMHTMLTableElement.h"
#include "nsIDOMHTMLTableCaptionElement.h"
#include "nsIDOMHTMLTableSectionElement.h"
#include "nsIDOMHTMLCollection.h"


static NS_DEFINE_IID(kIScriptObjectOwnerIID, NS_ISCRIPTOBJECTOWNER_IID);
static NS_DEFINE_IID(kIJSScriptObjectIID, NS_IJSSCRIPTOBJECT_IID);
static NS_DEFINE_IID(kIScriptGlobalObjectIID, NS_ISCRIPTGLOBALOBJECT_IID);
static NS_DEFINE_IID(kIHTMLElementIID, NS_IDOMHTMLELEMENT_IID);
static NS_DEFINE_IID(kIHTMLTableElementIID, NS_IDOMHTMLTABLEELEMENT_IID);
static NS_DEFINE_IID(kIHTMLTableCaptionElementIID, NS_IDOMHTMLTABLECAPTIONELEMENT_IID);
static NS_DEFINE_IID(kIHTMLTableSectionElementIID, NS_IDOMHTMLTABLESECTIONELEMENT_IID);
static NS_DEFINE_IID(kIHTMLCollectionIID, NS_IDOMHTMLCOLLECTION_IID);

NS_DEF_PTR(nsIDOMHTMLElement);
NS_DEF_PTR(nsIDOMHTMLTableElement);
NS_DEF_PTR(nsIDOMHTMLTableCaptionElement);
NS_DEF_PTR(nsIDOMHTMLTableSectionElement);
NS_DEF_PTR(nsIDOMHTMLCollection);

//
// HTMLTableElement property ids
//
enum HTMLTableElement_slots {
  HTMLTABLEELEMENT_CAPTION = -11,
  HTMLTABLEELEMENT_THEAD = -12,
  HTMLTABLEELEMENT_TFOOT = -13,
  HTMLTABLEELEMENT_ROWS = -14,
  HTMLTABLEELEMENT_TBODIES = -15,
  HTMLTABLEELEMENT_ALIGN = -16,
  HTMLTABLEELEMENT_BGCOLOR = -17,
  HTMLTABLEELEMENT_BORDER = -18,
  HTMLTABLEELEMENT_CELLPADDING = -19,
  HTMLTABLEELEMENT_CELLSPACING = -110,
  HTMLTABLEELEMENT_FRAME = -111,
  HTMLTABLEELEMENT_RULES = -112,
  HTMLTABLEELEMENT_SUMMARY = -113,
  HTMLTABLEELEMENT_WIDTH = -114
};

/***********************************************************************/
//
// HTMLTableElement Properties Getter
//
PR_STATIC_CALLBACK(JSBool)
GetHTMLTableElementProperty(JSContext *cx, JSObject *obj, jsval id, jsval *vp)
{
  nsIDOMHTMLTableElement *a = (nsIDOMHTMLTableElement*)JS_GetPrivate(cx, obj);

  // If there's no private data, this must be the prototype, so ignore
  if (nsnull == a) {
    return JS_TRUE;
  }

  if (JSVAL_IS_INT(id)) {
    switch(JSVAL_TO_INT(id)) {
      case HTMLTABLEELEMENT_CAPTION:
      {
        nsIDOMHTMLTableCaptionElement* prop;
        if (NS_OK == a->GetCaption(&prop)) {
          // get the js object
          if (prop != nsnull) {
            nsIScriptObjectOwner *owner = nsnull;
            if (NS_OK == prop->QueryInterface(kIScriptObjectOwnerIID, (void**)&owner)) {
              JSObject *object = nsnull;
              nsIScriptContext *script_cx = (nsIScriptContext *)JS_GetContextPrivate(cx);
              if (NS_OK == owner->GetScriptObject(script_cx, (void**)&object)) {
                // set the return value
                *vp = OBJECT_TO_JSVAL(object);
              }
              NS_RELEASE(owner);
            }
            NS_RELEASE(prop);
          }
          else {
            *vp = JSVAL_NULL;
          }
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLEELEMENT_THEAD:
      {
        nsIDOMHTMLTableSectionElement* prop;
        if (NS_OK == a->GetTHead(&prop)) {
          // get the js object
          if (prop != nsnull) {
            nsIScriptObjectOwner *owner = nsnull;
            if (NS_OK == prop->QueryInterface(kIScriptObjectOwnerIID, (void**)&owner)) {
              JSObject *object = nsnull;
              nsIScriptContext *script_cx = (nsIScriptContext *)JS_GetContextPrivate(cx);
              if (NS_OK == owner->GetScriptObject(script_cx, (void**)&object)) {
                // set the return value
                *vp = OBJECT_TO_JSVAL(object);
              }
              NS_RELEASE(owner);
            }
            NS_RELEASE(prop);
          }
          else {
            *vp = JSVAL_NULL;
          }
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLEELEMENT_TFOOT:
      {
        nsIDOMHTMLTableSectionElement* prop;
        if (NS_OK == a->GetTFoot(&prop)) {
          // get the js object
          if (prop != nsnull) {
            nsIScriptObjectOwner *owner = nsnull;
            if (NS_OK == prop->QueryInterface(kIScriptObjectOwnerIID, (void**)&owner)) {
              JSObject *object = nsnull;
              nsIScriptContext *script_cx = (nsIScriptContext *)JS_GetContextPrivate(cx);
              if (NS_OK == owner->GetScriptObject(script_cx, (void**)&object)) {
                // set the return value
                *vp = OBJECT_TO_JSVAL(object);
              }
              NS_RELEASE(owner);
            }
            NS_RELEASE(prop);
          }
          else {
            *vp = JSVAL_NULL;
          }
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLEELEMENT_ROWS:
      {
        nsIDOMHTMLCollection* prop;
        if (NS_OK == a->GetRows(&prop)) {
          // get the js object
          if (prop != nsnull) {
            nsIScriptObjectOwner *owner = nsnull;
            if (NS_OK == prop->QueryInterface(kIScriptObjectOwnerIID, (void**)&owner)) {
              JSObject *object = nsnull;
              nsIScriptContext *script_cx = (nsIScriptContext *)JS_GetContextPrivate(cx);
              if (NS_OK == owner->GetScriptObject(script_cx, (void**)&object)) {
                // set the return value
                *vp = OBJECT_TO_JSVAL(object);
              }
              NS_RELEASE(owner);
            }
            NS_RELEASE(prop);
          }
          else {
            *vp = JSVAL_NULL;
          }
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLEELEMENT_TBODIES:
      {
        nsIDOMHTMLCollection* prop;
        if (NS_OK == a->GetTBodies(&prop)) {
          // get the js object
          if (prop != nsnull) {
            nsIScriptObjectOwner *owner = nsnull;
            if (NS_OK == prop->QueryInterface(kIScriptObjectOwnerIID, (void**)&owner)) {
              JSObject *object = nsnull;
              nsIScriptContext *script_cx = (nsIScriptContext *)JS_GetContextPrivate(cx);
              if (NS_OK == owner->GetScriptObject(script_cx, (void**)&object)) {
                // set the return value
                *vp = OBJECT_TO_JSVAL(object);
              }
              NS_RELEASE(owner);
            }
            NS_RELEASE(prop);
          }
          else {
            *vp = JSVAL_NULL;
          }
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLEELEMENT_ALIGN:
      {
        nsAutoString prop;
        if (NS_OK == a->GetAlign(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLEELEMENT_BGCOLOR:
      {
        nsAutoString prop;
        if (NS_OK == a->GetBgColor(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLEELEMENT_BORDER:
      {
        nsAutoString prop;
        if (NS_OK == a->GetBorder(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLEELEMENT_CELLPADDING:
      {
        nsAutoString prop;
        if (NS_OK == a->GetCellPadding(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLEELEMENT_CELLSPACING:
      {
        nsAutoString prop;
        if (NS_OK == a->GetCellSpacing(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLEELEMENT_FRAME:
      {
        nsAutoString prop;
        if (NS_OK == a->GetFrame(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLEELEMENT_RULES:
      {
        nsAutoString prop;
        if (NS_OK == a->GetRules(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLEELEMENT_SUMMARY:
      {
        nsAutoString prop;
        if (NS_OK == a->GetSummary(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLEELEMENT_WIDTH:
      {
        nsAutoString prop;
        if (NS_OK == a->GetWidth(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      default:
      {
        nsIJSScriptObject *object;
        if (NS_OK == a->QueryInterface(kIJSScriptObjectIID, (void**)&object)) {
          PRBool rval;
          rval =  object->GetProperty(cx, id, vp);
          NS_RELEASE(object);
          return rval;
        }
      }
    }
  }
  else {
    nsIJSScriptObject *object;
    if (NS_OK == a->QueryInterface(kIJSScriptObjectIID, (void**)&object)) {
      PRBool rval;
      rval =  object->GetProperty(cx, id, vp);
      NS_RELEASE(object);
      return rval;
    }
  }

  return PR_TRUE;
}

/***********************************************************************/
//
// HTMLTableElement Properties Setter
//
PR_STATIC_CALLBACK(JSBool)
SetHTMLTableElementProperty(JSContext *cx, JSObject *obj, jsval id, jsval *vp)
{
  nsIDOMHTMLTableElement *a = (nsIDOMHTMLTableElement*)JS_GetPrivate(cx, obj);

  // If there's no private data, this must be the prototype, so ignore
  if (nsnull == a) {
    return JS_TRUE;
  }

  if (JSVAL_IS_INT(id)) {
    switch(JSVAL_TO_INT(id)) {
      case HTMLTABLEELEMENT_CAPTION:
      {
        nsIDOMHTMLTableCaptionElement* prop;
        if (JSVAL_IS_NULL(*vp)) {
          prop = nsnull;
        }
        else if (JSVAL_IS_OBJECT(*vp)) {
          JSObject *jsobj = JSVAL_TO_OBJECT(*vp); 
          nsISupports *supports = (nsISupports *)JS_GetPrivate(cx, jsobj);
          if (NS_OK != supports->QueryInterface(kIHTMLTableCaptionElementIID, (void **)&prop)) {
            JS_ReportError(cx, "Parameter must be of type HTMLTableCaptionElement");
            return JS_FALSE;
          }
        }
        else {
          JS_ReportError(cx, "Parameter must be an object");
          return JS_FALSE;
        }
      
        a->SetCaption(prop);
        if (prop) NS_RELEASE(prop);
        break;
      }
      case HTMLTABLEELEMENT_THEAD:
      {
        nsIDOMHTMLTableSectionElement* prop;
        if (JSVAL_IS_NULL(*vp)) {
          prop = nsnull;
        }
        else if (JSVAL_IS_OBJECT(*vp)) {
          JSObject *jsobj = JSVAL_TO_OBJECT(*vp); 
          nsISupports *supports = (nsISupports *)JS_GetPrivate(cx, jsobj);
          if (NS_OK != supports->QueryInterface(kIHTMLTableSectionElementIID, (void **)&prop)) {
            JS_ReportError(cx, "Parameter must be of type HTMLTableSectionElement");
            return JS_FALSE;
          }
        }
        else {
          JS_ReportError(cx, "Parameter must be an object");
          return JS_FALSE;
        }
      
        a->SetTHead(prop);
        if (prop) NS_RELEASE(prop);
        break;
      }
      case HTMLTABLEELEMENT_TFOOT:
      {
        nsIDOMHTMLTableSectionElement* prop;
        if (JSVAL_IS_NULL(*vp)) {
          prop = nsnull;
        }
        else if (JSVAL_IS_OBJECT(*vp)) {
          JSObject *jsobj = JSVAL_TO_OBJECT(*vp); 
          nsISupports *supports = (nsISupports *)JS_GetPrivate(cx, jsobj);
          if (NS_OK != supports->QueryInterface(kIHTMLTableSectionElementIID, (void **)&prop)) {
            JS_ReportError(cx, "Parameter must be of type HTMLTableSectionElement");
            return JS_FALSE;
          }
        }
        else {
          JS_ReportError(cx, "Parameter must be an object");
          return JS_FALSE;
        }
      
        a->SetTFoot(prop);
        if (prop) NS_RELEASE(prop);
        break;
      }
      case HTMLTABLEELEMENT_ROWS:
      {
        nsIDOMHTMLCollection* prop;
        if (JSVAL_IS_NULL(*vp)) {
          prop = nsnull;
        }
        else if (JSVAL_IS_OBJECT(*vp)) {
          JSObject *jsobj = JSVAL_TO_OBJECT(*vp); 
          nsISupports *supports = (nsISupports *)JS_GetPrivate(cx, jsobj);
          if (NS_OK != supports->QueryInterface(kIHTMLCollectionIID, (void **)&prop)) {
            JS_ReportError(cx, "Parameter must be of type HTMLCollection");
            return JS_FALSE;
          }
        }
        else {
          JS_ReportError(cx, "Parameter must be an object");
          return JS_FALSE;
        }
      
        a->SetRows(prop);
        if (prop) NS_RELEASE(prop);
        break;
      }
      case HTMLTABLEELEMENT_TBODIES:
      {
        nsIDOMHTMLCollection* prop;
        if (JSVAL_IS_NULL(*vp)) {
          prop = nsnull;
        }
        else if (JSVAL_IS_OBJECT(*vp)) {
          JSObject *jsobj = JSVAL_TO_OBJECT(*vp); 
          nsISupports *supports = (nsISupports *)JS_GetPrivate(cx, jsobj);
          if (NS_OK != supports->QueryInterface(kIHTMLCollectionIID, (void **)&prop)) {
            JS_ReportError(cx, "Parameter must be of type HTMLCollection");
            return JS_FALSE;
          }
        }
        else {
          JS_ReportError(cx, "Parameter must be an object");
          return JS_FALSE;
        }
      
        a->SetTBodies(prop);
        if (prop) NS_RELEASE(prop);
        break;
      }
      case HTMLTABLEELEMENT_ALIGN:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetAlign(prop);
        
        break;
      }
      case HTMLTABLEELEMENT_BGCOLOR:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetBgColor(prop);
        
        break;
      }
      case HTMLTABLEELEMENT_BORDER:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetBorder(prop);
        
        break;
      }
      case HTMLTABLEELEMENT_CELLPADDING:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetCellPadding(prop);
        
        break;
      }
      case HTMLTABLEELEMENT_CELLSPACING:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetCellSpacing(prop);
        
        break;
      }
      case HTMLTABLEELEMENT_FRAME:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetFrame(prop);
        
        break;
      }
      case HTMLTABLEELEMENT_RULES:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetRules(prop);
        
        break;
      }
      case HTMLTABLEELEMENT_SUMMARY:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetSummary(prop);
        
        break;
      }
      case HTMLTABLEELEMENT_WIDTH:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetWidth(prop);
        
        break;
      }
      default:
      {
        nsIJSScriptObject *object;
        if (NS_OK == a->QueryInterface(kIJSScriptObjectIID, (void**)&object)) {
          PRBool rval;
          rval =  object->SetProperty(cx, id, vp);
          NS_RELEASE(object);
          return rval;
        }
      }
    }
  }
  else {
    nsIJSScriptObject *object;
    if (NS_OK == a->QueryInterface(kIJSScriptObjectIID, (void**)&object)) {
      PRBool rval;
      rval =  object->SetProperty(cx, id, vp);
      NS_RELEASE(object);
      return rval;
    }
  }

  return PR_TRUE;
}


//
// HTMLTableElement finalizer
//
PR_STATIC_CALLBACK(void)
FinalizeHTMLTableElement(JSContext *cx, JSObject *obj)
{
  nsIDOMHTMLTableElement *a = (nsIDOMHTMLTableElement*)JS_GetPrivate(cx, obj);
  
  if (nsnull != a) {
    // get the js object
    nsIScriptObjectOwner *owner = nsnull;
    if (NS_OK == a->QueryInterface(kIScriptObjectOwnerIID, (void**)&owner)) {
      owner->ResetScriptObject();
      NS_RELEASE(owner);
    }

    NS_RELEASE(a);
  }
}


//
// HTMLTableElement enumerate
//
PR_STATIC_CALLBACK(JSBool)
EnumerateHTMLTableElement(JSContext *cx, JSObject *obj)
{
  nsIDOMHTMLTableElement *a = (nsIDOMHTMLTableElement*)JS_GetPrivate(cx, obj);
  
  if (nsnull != a) {
    // get the js object
    nsIJSScriptObject *object;
    if (NS_OK == a->QueryInterface(kIJSScriptObjectIID, (void**)&object)) {
      object->EnumerateProperty(cx);
      NS_RELEASE(object);
    }
  }
  return JS_TRUE;
}


//
// HTMLTableElement resolve
//
PR_STATIC_CALLBACK(JSBool)
ResolveHTMLTableElement(JSContext *cx, JSObject *obj, jsval id)
{
  nsIDOMHTMLTableElement *a = (nsIDOMHTMLTableElement*)JS_GetPrivate(cx, obj);
  
  if (nsnull != a) {
    // get the js object
    nsIJSScriptObject *object;
    if (NS_OK == a->QueryInterface(kIJSScriptObjectIID, (void**)&object)) {
      object->Resolve(cx, id);
      NS_RELEASE(object);
    }
  }
  return JS_TRUE;
}


//
// Native method CreateTHead
//
PR_STATIC_CALLBACK(JSBool)
HTMLTableElementCreateTHead(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
  nsIDOMHTMLTableElement *nativeThis = (nsIDOMHTMLTableElement*)JS_GetPrivate(cx, obj);
  JSBool rBool = JS_FALSE;
  nsIDOMHTMLElement* nativeRet;

  *rval = JSVAL_NULL;

  // If there's no private data, this must be the prototype, so ignore
  if (nsnull == nativeThis) {
    return JS_TRUE;
  }

  if (argc >= 0) {

    if (NS_OK != nativeThis->CreateTHead(&nativeRet)) {
      return JS_FALSE;
    }

    if (nativeRet != nsnull) {
      nsIScriptObjectOwner *owner = nsnull;
      if (NS_OK == nativeRet->QueryInterface(kIScriptObjectOwnerIID, (void**)&owner)) {
        JSObject *object = nsnull;
        nsIScriptContext *script_cx = (nsIScriptContext *)JS_GetContextPrivate(cx);
        if (NS_OK == owner->GetScriptObject(script_cx, (void**)&object)) {
          // set the return value
          *rval = OBJECT_TO_JSVAL(object);
        }
        NS_RELEASE(owner);
      }
      NS_RELEASE(nativeRet);
    }
    else {
      *rval = JSVAL_NULL;
    }
  }
  else {
    JS_ReportError(cx, "Function createTHead requires 0 parameters");
    return JS_FALSE;
  }

  return JS_TRUE;
}


//
// Native method DeleteTHead
//
PR_STATIC_CALLBACK(JSBool)
HTMLTableElementDeleteTHead(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
  nsIDOMHTMLTableElement *nativeThis = (nsIDOMHTMLTableElement*)JS_GetPrivate(cx, obj);
  JSBool rBool = JS_FALSE;

  *rval = JSVAL_NULL;

  // If there's no private data, this must be the prototype, so ignore
  if (nsnull == nativeThis) {
    return JS_TRUE;
  }

  if (argc >= 0) {

    if (NS_OK != nativeThis->DeleteTHead()) {
      return JS_FALSE;
    }

    *rval = JSVAL_VOID;
  }
  else {
    JS_ReportError(cx, "Function deleteTHead requires 0 parameters");
    return JS_FALSE;
  }

  return JS_TRUE;
}


//
// Native method CreateTFoot
//
PR_STATIC_CALLBACK(JSBool)
HTMLTableElementCreateTFoot(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
  nsIDOMHTMLTableElement *nativeThis = (nsIDOMHTMLTableElement*)JS_GetPrivate(cx, obj);
  JSBool rBool = JS_FALSE;
  nsIDOMHTMLElement* nativeRet;

  *rval = JSVAL_NULL;

  // If there's no private data, this must be the prototype, so ignore
  if (nsnull == nativeThis) {
    return JS_TRUE;
  }

  if (argc >= 0) {

    if (NS_OK != nativeThis->CreateTFoot(&nativeRet)) {
      return JS_FALSE;
    }

    if (nativeRet != nsnull) {
      nsIScriptObjectOwner *owner = nsnull;
      if (NS_OK == nativeRet->QueryInterface(kIScriptObjectOwnerIID, (void**)&owner)) {
        JSObject *object = nsnull;
        nsIScriptContext *script_cx = (nsIScriptContext *)JS_GetContextPrivate(cx);
        if (NS_OK == owner->GetScriptObject(script_cx, (void**)&object)) {
          // set the return value
          *rval = OBJECT_TO_JSVAL(object);
        }
        NS_RELEASE(owner);
      }
      NS_RELEASE(nativeRet);
    }
    else {
      *rval = JSVAL_NULL;
    }
  }
  else {
    JS_ReportError(cx, "Function createTFoot requires 0 parameters");
    return JS_FALSE;
  }

  return JS_TRUE;
}


//
// Native method DeleteTFoot
//
PR_STATIC_CALLBACK(JSBool)
HTMLTableElementDeleteTFoot(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
  nsIDOMHTMLTableElement *nativeThis = (nsIDOMHTMLTableElement*)JS_GetPrivate(cx, obj);
  JSBool rBool = JS_FALSE;

  *rval = JSVAL_NULL;

  // If there's no private data, this must be the prototype, so ignore
  if (nsnull == nativeThis) {
    return JS_TRUE;
  }

  if (argc >= 0) {

    if (NS_OK != nativeThis->DeleteTFoot()) {
      return JS_FALSE;
    }

    *rval = JSVAL_VOID;
  }
  else {
    JS_ReportError(cx, "Function deleteTFoot requires 0 parameters");
    return JS_FALSE;
  }

  return JS_TRUE;
}


//
// Native method CreateCaption
//
PR_STATIC_CALLBACK(JSBool)
HTMLTableElementCreateCaption(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
  nsIDOMHTMLTableElement *nativeThis = (nsIDOMHTMLTableElement*)JS_GetPrivate(cx, obj);
  JSBool rBool = JS_FALSE;
  nsIDOMHTMLElement* nativeRet;

  *rval = JSVAL_NULL;

  // If there's no private data, this must be the prototype, so ignore
  if (nsnull == nativeThis) {
    return JS_TRUE;
  }

  if (argc >= 0) {

    if (NS_OK != nativeThis->CreateCaption(&nativeRet)) {
      return JS_FALSE;
    }

    if (nativeRet != nsnull) {
      nsIScriptObjectOwner *owner = nsnull;
      if (NS_OK == nativeRet->QueryInterface(kIScriptObjectOwnerIID, (void**)&owner)) {
        JSObject *object = nsnull;
        nsIScriptContext *script_cx = (nsIScriptContext *)JS_GetContextPrivate(cx);
        if (NS_OK == owner->GetScriptObject(script_cx, (void**)&object)) {
          // set the return value
          *rval = OBJECT_TO_JSVAL(object);
        }
        NS_RELEASE(owner);
      }
      NS_RELEASE(nativeRet);
    }
    else {
      *rval = JSVAL_NULL;
    }
  }
  else {
    JS_ReportError(cx, "Function createCaption requires 0 parameters");
    return JS_FALSE;
  }

  return JS_TRUE;
}


//
// Native method DeleteCaption
//
PR_STATIC_CALLBACK(JSBool)
HTMLTableElementDeleteCaption(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
  nsIDOMHTMLTableElement *nativeThis = (nsIDOMHTMLTableElement*)JS_GetPrivate(cx, obj);
  JSBool rBool = JS_FALSE;

  *rval = JSVAL_NULL;

  // If there's no private data, this must be the prototype, so ignore
  if (nsnull == nativeThis) {
    return JS_TRUE;
  }

  if (argc >= 0) {

    if (NS_OK != nativeThis->DeleteCaption()) {
      return JS_FALSE;
    }

    *rval = JSVAL_VOID;
  }
  else {
    JS_ReportError(cx, "Function deleteCaption requires 0 parameters");
    return JS_FALSE;
  }

  return JS_TRUE;
}


//
// Native method InsertRow
//
PR_STATIC_CALLBACK(JSBool)
HTMLTableElementInsertRow(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
  nsIDOMHTMLTableElement *nativeThis = (nsIDOMHTMLTableElement*)JS_GetPrivate(cx, obj);
  JSBool rBool = JS_FALSE;
  nsIDOMHTMLElement* nativeRet;
  PRInt32 b0;

  *rval = JSVAL_NULL;

  // If there's no private data, this must be the prototype, so ignore
  if (nsnull == nativeThis) {
    return JS_TRUE;
  }

  if (argc >= 1) {

    if (!JS_ValueToInt32(cx, argv[0], (int32 *)&b0)) {
      JS_ReportError(cx, "Parameter must be a number");
      return JS_FALSE;
    }

    if (NS_OK != nativeThis->InsertRow(b0, &nativeRet)) {
      return JS_FALSE;
    }

    if (nativeRet != nsnull) {
      nsIScriptObjectOwner *owner = nsnull;
      if (NS_OK == nativeRet->QueryInterface(kIScriptObjectOwnerIID, (void**)&owner)) {
        JSObject *object = nsnull;
        nsIScriptContext *script_cx = (nsIScriptContext *)JS_GetContextPrivate(cx);
        if (NS_OK == owner->GetScriptObject(script_cx, (void**)&object)) {
          // set the return value
          *rval = OBJECT_TO_JSVAL(object);
        }
        NS_RELEASE(owner);
      }
      NS_RELEASE(nativeRet);
    }
    else {
      *rval = JSVAL_NULL;
    }
  }
  else {
    JS_ReportError(cx, "Function insertRow requires 1 parameters");
    return JS_FALSE;
  }

  return JS_TRUE;
}


//
// Native method DeleteRow
//
PR_STATIC_CALLBACK(JSBool)
HTMLTableElementDeleteRow(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
  nsIDOMHTMLTableElement *nativeThis = (nsIDOMHTMLTableElement*)JS_GetPrivate(cx, obj);
  JSBool rBool = JS_FALSE;
  PRInt32 b0;

  *rval = JSVAL_NULL;

  // If there's no private data, this must be the prototype, so ignore
  if (nsnull == nativeThis) {
    return JS_TRUE;
  }

  if (argc >= 1) {

    if (!JS_ValueToInt32(cx, argv[0], (int32 *)&b0)) {
      JS_ReportError(cx, "Parameter must be a number");
      return JS_FALSE;
    }

    if (NS_OK != nativeThis->DeleteRow(b0)) {
      return JS_FALSE;
    }

    *rval = JSVAL_VOID;
  }
  else {
    JS_ReportError(cx, "Function deleteRow requires 1 parameters");
    return JS_FALSE;
  }

  return JS_TRUE;
}


/***********************************************************************/
//
// class for HTMLTableElement
//
JSClass HTMLTableElementClass = {
  "HTMLTableElement", 
  JSCLASS_HAS_PRIVATE,
  JS_PropertyStub,
  JS_PropertyStub,
  GetHTMLTableElementProperty,
  SetHTMLTableElementProperty,
  EnumerateHTMLTableElement,
  ResolveHTMLTableElement,
  JS_ConvertStub,
  FinalizeHTMLTableElement
};


//
// HTMLTableElement class properties
//
static JSPropertySpec HTMLTableElementProperties[] =
{
  {"caption",    HTMLTABLEELEMENT_CAPTION,    JSPROP_ENUMERATE},
  {"tHead",    HTMLTABLEELEMENT_THEAD,    JSPROP_ENUMERATE},
  {"tFoot",    HTMLTABLEELEMENT_TFOOT,    JSPROP_ENUMERATE},
  {"rows",    HTMLTABLEELEMENT_ROWS,    JSPROP_ENUMERATE},
  {"tBodies",    HTMLTABLEELEMENT_TBODIES,    JSPROP_ENUMERATE},
  {"align",    HTMLTABLEELEMENT_ALIGN,    JSPROP_ENUMERATE},
  {"bgColor",    HTMLTABLEELEMENT_BGCOLOR,    JSPROP_ENUMERATE},
  {"border",    HTMLTABLEELEMENT_BORDER,    JSPROP_ENUMERATE},
  {"cellPadding",    HTMLTABLEELEMENT_CELLPADDING,    JSPROP_ENUMERATE},
  {"cellSpacing",    HTMLTABLEELEMENT_CELLSPACING,    JSPROP_ENUMERATE},
  {"frame",    HTMLTABLEELEMENT_FRAME,    JSPROP_ENUMERATE},
  {"rules",    HTMLTABLEELEMENT_RULES,    JSPROP_ENUMERATE},
  {"summary",    HTMLTABLEELEMENT_SUMMARY,    JSPROP_ENUMERATE},
  {"width",    HTMLTABLEELEMENT_WIDTH,    JSPROP_ENUMERATE},
  {0}
};


//
// HTMLTableElement class methods
//
static JSFunctionSpec HTMLTableElementMethods[] = 
{
  {"createTHead",          HTMLTableElementCreateTHead,     0},
  {"deleteTHead",          HTMLTableElementDeleteTHead,     0},
  {"createTFoot",          HTMLTableElementCreateTFoot,     0},
  {"deleteTFoot",          HTMLTableElementDeleteTFoot,     0},
  {"createCaption",          HTMLTableElementCreateCaption,     0},
  {"deleteCaption",          HTMLTableElementDeleteCaption,     0},
  {"insertRow",          HTMLTableElementInsertRow,     1},
  {"deleteRow",          HTMLTableElementDeleteRow,     1},
  {0}
};


//
// HTMLTableElement constructor
//
PR_STATIC_CALLBACK(JSBool)
HTMLTableElement(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
  return JS_TRUE;
}


//
// HTMLTableElement class initialization
//
nsresult NS_InitHTMLTableElementClass(nsIScriptContext *aContext, void **aPrototype)
{
  JSContext *jscontext = (JSContext *)aContext->GetNativeContext();
  JSObject *proto = nsnull;
  JSObject *constructor = nsnull;
  JSObject *parent_proto = nsnull;
  JSObject *global = JS_GetGlobalObject(jscontext);
  jsval vp;

  if ((PR_TRUE != JS_LookupProperty(jscontext, global, "HTMLTableElement", &vp)) ||
      !JSVAL_IS_OBJECT(vp) ||
      ((constructor = JSVAL_TO_OBJECT(vp)) == nsnull) ||
      (PR_TRUE != JS_LookupProperty(jscontext, JSVAL_TO_OBJECT(vp), "prototype", &vp)) || 
      !JSVAL_IS_OBJECT(vp)) {

    if (NS_OK != NS_InitHTMLElementClass(aContext, (void **)&parent_proto)) {
      return NS_ERROR_FAILURE;
    }
    proto = JS_InitClass(jscontext,     // context
                         global,        // global object
                         parent_proto,  // parent proto 
                         &HTMLTableElementClass,      // JSClass
                         HTMLTableElement,            // JSNative ctor
                         0,             // ctor args
                         HTMLTableElementProperties,  // proto props
                         HTMLTableElementMethods,     // proto funcs
                         nsnull,        // ctor props (static)
                         nsnull);       // ctor funcs (static)
    if (nsnull == proto) {
      return NS_ERROR_FAILURE;
    }

  }
  else if ((nsnull != constructor) && JSVAL_IS_OBJECT(vp)) {
    proto = JSVAL_TO_OBJECT(vp);
  }
  else {
    return NS_ERROR_FAILURE;
  }

  if (aPrototype) {
    *aPrototype = proto;
  }
  return NS_OK;
}


//
// Method for creating a new HTMLTableElement JavaScript object
//
extern "C" NS_DOM nsresult NS_NewScriptHTMLTableElement(nsIScriptContext *aContext, nsIDOMHTMLTableElement *aSupports, nsISupports *aParent, void **aReturn)
{
  NS_PRECONDITION(nsnull != aContext && nsnull != aSupports && nsnull != aReturn, "null argument to NS_NewScriptHTMLTableElement");
  JSObject *proto;
  JSObject *parent;
  nsIScriptObjectOwner *owner;
  JSContext *jscontext = (JSContext *)aContext->GetNativeContext();

  if (nsnull == aParent) {
    parent = nsnull;
  }
  else if (NS_OK == aParent->QueryInterface(kIScriptObjectOwnerIID, (void**)&owner)) {
    if (NS_OK != owner->GetScriptObject(aContext, (void **)&parent)) {
      NS_RELEASE(owner);
      return NS_ERROR_FAILURE;
    }
    NS_RELEASE(owner);
  }
  else {
    return NS_ERROR_FAILURE;
  }

  if (NS_OK != NS_InitHTMLTableElementClass(aContext, (void **)&proto)) {
    return NS_ERROR_FAILURE;
  }

  // create a js object for this class
  *aReturn = JS_NewObject(jscontext, &HTMLTableElementClass, proto, parent);
  if (nsnull != *aReturn) {
    // connect the native object to the js object
    JS_SetPrivate(jscontext, (JSObject *)*aReturn, aSupports);
    NS_ADDREF(aSupports);
  }
  else {
    return NS_ERROR_FAILURE; 
  }

  return NS_OK;
}

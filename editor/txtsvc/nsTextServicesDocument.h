/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef nsTextServicesDocument_h__
#define nsTextServicesDocument_h__

#include "nsCOMPtr.h"
#include "nsCycleCollectionParticipant.h"
#include "nsIEditActionListener.h"
#include "nsISupportsImpl.h"
#include "nsITextServicesDocument.h"
#include "nsIWeakReferenceUtils.h"
#include "nsTArray.h"
#include "nscore.h"

class OffsetEntry;
class nsIAtom;
class nsIContent;
class nsIContentIterator;
class nsIDOMCharacterData;
class nsIDOMDocument;
class nsIDOMNode;
class nsIDOMRange;
class nsIEditor;
class nsISelection;
class nsISelectionController;
class nsITextServicesFilter;
class nsString;

/** implementation of a text services object.
 *
 */
class nsTextServicesDocument MOZ_FINAL : public nsITextServicesDocument,
                                         public nsIEditActionListener
{
private:
  static nsIAtom *sAAtom;
  static nsIAtom *sAddressAtom;
  static nsIAtom *sBigAtom;
  static nsIAtom *sBAtom;
  static nsIAtom *sCiteAtom;
  static nsIAtom *sCodeAtom;
  static nsIAtom *sDfnAtom;
  static nsIAtom *sEmAtom;
  static nsIAtom *sFontAtom;
  static nsIAtom *sIAtom;
  static nsIAtom *sKbdAtom;
  static nsIAtom *sKeygenAtom;
  static nsIAtom *sNobrAtom;
  static nsIAtom *sSAtom;
  static nsIAtom *sSampAtom;
  static nsIAtom *sSmallAtom;
  static nsIAtom *sSpacerAtom;
  static nsIAtom *sSpanAtom;      
  static nsIAtom *sStrikeAtom;
  static nsIAtom *sStrongAtom;
  static nsIAtom *sSubAtom;
  static nsIAtom *sSupAtom;
  static nsIAtom *sTtAtom;
  static nsIAtom *sUAtom;
  static nsIAtom *sVarAtom;
  static nsIAtom *sWbrAtom;

  typedef enum { eIsDone=0,        // No iterator (I), or iterator doesn't point to anything valid.
                 eValid,           // I points to first text node (TN) in current block (CB).
                 ePrev,            // No TN in CB, I points to first TN in prev block.
                 eNext             // No TN in CB, I points to first TN in next block.
  } TSDIteratorStatus;

  nsCOMPtr<nsIDOMDocument>        mDOMDocument;
  nsCOMPtr<nsISelectionController>mSelCon;
  nsWeakPtr                       mEditor;  // avoid a cycle with the spell checker and editor
  nsCOMPtr<nsIContentIterator>    mIterator;
  TSDIteratorStatus               mIteratorStatus;
  nsCOMPtr<nsIContent>            mPrevTextBlock;
  nsCOMPtr<nsIContent>            mNextTextBlock;
  nsTArray<OffsetEntry*>          mOffsetTable;

  int32_t                         mSelStartIndex;
  int32_t                         mSelStartOffset;
  int32_t                         mSelEndIndex;
  int32_t                         mSelEndOffset;

  nsRefPtr<nsRange>               mExtent;

  nsCOMPtr<nsITextServicesFilter> mTxtSvcFilter;

protected:
  /** The default destructor.
   */
  virtual ~nsTextServicesDocument();

public:

  /** The default constructor.
   */
  nsTextServicesDocument();

  /** To be called at module init
   */
  static void RegisterAtoms();

  /* Macro for AddRef(), Release(), and QueryInterface() */
  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_CYCLE_COLLECTION_CLASS_AMBIGUOUS(nsTextServicesDocument, nsITextServicesDocument)

  /* nsITextServicesDocument method implementations. */
  NS_IMETHOD InitWithEditor(nsIEditor *aEditor) MOZ_OVERRIDE;
  NS_IMETHOD GetDocument(nsIDOMDocument **aDoc) MOZ_OVERRIDE;
  NS_IMETHOD SetExtent(nsIDOMRange* aDOMRange) MOZ_OVERRIDE;
  NS_IMETHOD ExpandRangeToWordBoundaries(nsIDOMRange *aRange) MOZ_OVERRIDE;
  NS_IMETHOD SetFilter(nsITextServicesFilter *aFilter) MOZ_OVERRIDE;
  NS_IMETHOD GetCurrentTextBlock(nsString *aStr) MOZ_OVERRIDE;
  NS_IMETHOD FirstBlock() MOZ_OVERRIDE;
  NS_IMETHOD LastSelectedBlock(TSDBlockSelectionStatus *aSelStatus, int32_t *aSelOffset, int32_t *aSelLength) MOZ_OVERRIDE;
  NS_IMETHOD PrevBlock() MOZ_OVERRIDE;
  NS_IMETHOD NextBlock() MOZ_OVERRIDE;
  NS_IMETHOD IsDone(bool *aIsDone) MOZ_OVERRIDE;
  NS_IMETHOD SetSelection(int32_t aOffset, int32_t aLength) MOZ_OVERRIDE;
  NS_IMETHOD ScrollSelectionIntoView() MOZ_OVERRIDE;
  NS_IMETHOD DeleteSelection() MOZ_OVERRIDE;
  NS_IMETHOD InsertText(const nsString *aText) MOZ_OVERRIDE;

  /* nsIEditActionListener method implementations. */
  NS_IMETHOD WillInsertNode(nsIDOMNode *aNode,
                            nsIDOMNode *aParent,
                            int32_t      aPosition) MOZ_OVERRIDE;
  NS_IMETHOD DidInsertNode(nsIDOMNode *aNode,
                           nsIDOMNode *aParent,
                           int32_t     aPosition,
                           nsresult    aResult) MOZ_OVERRIDE;

  NS_IMETHOD WillDeleteNode(nsIDOMNode *aChild) MOZ_OVERRIDE;
  NS_IMETHOD DidDeleteNode(nsIDOMNode *aChild, nsresult aResult) MOZ_OVERRIDE;

  NS_IMETHOD WillSplitNode(nsIDOMNode * aExistingRightNode,
                           int32_t      aOffset) MOZ_OVERRIDE;
  NS_IMETHOD DidSplitNode(nsIDOMNode *aExistingRightNode,
                          int32_t     aOffset,
                          nsIDOMNode *aNewLeftNode,
                          nsresult    aResult) MOZ_OVERRIDE;

  NS_IMETHOD WillJoinNodes(nsIDOMNode  *aLeftNode,
                           nsIDOMNode  *aRightNode,
                           nsIDOMNode  *aParent) MOZ_OVERRIDE;
  NS_IMETHOD DidJoinNodes(nsIDOMNode  *aLeftNode,
                          nsIDOMNode  *aRightNode,
                          nsIDOMNode  *aParent,
                          nsresult     aResult) MOZ_OVERRIDE;
  // these listen methods are unused:
  NS_IMETHOD WillCreateNode(const nsAString& aTag, nsIDOMNode *aParent, int32_t aPosition) MOZ_OVERRIDE;
  NS_IMETHOD DidCreateNode(const nsAString& aTag, nsIDOMNode *aNode, nsIDOMNode *aParent, int32_t aPosition, nsresult aResult) MOZ_OVERRIDE;
  NS_IMETHOD WillInsertText(nsIDOMCharacterData *aTextNode, int32_t aOffset, const nsAString &aString) MOZ_OVERRIDE;
  NS_IMETHOD DidInsertText(nsIDOMCharacterData *aTextNode, int32_t aOffset, const nsAString &aString, nsresult aResult) MOZ_OVERRIDE;
  NS_IMETHOD WillDeleteText(nsIDOMCharacterData *aTextNode, int32_t aOffset, int32_t aLength) MOZ_OVERRIDE;
  NS_IMETHOD DidDeleteText(nsIDOMCharacterData *aTextNode, int32_t aOffset, int32_t aLength, nsresult aResult) MOZ_OVERRIDE;
  NS_IMETHOD WillDeleteSelection(nsISelection *aSelection) MOZ_OVERRIDE;
  NS_IMETHOD DidDeleteSelection(nsISelection *aSelection) MOZ_OVERRIDE;

  /* Helper functions */
  static nsresult GetRangeEndPoints(nsRange* aRange, nsIDOMNode** aParent1,
                                    int32_t* aOffset1, nsIDOMNode** aParent2,
                                    int32_t* aOffset2);
  static nsresult CreateRange(nsIDOMNode* aStartParent, int32_t aStartOffset,
                              nsIDOMNode* aEndParent, int32_t aEndOffset,
                              nsRange** aRange);

private:
  /* nsTextServicesDocument private methods. */

  nsresult CreateContentIterator(nsRange* aRange,
                                 nsIContentIterator** aIterator);

  nsresult GetDocumentContentRootNode(nsIDOMNode **aNode);
  nsresult CreateDocumentContentRange(nsRange** aRange);
  nsresult CreateDocumentContentRootToNodeOffsetRange(nsIDOMNode* aParent,
                                                      int32_t aOffset,
                                                      bool aToStart,
                                                      nsRange** aRange);
  nsresult CreateDocumentContentIterator(nsIContentIterator **aIterator);

  nsresult AdjustContentIterator();

  static nsresult FirstTextNode(nsIContentIterator *aIterator, TSDIteratorStatus *IteratorStatus);
  static nsresult LastTextNode(nsIContentIterator *aIterator, TSDIteratorStatus *IteratorStatus);

  static nsresult FirstTextNodeInCurrentBlock(nsIContentIterator *aIterator);
  static nsresult FirstTextNodeInPrevBlock(nsIContentIterator *aIterator);
  static nsresult FirstTextNodeInNextBlock(nsIContentIterator *aIterator);

  nsresult GetFirstTextNodeInPrevBlock(nsIContent **aContent);
  nsresult GetFirstTextNodeInNextBlock(nsIContent **aContent);

  static bool IsBlockNode(nsIContent *aContent);
  static bool IsTextNode(nsIContent *aContent);
  static bool IsTextNode(nsIDOMNode *aNode);

  static bool DidSkip(nsIContentIterator* aFilteredIter);
  static void   ClearDidSkip(nsIContentIterator* aFilteredIter);

  static bool HasSameBlockNodeParent(nsIContent *aContent1, nsIContent *aContent2);

  nsresult SetSelectionInternal(int32_t aOffset, int32_t aLength, bool aDoUpdate);
  nsresult GetSelection(TSDBlockSelectionStatus *aSelStatus, int32_t *aSelOffset, int32_t *aSelLength);
  nsresult GetCollapsedSelection(TSDBlockSelectionStatus *aSelStatus, int32_t *aSelOffset, int32_t *aSelLength);
  nsresult GetUncollapsedSelection(TSDBlockSelectionStatus *aSelStatus, int32_t *aSelOffset, int32_t *aSelLength);

  bool SelectionIsCollapsed();
  bool SelectionIsValid();

  static nsresult CreateOffsetTable(nsTArray<OffsetEntry*> *aOffsetTable,
                             nsIContentIterator *aIterator,
                             TSDIteratorStatus *aIteratorStatus,
                             nsRange* aIterRange, nsString* aStr);
  static nsresult ClearOffsetTable(nsTArray<OffsetEntry*> *aOffsetTable);

  static nsresult NodeHasOffsetEntry(nsTArray<OffsetEntry*> *aOffsetTable,
                                     nsIDOMNode *aNode,
                                     bool *aHasEntry,
                                     int32_t *aEntryIndex);

  nsresult RemoveInvalidOffsetEntries();
  nsresult SplitOffsetEntry(int32_t aTableIndex, int32_t aOffsetIntoEntry);

  static nsresult FindWordBounds(nsTArray<OffsetEntry*> *offsetTable,
                                 nsString *blockStr,
                                 nsIDOMNode *aNode, int32_t aNodeOffset,
                                 nsIDOMNode **aWordStartNode,
                                 int32_t *aWordStartOffset,
                                 nsIDOMNode **aWordEndNode,
                                 int32_t *aWordEndOffset);
};

#endif // nsTextServicesDocument_h__

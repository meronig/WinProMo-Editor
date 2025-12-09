/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
// SrvrItem.cpp : implementation of the COleTestSrvrItem class
//

#include "stdafx.h"
#include "WinProMo.h"

#include "WinProMoDoc.h"
#include "OleSrvItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COleTestSrvrItem implementation

IMPLEMENT_DYNAMIC(CWinProMoOleSrvItem, COleServerItem)

CWinProMoOleSrvItem::CWinProMoOleSrvItem(CWinProMoDoc* pContainerDoc)
	: COleServerItem(pContainerDoc, TRUE)
{
	// TODO: add one-time construction code here
	//  (eg, adding additional clipboard formats to the item's data source)
}

CWinProMoOleSrvItem::~CWinProMoOleSrvItem()
{
	// TODO: add cleanup code here
}

void CWinProMoOleSrvItem::Serialize(CArchive& ar)
{
	// COleTestSrvrItem::Serialize will be called by the framework if
	//  the item is copied to the clipboard.  This can happen automatically
	//  through the OLE callback OnGetClipboardData.  A good default for
	//  the embedded item is simply to delegate to the document's Serialize
	//  function.  If you support links, then you will want to serialize
	//  just a portion of the document.

	if (!IsLinkedItem())
	{
		CWinProMoDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pDoc->Serialize(ar);
	}
}

BOOL CWinProMoOleSrvItem::OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize)
{
	// Most applications, like this one, only handle drawing the content
	//  aspect of the item.  If you wish to support other aspects, such
	//  as DVASPECT_THUMBNAIL (by overriding OnDrawEx), then this
	//  implementation of OnGetExtent should be modified to handle the
	//  additional aspect(s).

	if (dwDrawAspect != DVASPECT_CONTENT)
		return COleServerItem::OnGetExtent(dwDrawAspect, rSize);

	// COleTestSrvrItem::OnGetExtent is called to get the extent in
	//  HIMETRIC units of the entire item.  The default implementation
	//  here simply returns a hard-coded number of units.

	CWinProMoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: replace this arbitrary size

	CSize logicalSize = pDoc->GetData()->GetVirtualSize();

	CClientDC dc(NULL);

	// use a mapping mode based on logical units
//  (we can't use MM_LOENGLISH because MM_LOENGLISH uses physical inches)
	dc.SetMapMode(MM_ANISOTROPIC);
	dc.SetViewportExt(dc.GetDeviceCaps(LOGPIXELSX), dc.GetDeviceCaps(LOGPIXELSY));
	dc.SetWindowExt(100, -100);
	dc.LPtoHIMETRIC(&logicalSize);
	rSize = logicalSize;

	return TRUE;
}

BOOL CWinProMoOleSrvItem::OnDraw(CDC* pDC, CSize& rSize)
{
	CWinProMoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CProMoEntityContainer* objs = pDoc->GetData();

	CSize docSize = objs->GetVirtualSize();

	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowOrg(0, 0);
	pDC->SetWindowExt(docSize);

	if (objs)
	{
		objs->UnselectAll();
		ASSERT(true);
		int count = 0;
		CDiagramEntity* obj;
		while ((obj = objs->GetAt(count++))) {
			obj->DrawObject(pDC, 1.0);
		}
	}

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// COleTestSrvrItem diagnostics

#ifdef _DEBUG
void CWinProMoOleSrvItem::AssertValid() const
{
	COleServerItem::AssertValid();
}

void CWinProMoOleSrvItem::Dump(CDumpContext& dc) const
{
	COleServerItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////

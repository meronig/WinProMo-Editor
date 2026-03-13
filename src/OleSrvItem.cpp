/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
// SrvrItem.cpp : implementation of the CWinProMoOleSrvItem class
//

#include "stdafx.h"
#include "WinProMo.h"

#include "WinProMoDoc.h"
#include "OleSrvItem.h"
#include "resource.h"
#include "../../WinProMo/src/FileUtils/DibHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CWinProMoOleSrvItem, COleServerItem)
	//{{AFX_MSG_MAP(CWinProMoOleSrvItem)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinProMoOleSrvItem implementation

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
	// CWinProMoOleSrvItem::Serialize will be called by the framework if
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

	CProMoEntityContainer* objs = pDoc->GetData();

	if (objs) {

		CSize logicalSize = objs->GetVirtualSize();

		CClientDC dc(NULL);

		// use a mapping mode based on logical units
		// (we can't use MM_LOENGLISH because MM_LOENGLISH uses physical inches)
		dc.SetMapMode(MM_ANISOTROPIC);
		dc.SetViewportExt(dc.GetDeviceCaps(LOGPIXELSX), dc.GetDeviceCaps(LOGPIXELSY));
		dc.SetWindowExt(100, -100);
		dc.LPtoHIMETRIC(&logicalSize);
		rSize = logicalSize;

		return TRUE;
	}
	return FALSE;
}

BOOL CWinProMoOleSrvItem::OnDraw(CDC* pDC, CSize& rSize)
{
	CWinProMoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CDibHelper dib;

	CProMoEntityContainer* objs = pDoc->GetData();

	if (objs) {

		CSize docSize = objs->GetVirtualSize();

		CProMoRenderer* renderer = pDoc->GetRenderer();

		// this should be an application-level registry setting
		BOOL rasterize = FALSE;

		if (renderer) {
			if (rasterize) {
				CDC memDC;
				memDC.CreateCompatibleDC(NULL);

				renderer->RenderCanvasAsRaster(dib, memDC.GetDeviceCaps(LOGPIXELSX));

				BITMAPINFOHEADER bih = *dib.GetBitmapInfoHeader();
				BITMAPINFO bmi;
				ZeroMemory(&bmi, sizeof(bmi));
				bmi.bmiHeader = bih;

				StretchDIBits(
					*pDC,
					0, 0, docSize.cx, docSize.cy,
					0, 0, dib.GetWidth(), dib.GetHeight(),
					dib.GetBits(),
					&bmi,
					DIB_RGB_COLORS,
					SRCCOPY
				);

			}
			else {
				renderer->RenderCanvasAsMetafile(*pDC, 1.0);
			}
		}

		return TRUE;
	}
	return FALSE;
	
}

/////////////////////////////////////////////////////////////////////////////
// CWinProMoOleSrvItem diagnostics

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


void CWinProMoOleSrvItem::OnDoVerb(LONG iVerb)
{
	// Overridden to force the OLE server to fully open, so to avoid stale metafile
	// Remove if in-place activation is implemented
	if (iVerb == OLEIVERB_PRIMARY || iVerb == OLEIVERB_SHOW) {
		iVerb = OLEIVERB_OPEN;
	}

	COleServerItem::OnDoVerb(iVerb);
}

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
#include "resource.h"
#include "../../WinProMo/src/FileUtils/DibHelper.h"

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
	// TODO: merge this code with diagram export

	CWinProMoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CDibHelper dib;

	CProMoEntityContainer* objs = pDoc->GetData();

	if (objs) {

		CSize docSize = objs->GetVirtualSize();

		pDC->SetMapMode(MM_ANISOTROPIC);
		pDC->SetWindowOrg(0, 0);
		pDC->SetWindowExt(docSize);

		BOOL rasterize = TRUE;

		if (rasterize) {
			CDC memDC;
			memDC.CreateCompatibleDC(NULL);

			const double RASTER_RES = memDC.GetDeviceCaps(LOGPIXELSX);
			const double MAX_DIM = 6000.0;

			unsigned long scaling = RASTER_RES / memDC.GetDeviceCaps(LOGPIXELSX);
			unsigned long hSize = docSize.cx;
			unsigned long vSize = docSize.cy;

			double maxScaleW = MAX_DIM / hSize;
			double maxScaleH = MAX_DIM / vSize;
			double maxScale = min(maxScaleW, maxScaleH);

			if (scaling > maxScale)
				scaling = maxScale;

			dib.Create(docSize.cx * scaling, docSize.cy * scaling, 24);

			HBITMAP hOld = (HBITMAP)memDC.SelectObject(dib.GetBitmap());

			memDC.FillSolidRect(0, 0, docSize.cx * scaling, docSize.cy * scaling, RGB(255, 255, 255));


			if (objs)
			{
				objs->UnselectAll();
				int count = 0;
				CDiagramEntity* obj;
				while ((obj = objs->GetAt(count++))) {
					obj->DrawObject(&memDC, scaling);
				}
			}

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

			memDC.SelectObject(hOld);

		}
		else {
			if (objs)
			{
				objs->UnselectAll();
				int count = 0;
				CDiagramEntity* obj;
				while ((obj = objs->GetAt(count++))) {
					obj->DrawObject(pDC, 1.0);
				}
			}
		}

		return TRUE;
	}
	return FALSE;
	
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

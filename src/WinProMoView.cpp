/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/

#include "stdafx.h"
#include "WinProMoDoc.h"
#include "WinProMoView.h"
#include "GridSizeDialog.h"
#include "CanvasSizeDialog.h"

#include <afxole.h>
#include "WinProMo.h"
#include "../../WinProMo/src/FileUtils/DibHelper.h"
#include "../../WinProMo/src/ProMoEditor/ProMoRenderer.h"
#include "ExportDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWinProMoView

IMPLEMENT_DYNCREATE(CWinProMoView, CView)

BEGIN_MESSAGE_MAP(CWinProMoView, CView)
	//{{AFX_MSG_MAP(CWinProMoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, OnUpdateEditUndo)
	ON_COMMAND(ID_ARRANGE_SNAPTOGRID, OnButtonSnap)
	ON_UPDATE_COMMAND_UI(ID_ARRANGE_SNAPTOGRID, OnUpdateButtonSnap)
	// Standard printing commands
	ON_COMMAND(ID_CANCEL_EDIT_SRVR, OnCancelEditSrvr)
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CWinProMoView::OnFilePrintPreview)
	ON_COMMAND(ID_EDIT_DELETE, CWinProMoView::OnEditDelete)
	ON_UPDATE_COMMAND_UI(ID_EDIT_DELETE, CWinProMoView::OnUpdateEditDelete)
	ON_COMMAND(ID_ARRANGE_GROUP, CWinProMoView::OnArrangeGroup)
	ON_UPDATE_COMMAND_UI(ID_ARRANGE_GROUP, CWinProMoView::OnUpdateArrangeGroup)
	ON_COMMAND(ID_ARRANGE_UNGROUP, CWinProMoView::OnArrangeUngroup)
	ON_UPDATE_COMMAND_UI(ID_ARRANGE_UNGROUP, CWinProMoView::OnUpdateArrangeUngroup)
	ON_COMMAND(ID_VIEW_GRID, CWinProMoView::OnViewGrid)
	ON_UPDATE_COMMAND_UI(ID_VIEW_GRID, CWinProMoView::OnUpdateViewGrid)
	ON_COMMAND(ID_ALIGN_BOTTOM, CWinProMoView::OnAlignBottom)
	ON_UPDATE_COMMAND_UI(ID_ALIGN_BOTTOM, CWinProMoView::OnUpdateAlignBottom)
	ON_UPDATE_COMMAND_UI(ID_ALIGN_CENTER, CWinProMoView::OnUpdateAlignCenter)
	ON_COMMAND(ID_ALIGN_CENTER, CWinProMoView::OnAlignCenter)
	ON_COMMAND(ID_ALIGN_LEFT, CWinProMoView::OnAlignLeft)
	ON_UPDATE_COMMAND_UI(ID_ALIGN_LEFT, CWinProMoView::OnUpdateAlignLeft)
	ON_COMMAND(ID_ALIGN_MIDDLE, CWinProMoView::OnAlignMiddle)
	ON_UPDATE_COMMAND_UI(ID_ALIGN_MIDDLE, CWinProMoView::OnUpdateAlignMiddle)
	ON_COMMAND(ID_ALIGN_RIGHT, CWinProMoView::OnAlignRight)
	ON_UPDATE_COMMAND_UI(ID_ALIGN_RIGHT, CWinProMoView::OnUpdateAlignRight)
	ON_COMMAND(ID_ALIGN_TOP, CWinProMoView::OnAlignTop)
	ON_UPDATE_COMMAND_UI(ID_ALIGN_TOP, CWinProMoView::OnUpdateAlignTop)
	ON_COMMAND(ID_EDIT_GRIDSIZE, CWinProMoView::OnEditGridsize)
	ON_COMMAND(ID_EDIT_CANVASSIZE, CWinProMoView::OnEditCanvassize)
	ON_COMMAND(ID_VIEW_PAGEBREAKS, &CWinProMoView::OnViewPagebreaks)
	ON_UPDATE_COMMAND_UI(ID_VIEW_PAGEBREAKS, &CWinProMoView::OnUpdateViewPagebreaks)
	ON_COMMAND(ID_ZOOM_100, &CWinProMoView::OnZoom100)
	ON_COMMAND(ID_ZOOM_200, &CWinProMoView::OnZoom200)
	ON_COMMAND(ID_ZOOM_50, &CWinProMoView::OnZoom50)
	ON_COMMAND(ID_ZOOM_150, &CWinProMoView::OnZoom150)
	ON_COMMAND(ID_ZOOM_400, &CWinProMoView::OnZoom400)
	ON_COMMAND(ID_ZOOM_75, &CWinProMoView::OnZoom75)
	ON_COMMAND(ID_EDIT_REDO, &CWinProMoView::OnEditRedo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_REDO, &CWinProMoView::OnUpdateEditRedo)
	ON_COMMAND(ID_FORMAT_FONT, &CWinProMoView::OnFormatFont)
	ON_UPDATE_COMMAND_UI(ID_FORMAT_FONT, &CWinProMoView::OnUpdateFormatFont)
	ON_COMMAND(ID_ALIGNMENT_BOTTOM, &CWinProMoView::OnAlignmentBottom)
	ON_COMMAND(ID_ALIGNMENT_CENTER, &CWinProMoView::OnAlignmentCenter)
	ON_COMMAND(ID_ALIGNMENT_LEFT, &CWinProMoView::OnAlignmentLeft)
	ON_COMMAND(ID_ALIGNMENT_MIDDLE, &CWinProMoView::OnAlignmentMiddle)
	ON_COMMAND(ID_ALIGNMENT_MULTILINE, &CWinProMoView::OnAlignmentMultiline)
	ON_COMMAND(ID_ALIGNMENT_RIGHT, &CWinProMoView::OnAlignmentRight)
	ON_COMMAND(ID_ALIGNMENT_TOP, &CWinProMoView::OnAlignmentTop)
	ON_UPDATE_COMMAND_UI(ID_ALIGNMENT_BOTTOM, &CWinProMoView::OnUpdateAlignmentBottom)
	ON_UPDATE_COMMAND_UI(ID_ALIGNMENT_CENTER, &CWinProMoView::OnUpdateAlignmentCenter)
	ON_UPDATE_COMMAND_UI(ID_ALIGNMENT_LEFT, &CWinProMoView::OnUpdateAlignmentLeft)
	ON_UPDATE_COMMAND_UI(ID_ALIGNMENT_MIDDLE, &CWinProMoView::OnUpdateAlignmentMiddle)
	ON_UPDATE_COMMAND_UI(ID_ALIGNMENT_MULTILINE, &CWinProMoView::OnUpdateAlignmentMultiline)
	ON_UPDATE_COMMAND_UI(ID_ALIGNMENT_RIGHT, &CWinProMoView::OnUpdateAlignmentRight)
	ON_UPDATE_COMMAND_UI(ID_ALIGNMENT_TOP, &CWinProMoView::OnUpdateAlignmentTop)
	ON_COMMAND(ID_BACKGROUND_COLOR, &CWinProMoView::OnBackgroundColor)
	ON_UPDATE_COMMAND_UI(ID_BACKGROUND_COLOR, &CWinProMoView::OnUpdateBackgroundColor)
	ON_COMMAND(ID_BACKGROUND_TRANSPARENT, &CWinProMoView::OnBackgroundTransparent)
	ON_UPDATE_COMMAND_UI(ID_BACKGROUND_TRANSPARENT, &CWinProMoView::OnUpdateBackgroundTransparent)
	ON_COMMAND(ID_FILL_COLOR, &CWinProMoView::OnFillColor)
	ON_UPDATE_COMMAND_UI(ID_FILL_COLOR, &CWinProMoView::OnUpdateFillColor)
	ON_COMMAND(ID_PATTERN_CROSSHATCH, &CWinProMoView::OnPatternCrosshatch)
	ON_UPDATE_COMMAND_UI(ID_PATTERN_CROSSHATCH, &CWinProMoView::OnUpdatePatternCrosshatch)
	ON_COMMAND(ID_PATTERN_DIAGONALCROSSHATCH, &CWinProMoView::OnPatternDiagonalcrosshatch)
	ON_UPDATE_COMMAND_UI(ID_PATTERN_DIAGONALCROSSHATCH, &CWinProMoView::OnUpdatePatternDiagonalcrosshatch)
	ON_COMMAND(ID_PATTERN_DIAGONALLEFT, &CWinProMoView::OnPatternDiagonalleft)
	ON_UPDATE_COMMAND_UI(ID_PATTERN_DIAGONALLEFT, &CWinProMoView::OnUpdatePatternDiagonalleft)
	ON_COMMAND(ID_PATTERN_DIAGONALRIGHT, &CWinProMoView::OnPatternDiagonalright)
	ON_UPDATE_COMMAND_UI(ID_PATTERN_DIAGONALRIGHT, &CWinProMoView::OnUpdatePatternDiagonalright)
	ON_COMMAND(ID_PATTERN_HORIZONTAL, &CWinProMoView::OnPatternHorizontal)
	ON_UPDATE_COMMAND_UI(ID_PATTERN_HORIZONTAL, &CWinProMoView::OnUpdatePatternHorizontal)
	ON_COMMAND(ID_PATTERN_SOLID, &CWinProMoView::OnPatternSolid)
	ON_UPDATE_COMMAND_UI(ID_PATTERN_SOLID, &CWinProMoView::OnUpdatePatternSolid)
	ON_COMMAND(ID_PATTERN_VERTICAL, &CWinProMoView::OnPatternVertical)
	ON_UPDATE_COMMAND_UI(ID_PATTERN_VERTICAL, &CWinProMoView::OnUpdatePatternVertical)
	ON_COMMAND(ID_LINE_COLOR, &CWinProMoView::OnLineColor)
	ON_UPDATE_COMMAND_UI(ID_LINE_COLOR, &CWinProMoView::OnUpdateLineColor)
	ON_COMMAND(ID_STYLE_SOLID, &CWinProMoView::OnStyleSolid)
	ON_UPDATE_COMMAND_UI(ID_STYLE_SOLID, &CWinProMoView::OnUpdateStyleSolid)
	ON_COMMAND(ID_STYLE_DOTTED, &CWinProMoView::OnStyleDotted)
	ON_UPDATE_COMMAND_UI(ID_STYLE_DOTTED, &CWinProMoView::OnUpdateStyleDotted)
	ON_COMMAND(ID_STYLE_DASHED, &CWinProMoView::OnStyleDashed)
	ON_UPDATE_COMMAND_UI(ID_STYLE_DASHED, &CWinProMoView::OnUpdateStyleDashed)
	ON_COMMAND(ID_STYLE_DOTDASHDOTTED, &CWinProMoView::OnStyleDotdashdotted)
	ON_UPDATE_COMMAND_UI(ID_STYLE_DOTDASHDOTTED, &CWinProMoView::OnUpdateStyleDotdashdotted)
	ON_COMMAND(ID_STYLE_DASHDOTTED, &CWinProMoView::OnStyleDashdotted)
	ON_UPDATE_COMMAND_UI(ID_STYLE_DASHDOTTED, &CWinProMoView::OnUpdateStyleDashdotted)
	ON_COMMAND(ID_WIDTH_1PT, &CWinProMoView::OnWidth1pt)
	ON_UPDATE_COMMAND_UI(ID_WIDTH_1PT, &CWinProMoView::OnUpdateWidth1pt)
	ON_COMMAND(ID_WIDTH_2PT, &CWinProMoView::OnWidth2pt)
	ON_UPDATE_COMMAND_UI(ID_WIDTH_2PT, &CWinProMoView::OnUpdateWidth2pt)
	ON_COMMAND(ID_WIDTH_4PT, &CWinProMoView::OnWidth4pt)
	ON_UPDATE_COMMAND_UI(ID_WIDTH_4PT, &CWinProMoView::OnUpdateWidth4pt)
	ON_COMMAND_RANGE(1000, 10000, OnPluginCommand)
	ON_UPDATE_COMMAND_UI_RANGE(1000, 10000, OnUpdatePluginCommand)
	ON_COMMAND(ID_FILE_EXPORT, &CWinProMoView::OnFileExport)
	END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinProMoView construction/destruction

CWinProMoView::CWinProMoView()
{
	m_screenResolutionX = 0;
	m_screenResolutionY = 0;
	m_nHorzPages = 0;
	m_nVertPages = 0;
	m_cmdHandler = NULL;
}

CProMoEditor* CWinProMoView::GetEditor()
{
	if (m_cmdHandler) {
		return m_cmdHandler->GetEditor();
	}
	return NULL;
}

void CWinProMoView::SetPageSize()
{
	CDC dc;
	if (!GetPrinterDC(dc))
	{
		AfxMessageBox(_T("No printer available."));
		return;
	}

	GetEditor()->SetPageLayout(&dc);
	
	dc.DeleteDC();
}

CWinProMoView::~CWinProMoView()
{
	delete m_cmdHandler;
}

BOOL CWinProMoView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

void CWinProMoView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

}

void CWinProMoView::SetPageSizeFromPrinter()
{
	CClientDC viewDC(this);
	CDC printDC;

	CWinProMoDoc* pDoc = GetDocument();
	if (viewDC && pDoc) {
		int screenResolutionX = viewDC.GetDeviceCaps(LOGPIXELSX);
		int screenResolutionY = viewDC.GetDeviceCaps(LOGPIXELSY);

		if (GetPrinterDC(printDC)) {

			// Canvas size equals to current page size
			int printResolutionX = printDC.GetDeviceCaps(LOGPIXELSX);
			int printResolutionY = printDC.GetDeviceCaps(LOGPIXELSY);

			int horzSize = round((double)printDC.GetDeviceCaps(HORZRES) * (double)screenResolutionX / printResolutionX);
			int vertSize = round((double)printDC.GetDeviceCaps(VERTRES) * (double)screenResolutionY / printResolutionY);

			pDoc->GetData()->SetVirtualSize(CSize(horzSize - 1, vertSize - 1));
			printDC.DeleteDC();

		}
		// No printer, so default to 8x11
		else {
			pDoc->GetData()->SetVirtualSize(CSize(8 * screenResolutionX, 11 * screenResolutionX));
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWinProMoView drawing

void CWinProMoView::OnDraw(CDC* pDC)
{

}

/////////////////////////////////////////////////////////////////////////////
// CWinProMoView printing

BOOL CWinProMoView::OnPreparePrinting(CPrintInfo* pInfo)
{	
	CDC dc;
	if (!GetPrinterDC(dc))
	{
		AfxMessageBox(_T("No printer available."));
		return FALSE;
	}

	if (GetEditor())
	{
		// Virtual size in logical units
		CSize virtSize = GetEditor()->GetVirtualSize();

		if (pInfo) {

			// Scale with printer resolution / screen resolution
			double wzoom = (double)dc.GetDeviceCaps(LOGPIXELSX) / m_screenResolutionX;
			double hzoom = (double)dc.GetDeviceCaps(LOGPIXELSY) / m_screenResolutionY;
			int virtWidth = (int)round(virtSize.cx * wzoom);
			int virtHeight = (int)round(virtSize.cy * hzoom);

			CSize paperSize;
			paperSize.cx = dc.GetDeviceCaps(HORZRES);
			paperSize.cy = dc.GetDeviceCaps(VERTRES);

			m_nHorzPages = (virtWidth + paperSize.cx - 1) / paperSize.cx;
			m_nVertPages = (virtHeight + paperSize.cy - 1) / paperSize.cy;

			int totalPages = m_nHorzPages * m_nVertPages;

			pInfo->SetMaxPage(totalPages);
			pInfo->m_nCurPage = 1; // start at first page
		}
	}

	dc.DeleteDC();

	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWinProMoView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	if (!GetEditor())
		return;

	double zoom = (double)pDC->GetDeviceCaps(LOGPIXELSX) / m_screenResolutionX;

	// total rect = entire diagram in printer coords
	CRect totalRect(0, 0,
		(int)(GetEditor()->GetVirtualSize().cx * zoom),
		(int)(GetEditor()->GetVirtualSize().cy * zoom));

	// Determine current page index
	int pageIndex = pInfo->m_nCurPage - 1; // 0-based
	int pageX = pageIndex % m_nHorzPages;
	int pageY = pageIndex / m_nHorzPages;

	int pageWidth = pDC->GetDeviceCaps(HORZRES);
	int pageHeight = pDC->GetDeviceCaps(VERTRES);

	int offsetX = pageX * pageWidth;
	int offsetY = pageY * pageHeight;

	// Clip to page area
	CRect clipRect(0, 0, pageWidth, pageHeight);
	pDC->SaveDC();  // save state so we can restore later
	pDC->IntersectClipRect(&clipRect);

	// Shift origin so that Print() draws the right slice
	pDC->SetWindowOrg(offsetX, offsetY);

	COLORREF col = GetEditor()->GetBackgroundColor();
	GetEditor()->SetRedraw(FALSE);
	GetEditor()->SetBackgroundColor(RGB(255, 255, 255));
	GetEditor()->Print(pDC, totalRect, zoom);
	GetEditor()->SetBackgroundColor(col);
	GetEditor()->SetRedraw(TRUE);

	pDC->RestoreDC(-1); // restore to original

}


void CWinProMoView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	

}

void CWinProMoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CWinProMoView::OnFilePrintPreview()
{
	CDC dc;
	if (!GetPrinterDC(dc))
	{
		AfxMessageBox(_T("No printer available."));
		return; 
	}
	CView::OnFilePrintPreview();
}

/////////////////////////////////////////////////////////////////////////////
// OLE Server support

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the server (not the container) causes the deactivation.
void CWinProMoView::OnCancelEditSrvr()
{
	/*COleServerDoc* pOleDoc = DYNAMIC_DOWNCAST(COleServerDoc, GetDocument());
	if (pOleDoc)
		pOleDoc->OnDeactivateUI(FALSE);*/
	GetDocument()->OnDeactivateUI(FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CWinProMoView diagnostics

#ifdef _DEBUG
void CWinProMoView::AssertValid() const
{
	CView::AssertValid();
}

void CWinProMoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}


CWinProMoDoc* CWinProMoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinProMoDoc)));
	return (CWinProMoDoc*)m_pDocument;
}

#endif //_DEBUG

void CWinProMoView::CreateCmdHandler()
{
	if (!m_cmdHandler) {

		if (GetDocument()->m_pluginReference) {
			m_cmdHandler = GetDocument()->m_pluginReference->pluginInterface->GetCmdHandler();
		}

	}

	if (GetEditor()) {
		if (!GetEditor()->m_hWnd)
		{
			// Creating the editor window
			CWinProMoDoc* pDoc = GetDocument();

			CRect rect;
			GetClientRect(rect);
			GetEditor()->Create(WS_CHILD | WS_VISIBLE, rect, this, pDoc->GetData());

			// We get the screen resolution, which we will use 
			// for scaling to printer. See also OnDraw.
			CClientDC dc(this);
			m_screenResolutionX = dc.GetDeviceCaps(LOGPIXELSX);
			m_screenResolutionY = dc.GetDeviceCaps(LOGPIXELSY);

			CProMoRenderer* renderer = pDoc->GetRenderer();

			if (renderer) {
				renderer->SetScreenResolution(m_screenResolutionX);
			}

			SetPageSize();

			GetEditor()->SetModified(TRUE);

		}
		else
			GetEditor()->Clear();
	}
}

BOOL CWinProMoView::GetPrinterDC(CDC& dc)
{
	// First try via application (respects user’s print setup)
	AfxGetApp()->CreatePrinterDC(dc);
	if (dc.GetSafeHdc())
		return TRUE;

	// Fallback: try defaults via CPrintDialog
	CPrintDialog dlg(FALSE);
	if (dlg.GetDefaults())
	{
		HDC hPrinterDC = dlg.GetPrinterDC();
		if (hPrinterDC)
		{
			dc.Attach(hPrinterDC);
			return TRUE;
		}
	}

	// Nothing available
	return FALSE;
}

void CWinProMoView::CopyImageToClipboard()
{
	if (GetEditor()) {
		CProMoRenderer* rend = GetDocument()->GetRenderer();
		if (rend) {
			// metafile HGLOBAL generation

			CMetaFileDC	metaDC;
			
			metaDC.Create(NULL);
			
			rend->RenderSelectionAsMetafile(metaDC, 1.0);
			
			HMETAFILE hMeta = metaDC.Close();

			if (!hMeta)
				return;

			HGLOBAL hGlobal = ::GlobalAlloc(GMEM_MOVEABLE, sizeof(METAFILEPICT));
			if (!hGlobal)
				return;

			METAFILEPICT* pMfp =
				(METAFILEPICT*)::GlobalLock(hGlobal);

			if (!pMfp)
			{
				::GlobalFree(hGlobal);
				return;
			}

			pMfp->mm = MM_TEXT;
			pMfp->xExt = GetDocument()->GetData()->GetSelectionTotalSize().cx;
			pMfp->yExt = GetDocument()->GetData()->GetSelectionTotalSize().cy;
			pMfp->hMF = hMeta;

			::GlobalUnlock(hGlobal);
			
			// DIB HGLOBAL generation

			CDibHelper dib;
			rend->RenderSelectionAsRaster(dib, 300);
			
			HGLOBAL hDib = dib.CreateDibGlobalForClipboard();
			if (!hDib) return;

			if (!::OpenClipboard(NULL))
			{
				::GlobalFree(hDib);
				return;
			}

			::EmptyClipboard();
			::SetClipboardData(CF_DIB, hDib);
			::SetClipboardData(CF_METAFILEPICT, hGlobal);
			::CloseClipboard();

			DeleteMetaFile(hMeta);

		}
	}
}

void CWinProMoView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	if (GetEditor()) {
		if (GetEditor()->m_hWnd)
			GetEditor()->MoveWindow(0, 0, cx, cy);
	}
}

BOOL CWinProMoView::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}

void CWinProMoView::OnButtonSnap()
{
	if (GetEditor()) {
		BOOL snap = !GetEditor()->GetSnapToGrid();
		GetEditor()->SetSnapToGrid(snap);
	}
}

// Edit menu
void CWinProMoView::OnEditCopy()
{
	if (GetEditor()) {
		CopyImageToClipboard();
		GetEditor()->Copy();
	}

}

void CWinProMoView::OnEditCut()
{

	if (GetEditor()) {
		CopyImageToClipboard();
		GetEditor()->Cut();
	}

}

void CWinProMoView::OnEditPaste()
{

	if (GetEditor()) {
		GetEditor()->Paste();
	}

}

void CWinProMoView::OnEditUndo()
{

	if (GetEditor()) {
		GetEditor()->Undo();
	}

}

void CWinProMoView::OnUpdateEditUndo(CCmdUI* pCmdUI)
{

	if (GetEditor()) {
		GetEditor()->UpdateUndo(pCmdUI);
	}

}


void CWinProMoView::OnEditRedo()
{
	if (GetEditor()) {
		GetEditor()->Redo();
	}
}


void CWinProMoView::OnUpdateEditRedo(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		GetEditor()->UpdateRedo(pCmdUI);
	}
}

void CWinProMoView::OnUpdateEditCopy(CCmdUI* pCmdUI)
{

	if (GetEditor()) {
		GetEditor()->UpdateCopy(pCmdUI);
	}

}

void CWinProMoView::OnUpdateEditCut(CCmdUI* pCmdUI)
{

	if (GetEditor()) {
		GetEditor()->UpdateCut(pCmdUI);
	}

}

void CWinProMoView::OnUpdateEditPaste(CCmdUI* pCmdUI)
{

	if (GetEditor()) {
		GetEditor()->UpdatePaste(pCmdUI);
	}

}

void CWinProMoView::OnUpdateButtonSnap(CCmdUI* pCmdUI)
{

	if (GetEditor()) {
		pCmdUI->SetCheck(GetEditor()->GetSnapToGrid());
		pCmdUI->Enable(GetEditor()->IsGridVisible());
	}

}


/////////////////////////////////////////////////////////////////////////////
// CWinProMoView message handlers

void CWinProMoView::OnEditDelete()
{
	if (GetEditor()) {
		GetEditor()->DeleteAllSelected();
	}
}

void CWinProMoView::OnUpdateEditDelete(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		pCmdUI->Enable(GetEditor()->IsAnyObjectSelected());
	}
}


void CWinProMoView::OnArrangeGroup()
{
	if (GetEditor()) {
		GetEditor()->Group();
	}
}


void CWinProMoView::OnUpdateArrangeGroup(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		GetEditor()->UpdateGroup(pCmdUI);
	}
}


void CWinProMoView::OnArrangeUngroup()
{
	if (GetEditor()) {
		GetEditor()->Ungroup();
	}
}


void CWinProMoView::OnUpdateArrangeUngroup(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		GetEditor()->UpdateUngroup(pCmdUI);
	}
}


void CWinProMoView::OnViewGrid()
{
	if (GetEditor()) {
		BOOL grid = !GetEditor()->IsGridVisible();
		GetEditor()->ShowGrid(grid);
	}
}


void CWinProMoView::OnUpdateViewGrid(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		pCmdUI->SetCheck(GetEditor()->IsGridVisible());
		pCmdUI->Enable(!GetEditor()->GetSnapToGrid());
	}
}


void CWinProMoView::OnAlignBottom()
{
	if (GetEditor()) {
		GetEditor()->BottomAlignSelected();
	}
}


void CWinProMoView::OnUpdateAlignBottom(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		GetEditor()->UpdateGroup(pCmdUI);
	}
}


void CWinProMoView::OnUpdateAlignCenter(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		GetEditor()->UpdateGroup(pCmdUI);
	}
}


void CWinProMoView::OnAlignCenter()
{
	if (GetEditor()) {
		GetEditor()->CenterAlignSelected();
	}
}


void CWinProMoView::OnAlignLeft()
{
	GetEditor()->LeftAlignSelected();
}


void CWinProMoView::OnUpdateAlignLeft(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		GetEditor()->UpdateGroup(pCmdUI);
	}
}


void CWinProMoView::OnAlignMiddle()
{
	if (GetEditor()) {
		GetEditor()->MiddleAlignSelected();
	}
}


void CWinProMoView::OnUpdateAlignMiddle(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		GetEditor()->UpdateGroup(pCmdUI);
	}
}


void CWinProMoView::OnAlignRight()
{
	GetEditor()->RightAlignSelected();
}


void CWinProMoView::OnUpdateAlignRight(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		GetEditor()->UpdateGroup(pCmdUI);
	}
}


void CWinProMoView::OnAlignTop()
{
	GetEditor()->TopAlignSelected();
}


void CWinProMoView::OnUpdateAlignTop(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		GetEditor()->UpdateGroup(pCmdUI);
	}
}


void CWinProMoView::OnEditGridsize()
{
	if (GetEditor()) {
		CGridSizeDialog	dlg;

		dlg.m_width = GetEditor()->GetGridSize().cx;
		dlg.m_height = GetEditor()->GetGridSize().cy;
		if (dlg.DoModal() == IDOK)
			GetEditor()->SetGridSize(CSize(dlg.m_width, dlg.m_height));
	}
}


void CWinProMoView::OnEditCanvassize()
{
	if (GetEditor()) {
		CCanvasSizeDialog	dlg;

		dlg.m_width = GetEditor()->GetVirtualSize().cx;
		dlg.m_height = GetEditor()->GetVirtualSize().cy;
		if (dlg.DoModal() == IDOK)
			GetEditor()->SetVirtualSize(CSize(dlg.m_width, dlg.m_height));
	}
}


void CWinProMoView::OnViewPagebreaks()
{
	if (GetEditor()) {
		BOOL breaks = !GetEditor()->IsPageBreaksVisible();
		GetEditor()->ShowPageBreaks(breaks);
	}
}


void CWinProMoView::OnUpdateViewPagebreaks(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		pCmdUI->SetCheck(GetEditor()->IsPageBreaksVisible());
	}
}


void CWinProMoView::OnZoom100()
{
	if (GetEditor()) {
		GetEditor()->SetZoom(1.0);
	}
}


void CWinProMoView::OnZoom200()
{
	if (GetEditor()) {
		GetEditor()->SetZoom(2.0);
	}
}


void CWinProMoView::OnZoom50()
{
	if (GetEditor()) {
		GetEditor()->SetZoom(0.5);
	}
}


void CWinProMoView::OnZoom150()
{
	if (GetEditor()) {
		GetEditor()->SetZoom(1.5);
	}
}


void CWinProMoView::OnZoom400()
{
	if (GetEditor()) {
		GetEditor()->SetZoom(4.0);
	}
}


void CWinProMoView::OnZoom75()
{
	if (GetEditor()) {
		GetEditor()->SetZoom(0.75);
	}
}

void CWinProMoView::OnFormatFont()
{
	if (GetEditor()) {
		CClientDC dc(this);
		LOGFONT lf = { 0 };  // zero-initialize

		lf.lfHeight = -MulDiv(GetEditor()->GetFontSize(), GetDeviceCaps(dc, LOGPIXELSY), 72);

		// Weight
		lf.lfWeight = GetEditor()->GetFontWeight();

		// Style flags
		lf.lfItalic = GetEditor()->IsFontItalic();
		lf.lfUnderline = GetEditor()->IsFontUnderline();
		lf.lfStrikeOut = GetEditor()->IsFontStrikeOut();

		// Charset (use DEFAULT_CHARSET unless you need otherwise)
		lf.lfCharSet = DEFAULT_CHARSET;

		// Font face name
#if _MSC_VER >= 1500
		_tcsncpy_s(lf.lfFaceName, LF_FACESIZE, GetEditor()->GetFontName(), _TRUNCATE);
#else
		_tcsncpy(lf.lfFaceName, GetEditor()->GetFontName(), LF_FACESIZE - 1);
		lf.lfFaceName[LF_FACESIZE - 1] = _T('\0');
#endif

		CFontDialog dlg(&lf, CF_EFFECTS | CF_SCREENFONTS, NULL, AfxGetMainWnd());
		dlg.m_cf.rgbColors = GetEditor()->GetTextColor();

		if (dlg.DoModal() == IDOK)
		{
			GetEditor()->SetFontName(dlg.GetFaceName());
			GetEditor()->SetFontSize(dlg.GetSize()/10);
			GetEditor()->SetFontWeight(dlg.GetWeight());
			GetEditor()->SetFontItalic(dlg.IsItalic());
			GetEditor()->SetFontUnderline(dlg.IsUnderline());
			GetEditor()->SetFontStrikeOut(dlg.IsStrikeOut());
			GetEditor()->SetTextColor(dlg.GetColor());
		}
	}
}

void CWinProMoView::OnUpdateFormatFont(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		pCmdUI->Enable(GetEditor()->IsAnyObjectSelected());
	}
}

void CWinProMoView::OnAlignmentBottom()
{
	if (GetEditor()) {
		GetEditor()->SetTextVerticalAlignment(DT_BOTTOM);	
	}
}

void CWinProMoView::OnAlignmentCenter()
{
	if (GetEditor()) {
		GetEditor()->SetTextHorizontalAlignment(DT_CENTER);
	}
}

void CWinProMoView::OnAlignmentLeft()
{
	if (GetEditor()) {
		GetEditor()->SetTextHorizontalAlignment(DT_LEFT);
	}
}

void CWinProMoView::OnAlignmentMiddle()
{
	if (GetEditor()) {
		GetEditor()->SetTextVerticalAlignment(DT_VCENTER);
	}
}

void CWinProMoView::OnAlignmentMultiline()
{
	if (GetEditor()) {
		if (GetEditor()->HasTextAlignmentFlag(DT_WORDBREAK)) {
			GetEditor()->SetTextAlignmentFlag(DT_SINGLELINE, TRUE);
		}
		else {
			GetEditor()->SetTextAlignmentFlag(DT_WORDBREAK, TRUE);
		}
	}
}

void CWinProMoView::OnAlignmentRight()
{
	if (GetEditor()) {
		GetEditor()->SetTextHorizontalAlignment(DT_RIGHT);
	}
}

void CWinProMoView::OnAlignmentTop()
{
	if (GetEditor()) {
		GetEditor()->SetTextVerticalAlignment(DT_TOP);
	}
}

void CWinProMoView::OnUpdateAlignmentBottom(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		pCmdUI->Enable(GetEditor()->IsAnyObjectSelected() && !GetEditor()->IsLocked(LOCK_ALIGNMENT));
		pCmdUI->SetCheck(GetEditor()->GetTextVerticalAlignment() == DT_BOTTOM);
	}
}

void CWinProMoView::OnUpdateAlignmentCenter(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		pCmdUI->Enable(GetEditor()->IsAnyObjectSelected() && !GetEditor()->IsLocked(LOCK_ALIGNMENT));
		pCmdUI->SetCheck(GetEditor()->GetTextHorizontalAlignment() == DT_CENTER);
	}
}

void CWinProMoView::OnUpdateAlignmentLeft(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		pCmdUI->Enable(GetEditor()->IsAnyObjectSelected() && !GetEditor()->IsLocked(LOCK_ALIGNMENT));
		pCmdUI->SetCheck(GetEditor()->GetTextHorizontalAlignment() == DT_LEFT);
	}
}

void CWinProMoView::OnUpdateAlignmentMiddle(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		pCmdUI->Enable(GetEditor()->IsAnyObjectSelected() && !GetEditor()->IsLocked(LOCK_ALIGNMENT));
		pCmdUI->SetCheck(GetEditor()->GetTextVerticalAlignment() == DT_VCENTER);
	}
}

void CWinProMoView::OnUpdateAlignmentMultiline(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		pCmdUI->Enable(GetEditor()->IsAnyObjectSelected() && !GetEditor()->IsLocked(LOCK_ALIGNMENT));
		pCmdUI->SetCheck(GetEditor()->HasTextAlignmentFlag(DT_WORDBREAK));
	}
}

void CWinProMoView::OnUpdateAlignmentRight(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		pCmdUI->Enable(GetEditor()->IsAnyObjectSelected() && !GetEditor()->IsLocked(LOCK_ALIGNMENT));
		pCmdUI->SetCheck(GetEditor()->GetTextHorizontalAlignment() == DT_RIGHT);
	}
}

void CWinProMoView::OnUpdateAlignmentTop(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		pCmdUI->Enable(GetEditor()->IsAnyObjectSelected() && !GetEditor()->IsLocked(LOCK_ALIGNMENT));
		pCmdUI->SetCheck(GetEditor()->GetTextVerticalAlignment() == DT_TOP);
	}
}

void CWinProMoView::OnBackgroundColor()
{
	if (GetEditor()) {
		CColorDialog dlg (GetEditor()->GetBkColor(), CC_FULLOPEN | CC_RGBINIT, AfxGetMainWnd());
		if (dlg.DoModal() == IDOK)
		{
			GetEditor()->SetBkColor(dlg.GetColor());
		}
	}
}

void CWinProMoView::OnUpdateBackgroundColor(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		pCmdUI->Enable(GetEditor()->IsAnyObjectSelected() && !GetEditor()->IsLocked(LOCK_BKCOLOR));
	}
}

void CWinProMoView::OnBackgroundTransparent()
{
	if (GetEditor()) {
		if (GetEditor()->GetBkMode() == TRANSPARENT)
			GetEditor()->SetBkMode(OPAQUE);
		else
			GetEditor()->SetBkMode(TRANSPARENT);
	}
}

void CWinProMoView::OnUpdateBackgroundTransparent(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		pCmdUI->Enable(GetEditor()->IsAnyObjectSelected() && !GetEditor()->IsLocked(LOCK_BKMODE));
		pCmdUI->SetCheck(GetEditor()->GetBkMode() == TRANSPARENT);
	}
}

void CWinProMoView::OnFillColor()
{
	if (GetEditor()) {
		CColorDialog dlg(GetEditor()->GetFillColor(), CC_FULLOPEN | CC_RGBINIT, AfxGetMainWnd());
		if (dlg.DoModal() == IDOK)
		{
			GetEditor()->SetFillColor(dlg.GetColor());
		}
	}
}

void CWinProMoView::OnUpdateFillColor(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		if (GetEditor()->IsAnyBlockSelected()) {
			pCmdUI->Enable(!GetEditor()->IsLocked(LOCK_FILLCOLOR));
		}
		else {
			pCmdUI->Enable(FALSE);
		}
	}
}

void CWinProMoView::OnPatternCrosshatch()
{
	if (GetEditor()) {
		GetEditor()->SetFillPattern(TRUE);
		GetEditor()->SetFillStyle(HS_CROSS);
	}
}

void CWinProMoView::OnUpdatePatternCrosshatch(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		if (GetEditor()->IsAnyBlockSelected()) {
			pCmdUI->Enable(!GetEditor()->IsLocked(LOCK_FILLSTYLE));
			pCmdUI->SetCheck((GetEditor()->GetFillStyle() == HS_CROSS) && GetEditor()->IsFillPattern());
		}
		else {
			pCmdUI->Enable(FALSE);
			pCmdUI->SetCheck(FALSE);
		}
	}
}

void CWinProMoView::OnPatternDiagonalcrosshatch()
{
	if (GetEditor()) {
		GetEditor()->SetFillPattern(TRUE);
		GetEditor()->SetFillStyle(HS_DIAGCROSS);
	}
}

void CWinProMoView::OnUpdatePatternDiagonalcrosshatch(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		if (GetEditor()->IsAnyBlockSelected()) {
			pCmdUI->Enable(!GetEditor()->IsLocked(LOCK_FILLSTYLE));
			pCmdUI->SetCheck((GetEditor()->GetFillStyle() == HS_DIAGCROSS) && GetEditor()->IsFillPattern());
		}
		else {
			pCmdUI->Enable(FALSE);
			pCmdUI->SetCheck(FALSE);
		}
	}
}

void CWinProMoView::OnPatternDiagonalleft()
{
	if (GetEditor()) {
		GetEditor()->SetFillPattern(TRUE);
		GetEditor()->SetFillStyle(HS_BDIAGONAL);
	}
}

void CWinProMoView::OnUpdatePatternDiagonalleft(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		if (GetEditor()->IsAnyBlockSelected()) {
			pCmdUI->Enable(!GetEditor()->IsLocked(LOCK_FILLSTYLE));
			pCmdUI->SetCheck((GetEditor()->GetFillStyle() == HS_BDIAGONAL) && GetEditor()->IsFillPattern());
		}
		else {
			pCmdUI->Enable(FALSE);
			pCmdUI->SetCheck(FALSE);
		}
	}
}

void CWinProMoView::OnPatternDiagonalright()
{
	if (GetEditor()) {
		GetEditor()->SetFillPattern(TRUE);
		GetEditor()->SetFillStyle(HS_FDIAGONAL);
	}
}

void CWinProMoView::OnUpdatePatternDiagonalright(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		if (GetEditor()->IsAnyBlockSelected()) {
			pCmdUI->Enable(!GetEditor()->IsLocked(LOCK_FILLSTYLE));
			pCmdUI->SetCheck((GetEditor()->GetFillStyle() == HS_FDIAGONAL) && GetEditor()->IsFillPattern());
		}
		else {
			pCmdUI->Enable(FALSE);
			pCmdUI->SetCheck(FALSE);
		}
	}
}

void CWinProMoView::OnPatternHorizontal()
{
	if (GetEditor()) {
		GetEditor()->SetFillPattern(TRUE);
		GetEditor()->SetFillStyle(HS_HORIZONTAL);
	}
}

void CWinProMoView::OnUpdatePatternHorizontal(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		if (GetEditor()->IsAnyBlockSelected()) {
			pCmdUI->Enable(!GetEditor()->IsLocked(LOCK_FILLSTYLE));
			pCmdUI->SetCheck((GetEditor()->GetFillStyle() == HS_HORIZONTAL) && GetEditor()->IsFillPattern());
		}
		else {
			pCmdUI->Enable(FALSE);
			pCmdUI->SetCheck(FALSE);
		}
	}
}

void CWinProMoView::OnPatternSolid()
{
	if (GetEditor()) {
		GetEditor()->SetFillPattern(FALSE);
	}
}

void CWinProMoView::OnUpdatePatternSolid(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		if (GetEditor()->IsAnyBlockSelected()) {
			pCmdUI->Enable(!GetEditor()->IsLocked(LOCK_FILLSTYLE));
			pCmdUI->SetCheck(!GetEditor()->IsFillPattern());
		}
		else {
			pCmdUI->Enable(FALSE);
			pCmdUI->SetCheck(FALSE);
		}
	}
}

void CWinProMoView::OnPatternVertical()
{
	if (GetEditor()) {
		GetEditor()->SetFillPattern(TRUE);
		GetEditor()->SetFillStyle(HS_VERTICAL);
	}
}

void CWinProMoView::OnUpdatePatternVertical(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		if (GetEditor()->IsAnyBlockSelected()) {
			pCmdUI->Enable(!GetEditor()->IsLocked(LOCK_FILLSTYLE));
			pCmdUI->SetCheck((GetEditor()->GetFillStyle() == HS_VERTICAL) && GetEditor()->IsFillPattern());
		}
		else {
			pCmdUI->Enable(FALSE);
			pCmdUI->SetCheck(FALSE);
		}
	}
}

void CWinProMoView::OnLineColor()
{
	if (GetEditor()) {
		CColorDialog dlg(GetEditor()->GetLineColor(), CC_FULLOPEN | CC_RGBINIT, AfxGetMainWnd());
		if (dlg.DoModal() == IDOK)
		{
			GetEditor()->SetLineColor(dlg.GetColor());
		}
	}
}

void CWinProMoView::OnUpdateLineColor(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		if (GetEditor()->IsAnyEdgeSelected() || GetEditor()->IsAnyBlockSelected()) {
			pCmdUI->Enable(!GetEditor()->IsLocked(LOCK_LINECOLOR));
		}
		else {
			pCmdUI->Enable(FALSE);
		}
	}
}

void CWinProMoView::OnStyleSolid()
{
	if (GetEditor()) {
		GetEditor()->SetLineStyle(PS_SOLID);
	}
}

void CWinProMoView::OnUpdateStyleSolid(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		if (GetEditor()->IsAnyEdgeSelected() || GetEditor()->IsAnyBlockSelected()) {
			pCmdUI->Enable(!GetEditor()->IsLocked(LOCK_LINESTYLE) && GetEditor()->GetLineWidth() == 1);
			pCmdUI->SetCheck((GetEditor()->GetLineStyle() == PS_SOLID) || GetEditor()->GetLineWidth() != 1);
		}
		else {
			pCmdUI->Enable(FALSE);
			pCmdUI->SetCheck(FALSE);
		}
	}
}

void CWinProMoView::OnStyleDotted()
{
	if (GetEditor()) {
		GetEditor()->SetLineStyle(PS_DOT);
	}
}

void CWinProMoView::OnUpdateStyleDotted(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		if (GetEditor()->IsAnyEdgeSelected() || GetEditor()->IsAnyBlockSelected()) {
			pCmdUI->Enable(!GetEditor()->IsLocked(LOCK_LINESTYLE) && GetEditor()->GetLineWidth() == 1);
			pCmdUI->SetCheck((GetEditor()->GetLineStyle() == PS_DOT) && GetEditor()->GetLineWidth() == 1);
		}
		else {
			pCmdUI->Enable(FALSE);
			pCmdUI->SetCheck(FALSE);
		}
	}
}

void CWinProMoView::OnStyleDashed()
{
	if (GetEditor()) {
		GetEditor()->SetLineStyle(PS_DASH);
	}
}

void CWinProMoView::OnUpdateStyleDashed(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		if (GetEditor()->IsAnyEdgeSelected() || GetEditor()->IsAnyBlockSelected()) {
			pCmdUI->Enable(!GetEditor()->IsLocked(LOCK_LINESTYLE) && GetEditor()->GetLineWidth() == 1);
			pCmdUI->SetCheck((GetEditor()->GetLineStyle() == PS_DASH) && GetEditor()->GetLineWidth() == 1);
		}
		else {
			pCmdUI->Enable(FALSE);
			pCmdUI->SetCheck(FALSE);
		}
	}
}

void CWinProMoView::OnStyleDotdashdotted()
{
	if (GetEditor()) {
		GetEditor()->SetLineStyle(PS_DASHDOTDOT);
	}
}

void CWinProMoView::OnUpdateStyleDotdashdotted(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		if (GetEditor()->IsAnyEdgeSelected() || GetEditor()->IsAnyBlockSelected()) {
			pCmdUI->Enable(!GetEditor()->IsLocked(LOCK_LINESTYLE) && GetEditor()->GetLineWidth() == 1);
			pCmdUI->SetCheck((GetEditor()->GetLineStyle() == PS_DASHDOTDOT) && GetEditor()->GetLineWidth() == 1);
		}
		else {
			pCmdUI->Enable(FALSE);
			pCmdUI->SetCheck(FALSE);
		}
	}
}

void CWinProMoView::OnStyleDashdotted()
{
	if (GetEditor()) {
		GetEditor()->SetLineStyle(PS_DASHDOT);
	}
}

void CWinProMoView::OnUpdateStyleDashdotted(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		if (GetEditor()->IsAnyEdgeSelected() || GetEditor()->IsAnyBlockSelected()) {
			pCmdUI->Enable(!GetEditor()->IsLocked(LOCK_LINESTYLE) && GetEditor()->GetLineWidth() == 1);
			pCmdUI->SetCheck((GetEditor()->GetLineStyle() == PS_DASHDOT) && GetEditor()->GetLineWidth() == 1);
		}
		else {
			pCmdUI->Enable(FALSE);
			pCmdUI->SetCheck(FALSE);
		}
	}
}

void CWinProMoView::OnWidth1pt()
{
	if (GetEditor()) {
		GetEditor()->SetLineWidth(1);
	}
}

void CWinProMoView::OnUpdateWidth1pt(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		if (GetEditor()->IsAnyEdgeSelected() || GetEditor()->IsAnyBlockSelected()) {
			pCmdUI->Enable(!GetEditor()->IsLocked(LOCK_LINEWIDTH));
			pCmdUI->SetCheck(GetEditor()->GetLineWidth() == 1);
		}
		else {
			pCmdUI->Enable(FALSE);
			pCmdUI->SetCheck(FALSE);
		}
	}
}

void CWinProMoView::OnWidth2pt()
{
	if (GetEditor()) {
		GetEditor()->SetLineWidth(2);
	}
}

void CWinProMoView::OnUpdateWidth2pt(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		if (GetEditor()->IsAnyEdgeSelected() || GetEditor()->IsAnyBlockSelected()) {
			pCmdUI->Enable(!GetEditor()->IsLocked(LOCK_LINEWIDTH));
			pCmdUI->SetCheck(GetEditor()->GetLineWidth() == 2);
		}
		else {
			pCmdUI->Enable(FALSE);
		}
	}
}

void CWinProMoView::OnWidth4pt()
{
	if (GetEditor()) {
		GetEditor()->SetLineWidth(4);
	}
}

void CWinProMoView::OnUpdateWidth4pt(CCmdUI* pCmdUI)
{
	if (GetEditor()) {
		if (GetEditor()->IsAnyEdgeSelected() || GetEditor()->IsAnyBlockSelected()) {
			pCmdUI->Enable(!GetEditor()->IsLocked(LOCK_LINEWIDTH));
			pCmdUI->SetCheck(GetEditor()->GetLineWidth() == 4);
		}
		else {
			pCmdUI->Enable(FALSE);
		}
	}
}

void CWinProMoView::OnPluginCommand(UINT cmdID)
{
	if (m_cmdHandler && m_cmdHandler->OnPluginCommand(cmdID))
		return; // handled by plugin

	// fallback (unlikely)
	CView::OnCommand(cmdID, 0);
}

void CWinProMoView::OnUpdatePluginCommand(CCmdUI* pCmdUI)
{
	UINT cmdID = pCmdUI->m_nID;

	if (m_cmdHandler && m_cmdHandler->OnPluginUpdateCommandUI(pCmdUI))
		return;

	pCmdUI->ContinueRouting();
}

void CWinProMoView::OnFileExport()
{
	CString filter = _T("Windows Metafile (*.wmf)|*.wmf|"
		"Windows Bitmap (*.bmp)|*.bmp|");
	CFileDialog dlg(FALSE, _T("wmf"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter, NULL);
	if (dlg.DoModal() == IDOK)
	{
		CExportDlg exportDlg;
		CString ext = dlg.GetFileExt();

		if (ext == CString(_T("wmf")))
			exportDlg.SetExportMode(EXPORT_METAFILE);
		else
			exportDlg.SetExportMode(EXPORT_RASTER);
		
		exportDlg.SetSelectionAvailable(GetEditor()->IsAnyObjectSelected());
		if (exportDlg.DoModal() != IDOK)
			return;

		// Show hourglass cursor, as export may take several seconds
		BeginWaitCursor();
		
		CProMoRenderer* rend = GetDocument()->GetRenderer();
		
		if (exportDlg.GetExportMode() == EXPORT_RASTER)
		{
			// raster (bitmap) export
			CDibHelper dib;
			switch (exportDlg.GetExportElement())
			{
				case EXPORT_SELECTION:
					rend->RenderSelectionAsRaster(dib, exportDlg.GetResolution());
					break;
				case EXPORT_CANVAS:
					rend->RenderCanvasAsRaster(dib, exportDlg.GetResolution());
					break;
				default:
					rend->RenderDiagramAsRaster(dib, exportDlg.GetResolution());
			}
			dib.SaveBMP(dlg.GetPathName());
			
		}
		else if (exportDlg.GetExportMode() == EXPORT_METAFILE)
		{
			// vector (metafile) export
			CMetaFileDC	metaDC;
			metaDC.Create(dlg.GetPathName());
			switch (exportDlg.GetExportElement())
			{
			case EXPORT_SELECTION:
				rend->RenderSelectionAsMetafile(metaDC, exportDlg.GetZoom());
				break;
			case EXPORT_CANVAS:
				rend->RenderCanvasAsMetafile(metaDC, exportDlg.GetZoom());
				break;
			default:
				rend->RenderDiagramAsMetafile(metaDC, exportDlg.GetZoom());
			}
			HMETAFILE hmf = metaDC.Close();
			DeleteMetaFile(hmf);
			
		}
		
		// Restore normal cursor
		EndWaitCursor();
	}

}

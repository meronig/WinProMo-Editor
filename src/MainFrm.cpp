/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "WinProMo.h"

#include "MainFrm.h"
#include "../../WinProMo/src/WinProMoView.h"
#include "../../WinProMo/src/ProMoEditor/ProMoEditor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
	ON_MESSAGE(WM_SELECTION_CHANGED, &CMainFrame::OnSelectionChanged)
	ON_COMMAND(ID_VIEW_PROPERTIES, &CMainFrame::OnViewProperties)
	ON_UPDATE_COMMAND_UI(ID_VIEW_PROPERTIES, &CMainFrame::OnUpdateViewProperties)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_VIEW_ELEMENTLIST, &CMainFrame::OnViewElementlist)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ELEMENTLIST, &CMainFrame::OnUpdateViewElementlist)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Remove this if you don't want tool tips or a resizeable toolbar
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	CreatePropertyDialog();
	CreateElementListDialog();

	BOOL standardToolBarVisible = AfxGetApp()->GetProfileInt(_T("Settings"), _T("Standard ToolBar Visible"), TRUE);
	
	if (standardToolBarVisible) {
		m_wndToolBar.ShowWindow(SW_SHOW);
	}
	else {
		m_wndToolBar.ShowWindow(SW_HIDE);
	}

	BOOL statusBarVisible = AfxGetApp()->GetProfileInt(_T("Settings"), _T("Status Bar Visible"), TRUE);

	if (statusBarVisible) {
		m_wndStatusBar.ShowWindow(SW_SHOW);
	}
	else {
		m_wndStatusBar.ShowWindow(SW_HIDE);
	}
    
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CMDIFrameWnd::PreCreateWindow(cs);
}

BOOL CMainFrame::CreatePropertyDialog()
{
	m_pPropertyDlg.Create(CDynamicPropertyDlg::IDD, this);

	return TRUE;
}

BOOL CMainFrame::CreateElementListDialog()
{
	m_pElementListDlg.Create(CDynamicElementListDlg::IDD, this);

	return TRUE;
}

void CMainFrame::UpdatePropertyDialog(CObArray* pProps)
{
	m_pPropertyDlg.SetProperties(pProps);
	m_pPropertyDlg.EnableWindow(TRUE);
	delete pProps;
}

void CMainFrame::ClearPropertyDialog()
{
	if (m_pPropertyDlg)
	{
		m_pPropertyDlg.SetEntity(NULL);
		m_pPropertyDlg.EnableWindow(FALSE);
		// Optionally clear controls inside the dialog here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

afx_msg LRESULT CMainFrame::OnSelectionChanged(WPARAM wParam, LPARAM lParam)
{
	CObArray* pProps = reinterpret_cast<CObArray*>(lParam);

	UpdatePropertyDialog(pProps);

	return 0;
}

void CMainFrame::OnViewProperties()
{
	// Toggle visibility
	if (m_pPropertyDlg.IsWindowVisible())
		m_pPropertyDlg.Show(FALSE);
	else
		m_pPropertyDlg.Show(TRUE);
	
}

void CMainFrame::OnUpdateViewProperties(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_pPropertyDlg.IsWindowVisible() ? TRUE : FALSE);
}

void CMainFrame::OnViewElementlist()
{
	// Toggle visibility
	if (m_pElementListDlg.IsWindowVisible())
		m_pElementListDlg.Show(FALSE);
	else
		m_pElementListDlg.Show(TRUE);
}

void CMainFrame::OnUpdateViewElementlist(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_pElementListDlg.IsWindowVisible() ? TRUE : FALSE);
}

void CMainFrame::OnClose()
{
	if (m_wndToolBar.IsVisible()) {
		AfxGetApp()->WriteProfileInt(_T("Settings"), _T("Standard ToolBar Visible"), TRUE);
	}
	else {
		AfxGetApp()->WriteProfileInt(_T("Settings"), _T("Standard ToolBar Visible"), FALSE);
	}

	if (m_wndStatusBar.IsVisible()) {
		AfxGetApp()->WriteProfileInt(_T("Settings"), _T("Status Bar Visible"), TRUE);
	}
	else {
		AfxGetApp()->WriteProfileInt(_T("Settings"), _T("Status Bar Visible"), FALSE);
	}

	CMDIFrameWnd::OnClose();
}

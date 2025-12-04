/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "WinProMo.h"

#include "ChildFrm.h"
#include "MainFrm.h"
#include "WinProMoDoc.h"
#include "WinProMoView.h"
#include "../../WinProMo/src/Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CChildFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_WM_MDIACTIVATE()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
	m_pluginInterface = NULL;
	m_hDefaultMenu = ::LoadMenu(AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
	m_hAccel = NULL;

}

CChildFrame::~CChildFrame()
{
	
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CMDIChildWnd::PreCreateWindow(cs);
}

void CChildFrame::ActivateFrame(int nCmdShow)
{

	if (!m_pluginInterface) {
		CWinProMoApp* app = dynamic_cast<CWinProMoApp*>(AfxGetApp());
		CDocument* pDoc = GetActiveDocument();
		if (pDoc && app)
		{
			CWinProMoDoc* pMyDoc = dynamic_cast<CWinProMoDoc*>(pDoc);
			if (pMyDoc)
			{
				for (size_t i = 0; i < app->m_Extensions.GetSize(); ++i) {
					ExtensionDLL* plugin = dynamic_cast<ExtensionDLL*>(app->m_Extensions.GetAt(i));
					if (plugin) {
						if (plugin->docType == pMyDoc->GetData()->GetModelType()) {
							m_pluginInterface = plugin;
						}
					}
				}
			}
		}
	}

	CMDIChildWnd::ActivateFrame(nCmdShow);
}


void CChildFrame::CreateMenuEntry(CMenu* menu, CObArray* commandList, BOOL createTopMenus) {
	if (commandList) {
		for (int i = 0; i < commandList->GetSize(); i++) {
			CWinProMoPluginCommand* command = dynamic_cast<CWinProMoPluginCommand*>(commandList->GetAt(i));
			if (command) {
				if (command->m_subCommands) {
					CMenu* dynamicMenu = new CMenu;
					m_dynamicMenus.Add(dynamicMenu);
					dynamicMenu->CreatePopupMenu();
					CreateMenuEntry(dynamicMenu, command->m_subCommands, FALSE);
					menu->AppendMenu(MF_BYPOSITION | MF_POPUP, (UINT_PTR)dynamicMenu->m_hMenu, command->m_caption);
				}
				else {
					if (command->m_commandID == NULL) {
						menu->AppendMenu(MF_SEPARATOR, NULL, command->m_caption);
					}
					else {
						menu->AppendMenu(MF_STRING, command->m_commandID, command->m_caption);
					}
				}
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG


/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers

void CChildFrame::OnMDIActivate(BOOL bActivate, CWnd* pActivateWnd, CWnd* pDeactivateWnd)
{
	CMDIChildWnd::OnMDIActivate(bActivate, pActivateWnd, pDeactivateWnd);

	// TODO: Add your message handler code here
	CMainFrame* pMainFrame = (CMainFrame*)GetParentFrame();
	CMDIFrameWnd* pMDIFrame = DYNAMIC_DOWNCAST(CMDIFrameWnd, pMainFrame);
	CWinProMoApp* app = dynamic_cast<CWinProMoApp*>(AfxGetApp());

	if (bActivate) {
		// Trigger property dialog refresh
		CWinProMoView* view = dynamic_cast<CWinProMoView*>(GetActiveView());
		if (view) {
			view->GetEditor()->NotifySelectionChanged();
		}
		
		// Set the new menu in the MDI frame
		if (m_pluginInterface) {

			HINSTANCE hPlugin = m_pluginInterface->hModule;
			m_hAccel = ::LoadAccelerators(hPlugin, MAKEINTRESOURCE(IDR_WINPROTYPE));
			app->g_hCurrentAccel = m_hAccel;

			CMenu* pNewMenu = new CMenu;
			if (pNewMenu->LoadMenu(IDR_WINPROTYPE))
			{
				//Insert is at position 3, revise if it changes
				CMenu* pInsertMenu = pNewMenu->GetSubMenu(3);
				//Window is at position 5, revise if it changes
				CMenu* pWindowMenu = pNewMenu->GetSubMenu(5);
				m_dynamicMenus.Add(pNewMenu);

				if (pInsertMenu) {
					pInsertMenu->DeleteMenu(0, MF_BYPOSITION);
					CreateMenuEntry(pInsertMenu, m_pluginInterface->elements, FALSE);
				}

				if (pMDIFrame)
				{
					pMDIFrame->MDISetMenu(pNewMenu, pWindowMenu);
					pMDIFrame->DrawMenuBar();

				}
			}
			else
			{
				delete pNewMenu;
			}

		}

	}
	else {
		
		// Restore old menu
		for (int i = m_dynamicMenus.GetSize() - 1; i >= 0; i--) {
			CMenu* menu = dynamic_cast<CMenu*>(m_dynamicMenus.GetAt(i));
			if (menu->m_hMenu)
				menu->DestroyMenu();
			delete menu;
			m_dynamicMenus.RemoveAt(i);
		}
		if (pMDIFrame)
		{
			pMDIFrame->SetMenu(CMenu::FromHandle(m_hDefaultMenu));
			
		}

		app->g_hCurrentAccel = NULL;

		if (!AfxGetMainWnd()->IsWindowVisible())
			return;

		pMainFrame->UpdatePropertyDialog(NULL);

	}

}

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
#include "SelectDocumentTypeDlg.h"

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

BOOL CChildFrame::InitDocView()
{
	CWinProMoDoc* pDoc = (CWinProMoDoc*)GetActiveDocument();
	ASSERT_KINDOF(CWinProMoDoc, pDoc);

	CWinProMoView* pView = dynamic_cast<CWinProMoView*>(GetActiveView());

	if (pView && pDoc) {
		if (!pDoc->m_pluginReference) {
			CSelectDocumentTypeDlg dlg;
			if (dlg.DoModal() == IDOK) {
				CString selectedDocType = dlg.GetSelectedDocType();

				if (!pDoc->SelectPluginInterface(selectedDocType)) {
					AfxMessageBox(CString("Cannot create data container for " + selectedDocType + "."));
					return FALSE;
				}

				CWinProMoApp* pApp = (CWinProMoApp*)AfxGetApp();

				pDoc->SetClipboardHandler(&pApp->m_clip);

				pView->SetPageSizeFromPrinter();
				
			}
			else {
				return FALSE;
			}

		}

		pView->CreateCmdHandler();

		return TRUE;
	}
	return FALSE;
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

	if (bActivate) {

		CWinProMoDoc* pDoc = (CWinProMoDoc*)GetActiveDocument();
		ASSERT_KINDOF(CWinProMoDoc, pDoc);
		
		if (InitDocView()){
			
			// Locate the insert submenu
			CMenu* pInsertMenu = NULL;
			CMenu* pTopMenu = AfxGetMainWnd()->GetMenu();
			int iPos;
			for (iPos = pTopMenu->GetMenuItemCount() - 1; iPos >= 0; iPos--)
			{
				CMenu* pMenu = pTopMenu->GetSubMenu(iPos);
				if (pMenu && pMenu->GetMenuItemID(0) == ID_INSERT_)
				{
					pInsertMenu = pMenu;
					break;
				}
			}
			if (pInsertMenu != NULL) {
				// Update the insert submenu to reflect the options available for
				// the active document

				// First, delete all items
				for (iPos = pInsertMenu->GetMenuItemCount() - 1; iPos > 0; iPos--)
					pInsertMenu->DeleteMenu(iPos, MF_BYPOSITION);

				// Then, add a separator and an item for each available text color
				CreateMenuEntry(pInsertMenu, pDoc->m_pluginReference->elements, FALSE);

				// Set the icon specified by the plugin
				HICON hNew = NULL;
				hNew = AfxGetApp()->LoadIcon(pDoc->m_pluginReference->docID);
				if (hNew)
					SetIcon(hNew, TRUE);
			}
			return;
			
		}
		// User has canceled document creation, or something went wrong
		PostMessage(WM_CLOSE);

	}
	else {
		int i = 0;
		for (i = (int)m_dynamicMenus.GetSize() - 1; i >= 0; i--) {
			CMenu* menu = dynamic_cast<CMenu*>(m_dynamicMenus.GetAt(i));
			if (menu->m_hMenu)
				menu->DestroyMenu();
			delete menu;
			m_dynamicMenus.RemoveAt(i);
		}
	}

}

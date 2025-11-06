/* ==========================================================================

    Copyright © 2025 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#include "stdafx.h"
#include "DynamicPropertyDlg.h"
#include <errno.h>
#include "../../WinProMo/src/ProMoEditor/ProMoBlockView.h"
#include "../../WinProMo/src/ProMoEditor/ProMoEdgeView.h"
#include "../../WinProMo/src/ProMoEditor/ProMoBlockModel.h"
#include "../../WinProMo/src/ProMoEditor/ProMoEdgeModel.h"
#include "../../WinProMo/src/ProMoEditor/ProMoModel.h"
#include "../../WinProMo/src/ProMoEditor/ProMoProperty.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CDynamicPropertyDlg, CDiagramPropertyDlg)
ON_CONTROL_RANGE(EN_KILLFOCUS, 1000, 1099, OnPropertyControlChanged)
ON_CONTROL_RANGE(BN_CLICKED, 1000, 1099, OnPropertyControlChanged)
ON_CONTROL_RANGE(CBN_KILLFOCUS, 1000, 1099, OnPropertyControlChanged)
ON_WM_SIZE()
ON_WM_DESTROY()
END_MESSAGE_MAP()

CDynamicPropertyDlg::CDynamicPropertyDlg(CWnd* pParent)
    : CDiagramPropertyDlg(CDynamicPropertyDlg::IDD, pParent), m_nextCtrlID(1000) // Resource ID = 0, since we don’t use a template
{
    m_visible = FALSE;
}

CDynamicPropertyDlg::~CDynamicPropertyDlg()
{
    m_ScrollView.ClearControls();
	ClearProperties();
}

void CDynamicPropertyDlg::Show(BOOL visible)
{
    // Toggle visibility
    m_visible = visible;
    if (visible)
        ShowWindow(SW_SHOW);
    else
        ShowWindow(SW_HIDE);
}

void CDynamicPropertyDlg::ClearProperties()
{
    m_properties.RemoveAll();
    m_nextCtrlID = 1000;
}

void CDynamicPropertyDlg::SetProperties(CDiagramEntity* entity)
{
    ClearProperties();

    CProMoModel* pModel = NULL;


	CProMoBlockView* pBlockView = dynamic_cast<CProMoBlockView*>(entity);
    if (pBlockView) {
        pModel = dynamic_cast<CProMoModel*>(pBlockView->GetModel());
    }
    CProMoEdgeView* pEdgeView = dynamic_cast<CProMoEdgeView*>(entity);
    if (pEdgeView) {
        pModel = dynamic_cast<CProMoModel*>(pEdgeView->GetModel());
    }

    if (pModel) {
        for (int i = 0; i < pModel->GetPropertiesCount(); ++i)
        {
            CProMoProperty* prop = pModel->GetProperty(i);
            if (prop) {
                m_properties.Add(prop);
            }
		}
    }

    CWnd* pMainFrame = AfxGetMainWnd();
    if (pMainFrame && ::IsWindow(pMainFrame->GetSafeHwnd())) {
        pMainFrame->SetFocus();
    }
	RebuildControls();
}

void CDynamicPropertyDlg::SetValues() {
    return;
}

void CDynamicPropertyDlg::RebuildControls()
{
    m_ScrollView.ClearControls();

    for (int i = 0; i < m_properties.GetSize(); ++i)
    {
        CProMoProperty* pi = dynamic_cast<CProMoProperty*>(m_properties[i]);

        // Control ID
        UINT ctrlID = m_nextCtrlID++;
        
        // Create control based on type
        CWnd* ctrl = NULL;
        CString value;

        if (pi) {
            if (pi->HasHandler()) {
                ctrl = m_ScrollView.AddControl(ctrlID, pi->GetName(), RUNTIME_CLASS(CButton));
            }
            else {
                switch (pi->GetType())
                {
                case PROPTYPE_INT:
                case PROPTYPE_STRING:
                    if (pi->GetOptionsCount() > 0) {
                        ctrl = m_ScrollView.AddControl(ctrlID, pi->GetName(), RUNTIME_CLASS(CComboBox));
                        if (ctrl) {
                            CComboBox* box = dynamic_cast<CComboBox*>(ctrl);
                            for (int i = 0; i < pi->GetOptionsCount(); i++) {
                                box->AddString(pi->GetOption(i)->GetValue().GetString());
                            }
                        }
                    }
                    else {
                        ctrl = m_ScrollView.AddControl(ctrlID, pi->GetName(), RUNTIME_CLASS(CEdit));
                    }
                    ctrl->SetWindowText(pi->GetValue().GetString());
                    if (pi->GetType() == PROPTYPE_INT) {
                        ctrl->ModifyStyle(0, ES_NUMBER);
                    }
                    break;
                    // add other types here
                default:
                    break;
                }
            }
        }
    }

    Invalidate();
}

void CDynamicPropertyDlg::OnPropertyControlChanged(UINT ctrlID)
{
    int index = ctrlID - 1000;
    if (index >= 0 && index < m_properties.GetSize())
    {
        CProMoProperty* pItem = dynamic_cast<CProMoProperty*>(m_properties.GetAt(index));
        CWnd* ctl = m_ScrollView.GetControl(ctrlID);

        if (pItem && ctl)
        {
            if (pItem->HasHandler()) {
                //TODO: set correct handler
                BOOL result = pItem->InvokeHandler(NULL);
                if (!result) {
                    Invalidate();
				}
            }
            else {
                CString newVal;
                CVariantWrapper wrapper;
                ctl->GetWindowText(newVal);
                if (newVal != pItem->GetValue().GetString())
                {
                    switch (pItem->GetType())
                    {
                    case PROPTYPE_STRING:
                    {
                        wrapper.SetString(newVal);

                    }
                    break;
                    case PROPTYPE_INT:
                    {
                        wrapper.SetFromString(newVal, VT_I4);
                    }
                    default:
                        break;
                    }
                    BOOL result = pItem->SetValue(wrapper);
                    if (!result) {
                        ctl->SetWindowText(pItem->GetValue().GetString());
                        Invalidate();
                    }
                }

            }
        }
    }
    // Trigger redraw on the main editor window (stored in base class)
    Redraw();
	
    CView* pView = NULL;

    CFrameWnd* pMainFrame = (CFrameWnd*)AfxGetMainWnd();
    if (pMainFrame)
    {
        CMDIChildWnd* pChild = (CMDIChildWnd*)pMainFrame->GetActiveFrame();
        if (pChild)
            pView = pChild->GetActiveView();
    }

    if (pView && ::IsWindow(pView->GetSafeHwnd()))
    {
        pView->Invalidate();        // Marks the view as needing redraw
        pView->UpdateWindow();      // Immediately repaints
    }
}

BOOL CDynamicPropertyDlg::Create(UINT nIDTemplate, CWnd* pParentWnd)
{
    // Call base class to create the dialog window
    BOOL result = CDiagramPropertyDlg::Create(nIDTemplate, pParentWnd);
    if (!result)
        return FALSE;

    return TRUE;
}

BOOL CDynamicPropertyDlg::PreTranslateMessage(MSG* pMsg)
{
    if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
    {
        // Ignore Enter key to prevent dialog closing
        return TRUE; // Handled here
    }
    return CDiagramPropertyDlg::PreTranslateMessage(pMsg);
}

void CDynamicPropertyDlg::OnSize(UINT nType, int cx, int cy)
{
    CDiagramPropertyDlg::OnSize(nType, cx, cy);

    if (!::IsWindow(m_ScrollView.GetSafeHwnd()))
        return; // Avoid resizing if scroll view isn't created yet

    if (m_ScrollView.GetSafeHwnd())
    {
        m_ScrollView.MoveWindow(0, 0, cx, cy);
    }

}

BOOL CDynamicPropertyDlg::OnInitDialog()
{
    CDiagramPropertyDlg::OnInitDialog();

    int left = AfxGetApp()->GetProfileInt(_T("PropertyDialog"), _T("Left"), -1);
    int top = AfxGetApp()->GetProfileInt(_T("PropertyDialog"), _T("Top"), -1);
    int width = AfxGetApp()->GetProfileInt(_T("PropertyDialog"), _T("Width"), -1);
    int height = AfxGetApp()->GetProfileInt(_T("PropertyDialog"), _T("Height"), -1);

    if (left != -1 && top != -1 && width > 0 && height > 0)
    {
        CRect desired(left, top, left + width, top + height);

        // Optional: Clamp to virtual screen to avoid placing the dialog off-screen
        
		CRect virtualScreen;
        virtualScreen.left = GetSystemMetrics(SM_XVIRTUALSCREEN);
        virtualScreen.top = GetSystemMetrics(SM_YVIRTUALSCREEN);
        virtualScreen.right = virtualScreen.left + GetSystemMetrics(SM_CXVIRTUALSCREEN);
        virtualScreen.bottom = virtualScreen.top + GetSystemMetrics(SM_CYVIRTUALSCREEN);

        if (!virtualScreen.IsRectEmpty())
        {
            // Ensure dialog fits at least partially on screen
            if (desired.right > virtualScreen.right)
                desired.OffsetRect(virtualScreen.right - desired.right, 0);
            if (desired.bottom > virtualScreen.bottom)
                desired.OffsetRect(0, virtualScreen.bottom - desired.bottom);
            if (desired.left < virtualScreen.left)
                desired.OffsetRect(virtualScreen.left - desired.left, 0);
            if (desired.top < virtualScreen.top)
                desired.OffsetRect(0, virtualScreen.top - desired.top);
        }

        MoveWindow(desired);
    
    }

    CRect clientRect;
    GetClientRect(&clientRect);

    if (!m_ScrollView.Create(this, 1234, clientRect))
    {
        TRACE("Failed to create scroll view\n");
        return FALSE;
    }

    m_visible = AfxGetApp()->GetProfileInt(_T("PropertyDialog"), _T("Visible"), FALSE);
    if (m_visible) {
        ShowWindow(SW_SHOW);
    }
    else {
        ShowWindow(SW_HIDE);
    }

    return TRUE;
}

void CDynamicPropertyDlg::OnDestroy()
{

    if (m_visible)
        AfxGetApp()->WriteProfileInt(_T("PropertyDialog"), _T("Visible"), TRUE);
    else
        AfxGetApp()->WriteProfileInt(_T("PropertyDialog"), _T("Visible"), FALSE);
    
    CRect rect;
    GetWindowRect(&rect);

    AfxGetApp()->WriteProfileInt(_T("PropertyDialog"), _T("Left"), rect.left);
    AfxGetApp()->WriteProfileInt(_T("PropertyDialog"), _T("Top"), rect.top);
    AfxGetApp()->WriteProfileInt(_T("PropertyDialog"), _T("Width"), rect.Width());
    AfxGetApp()->WriteProfileInt(_T("PropertyDialog"), _T("Height"), rect.Height());

    CDiagramPropertyDlg::OnDestroy();

}
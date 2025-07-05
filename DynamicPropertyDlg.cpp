#include "stdafx.h"
#include "DynamicPropertyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "../WinProMo/ProMoEditor/PropertyItem.h"

BEGIN_MESSAGE_MAP(CDynamicPropertyDlg, CDiagramPropertyDlg)
ON_CONTROL_RANGE(EN_KILLFOCUS, 1000, 1099, OnPropertyControlChanged)
ON_WM_SIZE()
END_MESSAGE_MAP()

CDynamicPropertyDlg::CDynamicPropertyDlg(CWnd* pParent)
    : CDiagramPropertyDlg(CDynamicPropertyDlg::IDD, pParent), m_nextCtrlID(1000) // Resource ID = 0, since we don’t use a template
{
    
}

CDynamicPropertyDlg::~CDynamicPropertyDlg()
{
    m_ScrollView.ClearControls();
	ClearProperties();
}

void CDynamicPropertyDlg::ClearProperties()
{
    for (int i = 0; i < m_properties.GetSize(); ++i)
        delete (CPropertyItem*)m_properties[i];
    m_properties.RemoveAll();

    m_nextCtrlID = 1000;
}

void CDynamicPropertyDlg::SetProperties(CObArray* properties)
{

    ClearProperties();
    if (!properties)
        return;

    for (int i = 0; i < properties->GetSize(); ++i)
    {
        CPropertyItem* pi = (CPropertyItem*)properties->GetAt(i);
        m_properties.Add(pi);
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
        CPropertyItem* pi = (CPropertyItem*)m_properties[i];

        // Control ID
        UINT ctrlID = m_nextCtrlID++;
        pi->m_ctrlID = ctrlID;

        // Create control based on type
        CWnd* ctrl = NULL;

        ctrl = m_ScrollView.AddControl(ctrlID, pi->m_name, RUNTIME_CLASS(CEdit));
        ctrl->SetWindowText(pi->m_value);
    }

    Invalidate();
}

void CDynamicPropertyDlg::OnPropertyControlChanged(UINT ctrlID)
{
    int index = ctrlID - 1000;
    if (index >= 0 && index < m_properties.GetSize())
    {
        CPropertyItem* pItem = static_cast<CPropertyItem*>(m_properties.GetAt(index));
        CWnd* ctl = m_ScrollView.GetControl(ctrlID);

        if (pItem && ctl)
        {
            CString newVal;
            ctl->GetWindowText(newVal);

            if (newVal != pItem->m_value)
            {
                pItem->SetValue(newVal);
                
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

    CRect clientRect;
    GetClientRect(&clientRect);

    if (!m_ScrollView.Create(this, 1234, clientRect))
    {
        TRACE("Failed to create scroll view\n");
        return FALSE;
    }

    return TRUE;
}

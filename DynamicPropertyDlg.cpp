#include "stdafx.h"
#include "DynamicPropertyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CDynamicPropertyDlg, CDiagramPropertyDlg)
    ON_EN_CHANGE(1001, &CDynamicPropertyDlg::OnTextChanged)
END_MESSAGE_MAP()

CDynamicPropertyDlg::CDynamicPropertyDlg(CWnd* pParent)
    : CDiagramPropertyDlg(CDynamicPropertyDlg::IDD, pParent) // Resource ID = 0, since we don’t use a template
{
}

CDynamicPropertyDlg::~CDynamicPropertyDlg()
{
}

BOOL CDynamicPropertyDlg::Create(UINT nIDTemplate, CWnd* pParentWnd)
{
    // Call base class to create the dialog window
    BOOL result = CDiagramPropertyDlg::Create(nIDTemplate, pParentWnd);
    if (!result)
        return FALSE;

    // Now create your dynamic controls here
    BOOL ok = m_edit.Create(
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
        CRect(10, 10, 280, 30), this, 1001);
    ASSERT(ok);

    return TRUE;
}

void CDynamicPropertyDlg::SetValues()
{
    if (!::IsWindow(m_edit.GetSafeHwnd()))
        return; // or ASSERT(FALSE) for debugging
    
    CDiagramEntity* entity = GetEntity();
    if (entity)
    {
        CString title = entity->GetTitle();
        m_edit.SetWindowText(title);
    }
}

void CDynamicPropertyDlg::OnTextChanged()
{
    UpdateEntity();
}

void CDynamicPropertyDlg::UpdateEntity()
{
    CDiagramEntity* entity = GetEntity();
    if (entity)
    {
        CString newText;
        m_edit.GetWindowText(newText);
        entity->SetTitle(newText);
        Redraw();
    }
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

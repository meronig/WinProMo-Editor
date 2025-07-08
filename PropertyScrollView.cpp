#include "stdafx.h"
#include "PropertyScrollView.h"

BEGIN_MESSAGE_MAP(CPropertyScrollView, CWnd)
    ON_WM_VSCROLL()
    ON_WM_SIZE()
    ON_WM_CTLCOLOR()
    ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

CPropertyScrollView::CPropertyScrollView()
    : m_nTotalHeight(0), m_nScrollPos(0), m_nNextY(10)
{
    m_LabelWidth = 80;
    m_CtrlWidth = 150;
    m_CtrlHeight = 25;
    m_Spacing = 5;
    m_ComboBoxHeight = 200;
}

CPropertyScrollView::~CPropertyScrollView()
{
    ClearControls();
}

BOOL CPropertyScrollView::Create(CWnd* pParentWnd, UINT nID, const CRect& rect)
{
    
    LPCTSTR className = AfxRegisterWndClass(CS_VREDRAW | CS_HREDRAW, ::LoadCursor(NULL, IDC_ARROW), (HBRUSH)(COLOR_WINDOW + 1));
    
    BOOL ok = CWnd::CreateEx(
        0,
        className,
        _T(""),
        WS_CHILD | WS_VISIBLE | WS_VSCROLL,
        rect.left,
        rect.top,
        rect.Width(),
        rect.Height(),
        pParentWnd->GetSafeHwnd(),
        (HMENU)(UINT)nID,
        NULL
    );

    if (!ok) return FALSE;

    m_Frame.Create(className, _T(""), WS_CHILD | WS_VISIBLE, CRect(0, 0, rect.Width(), rect.Height()), this, 0);
	m_Frame.SetWindowPos(NULL, 0, 0, rect.Width(), rect.Height(), SWP_NOZORDER);
    
    CClientDC dc(this);
    CFont* pFont = GetParent()->GetFont();
    CFont* pOldFont = dc.SelectObject(pFont);

    TEXTMETRIC tm;
    dc.GetTextMetrics(&tm);

    dc.SelectObject(pOldFont);

    m_CtrlHeight = tm.tmHeight + tm.tmExternalLeading + 4;
    
    AdjustScrollBar();
    return TRUE;
}

CWnd* CPropertyScrollView::AddControl(UINT ctrlID, const CString& labelText, CRuntimeClass* pControlClass)
{
    if (!pControlClass || !pControlClass->IsDerivedFrom(RUNTIME_CLASS(CWnd)))
        return NULL;

    CFont* pFont = GetParent()->GetFont();
    CStatic* label = new CStatic();
    label->Create(labelText + _T(":"), WS_CHILD | WS_VISIBLE,
        CRect(10, m_nNextY, 10 + m_LabelWidth, m_nNextY + m_CtrlHeight), &m_Frame, 0);
    label->SetFont(pFont);

    CWnd* pControl = NULL;

    if (pControlClass == RUNTIME_CLASS(CEdit)) {
        CEdit* edit = new CEdit();
        if (!edit) 
        {
            delete label;
            return NULL;
        }
        if (!edit->Create(WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | WS_TABSTOP,
            CRect(10 + m_LabelWidth + m_Spacing, m_nNextY,
                10 + m_LabelWidth + m_Spacing + m_CtrlWidth,
                m_nNextY + m_CtrlHeight), &m_Frame, ctrlID)) 
        {
            delete pControl;
            delete label;
            return NULL;
        }
        pControl = edit;
    }
    else if (pControlClass == RUNTIME_CLASS(CComboBox)) {
        CComboBox* combo = new CComboBox();
        if (!combo)
        {
            delete label;
            return NULL;
        }
        if (!combo->Create(WS_CHILD | WS_VISIBLE | CBS_AUTOHSCROLL | WS_TABSTOP | CBS_DROPDOWN,
            CRect(10 + m_LabelWidth + m_Spacing, m_nNextY,
                10 + m_LabelWidth + m_Spacing + m_CtrlWidth,
                m_nNextY + m_CtrlHeight + m_ComboBoxHeight), &m_Frame, ctrlID))
        {
            delete pControl;
            delete label;
            return NULL;
        }
        pControl = combo;
    }
    else if (pControlClass == RUNTIME_CLASS(CButton)) {
        CButton* btn = new CButton();
        if (!btn)
        {
            delete label;
            return NULL;
        }
        if (!btn->Create(_T("Set..."), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP,
            CRect(10 + m_LabelWidth + m_Spacing, m_nNextY,
                10 + m_LabelWidth + m_Spacing + m_CtrlWidth,
                m_nNextY + m_CtrlHeight), &m_Frame, ctrlID))
        {
            delete pControl;
            delete label;
            return NULL;
        }
        pControl = btn;
    }
    else if (pControlClass && pControlClass->IsDerivedFrom(RUNTIME_CLASS(CWnd))) {
        pControl = (CWnd*)pControlClass->CreateObject();
        if (!pControl)
        {
            delete label;
            return NULL;
        }
        if (!pControl->Create(NULL, NULL, WS_CHILD | WS_VISIBLE | WS_TABSTOP,
            CRect(10 + m_LabelWidth + m_Spacing, m_nNextY,
                10 + m_LabelWidth + m_Spacing + m_CtrlWidth,
                m_nNextY + m_CtrlHeight),
            &m_Frame, ctrlID))
        {
            delete pControl;
            delete label;
            return NULL;
        }
    }

    pControl->ModifyStyleEx(0, WS_EX_CLIENTEDGE, SWP_FRAMECHANGED);
    pControl->SetFont(pFont);

    m_Labels.Add(label);
    m_Controls.Add(pControl);
    
    m_nNextY += m_CtrlHeight + m_Spacing;
    m_nTotalHeight = m_nNextY + 10;

    AdjustScrollBar();
    UpdateLayout();

    return pControl;
}

void CPropertyScrollView::ClearControls()
{
    int i;
	for (i = 0; i < m_Labels.GetSize(); ++i)
    {
        if (m_Labels[i])
        {
            m_Labels[i]->DestroyWindow();
            delete m_Labels[i];
        }
    }
    m_Labels.RemoveAll();

    for (i = 0; i < m_Controls.GetSize(); ++i)
    {
        if (m_Controls[i])
        {
            m_Controls[i]->DestroyWindow();
            delete m_Controls[i];
        }
    }
    m_Controls.RemoveAll();

    m_nScrollPos = 0;
    m_nNextY = 10;
    m_nTotalHeight = 0;
    AdjustScrollBar();
}

CWnd* CPropertyScrollView::GetControl(UINT ctrlID) const
{
    for (int i = 0; i < m_Controls.GetSize(); ++i)
    {
        if (m_Controls[i] && m_Controls[i]->GetDlgCtrlID() == (int)ctrlID)
            return m_Controls[i];
    }
    return NULL;
}

void CPropertyScrollView::AdjustScrollBar()
{
    if (!::IsWindow(m_Frame.GetSafeHwnd()))
        return;
    
    //fails when exiting
	CRect clientRect;
    GetClientRect(&clientRect);

    int pageSize = clientRect.Height();

    int maxScroll = max(0, m_nTotalHeight - pageSize);

    // Clamp m_nScrollPos within valid range after resize
    if (m_nScrollPos > maxScroll)
        m_nScrollPos = maxScroll;

    SCROLLINFO si = { sizeof(si) };
    si.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
    si.nMin = 0;
    si.nMax = max(0, m_nTotalHeight - 1);
    si.nPage = pageSize;
    si.nPos = m_nScrollPos;

    SetScrollInfo(SB_VERT, &si, TRUE);
    UpdateLayout();
}

void CPropertyScrollView::UpdateLayout()
{
    CRect clientRect;
    GetClientRect(&clientRect);
    m_Frame.MoveWindow(0, -m_nScrollPos, clientRect.Width(), m_nTotalHeight);

    int ctrlX = 10 + m_LabelWidth + m_Spacing;
    int ctrlWidth = max(50, clientRect.Width() - ctrlX - 10);

    for (int i = 0; i < m_Controls.GetSize(); ++i)
    {
        CWnd* pCtrl = m_Controls[i];
        if (!pCtrl)
            continue;

        // Skip labels — assuming labels stored separately or filtered
        if (pCtrl->IsKindOf(RUNTIME_CLASS(CStatic)))
            continue;

        CRect rect;
        pCtrl->GetWindowRect(&rect);
        m_Frame.ScreenToClient(&rect);

        // Reposition control width and X but keep Y
        pCtrl->MoveWindow(ctrlX, rect.top, ctrlWidth, rect.Height());
    }
}

void CPropertyScrollView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    CRect clientRect;
    GetClientRect(&clientRect);

    int pageSize = clientRect.Height();
    int maxScroll = max(0, m_nTotalHeight - pageSize);

    switch (nSBCode)
    {
    case SB_LINEUP:
        m_nScrollPos = max(0, m_nScrollPos - 10);
        break;
    case SB_LINEDOWN:
        m_nScrollPos = min(maxScroll, m_nScrollPos + 10);
        break;
    case SB_PAGEUP:
        m_nScrollPos = max(0, m_nScrollPos - pageSize);
        break;
    case SB_PAGEDOWN:
        m_nScrollPos = min(maxScroll, m_nScrollPos + pageSize);
        break;
    case SB_THUMBTRACK:
        m_nScrollPos = min(maxScroll, max(0, nPos));
        break;
    default:
        return;
    }

    SetScrollPos(SB_VERT, m_nScrollPos);
    UpdateLayout();
}

void CPropertyScrollView::OnSize(UINT nType, int cx, int cy)
{
    CWnd::OnSize(nType, cx, cy);

    AdjustScrollBar();
}

BOOL CPropertyScrollView::OnCommand(WPARAM wParam, LPARAM lParam)
{
    UINT notificationCode = HIWORD(wParam);
    UINT controlID = LOWORD(wParam);
	CWnd* pParent = GetParent();

    switch (notificationCode)
    {
    case EN_KILLFOCUS:
    case CBN_KILLFOCUS:
    case BN_CLICKED:
        if (pParent)
            return pParent->SendMessage(WM_COMMAND, wParam, lParam);
        break;
    }

    return CWnd::OnCommand(wParam, lParam);
}

BOOL CPropertyScrollView::PreTranslateMessage(MSG* pMsg)
{
    if (pMsg->message == WM_KEYDOWN && (pMsg->wParam == VK_TAB))
    {
        BOOL bShift = (GetKeyState(VK_SHIFT) & 0x8000) != 0;
        CWnd* pFocus = GetFocus();
        
        const int count = m_Controls.GetSize();
        if (count == 0)
            return FALSE;

        int currentIndex = -1;
        for (int i = 0; i < count; ++i)
        {
            if (m_Controls[i] == pFocus)
            {
                currentIndex = i;
                break;
            }
        }

        int nextIndex;
        if (currentIndex == -1)
        {
            nextIndex = 0;
        }
        else if (bShift)
        {
            nextIndex = (currentIndex == 0) ? count - 1 : currentIndex - 1;
        }
        else
        {
            nextIndex = (currentIndex == count - 1) ? 0 : currentIndex + 1;
        }

        m_Controls[nextIndex]->SetFocus();
        return TRUE;
    }

    return CWnd::PreTranslateMessage(pMsg);
}

HBRUSH CPropertyScrollView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    if (pWnd == &m_Frame)
    {
        pDC->SetBkColor(::GetSysColor(COLOR_3DFACE));
        return (HBRUSH)(::GetSysColorBrush(COLOR_3DFACE));
    }

    return CWnd::OnCtlColor(pDC, pWnd, nCtlColor);
}

BOOL CPropertyScrollView::OnEraseBkgnd(CDC* pDC)
{
    CRect rect;
    GetClientRect(&rect);

    pDC->FillSolidRect(&rect, ::GetSysColor(COLOR_3DFACE));
    return TRUE;
}

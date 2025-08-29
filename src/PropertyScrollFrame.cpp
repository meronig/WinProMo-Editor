/* ==========================================================================

    Copyright © 2025 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#include "stdafx.h"
#include "PropertyScrollFrame.h"

BEGIN_MESSAGE_MAP(CPropertyScrollFrame, CWnd)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

BOOL CPropertyScrollFrame::OnCommand(WPARAM wParam, LPARAM lParam)
{
    CWnd* pParent = GetParent();
    if (pParent)
        return pParent->SendMessage(WM_COMMAND, wParam, lParam);
    return FALSE;
}

HBRUSH CPropertyScrollFrame::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    switch (nCtlColor)
    {
    case CTLCOLOR_EDIT:
        // Default white background for edit controls
        pDC->SetBkColor(::GetSysColor(COLOR_WINDOW));
        pDC->SetTextColor(::GetSysColor(COLOR_WINDOWTEXT));
        return (HBRUSH)::GetSysColorBrush(COLOR_WINDOW);

    case CTLCOLOR_STATIC:
        // Match dialog background for static text
        pDC->SetBkColor(::GetSysColor(COLOR_3DFACE));
        return (HBRUSH)::GetSysColorBrush(COLOR_3DFACE);

    default:
        // Use default dialog background
        pDC->SetBkColor(::GetSysColor(COLOR_3DFACE));
        return (HBRUSH)::GetSysColorBrush(COLOR_3DFACE);
    }
}

BOOL CPropertyScrollFrame::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	pDC->FillSolidRect(&rect, ::GetSysColor(COLOR_3DFACE));
	return TRUE;
}

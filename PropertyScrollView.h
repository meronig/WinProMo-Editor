// CPropertyScrollView.h
#include "PropertyScrollFrame.h"
#ifndef _PROPERTYSCROLLVIEW_H_
#define _PROPERTYSCROLLVIEW_H_

class CPropertyScrollView : public CWnd
{
public:
    CPropertyScrollView();
    virtual ~CPropertyScrollView();

    BOOL Create(CWnd* pParentWnd, UINT nID, const CRect& rect);

    CWnd* AddControl(UINT ctrlID, const CString& labelText, CRuntimeClass* pControlClass);
    void ClearControls();
    CWnd* GetControl(UINT ctrlID) const;

protected:
    afx_msg BOOL OnCommand(WPARAM wParam, LPARAM lParam);
    afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg void OnSize(UINT nType, int cx, int cy);

    DECLARE_MESSAGE_MAP()

    void AdjustScrollBar();
    void UpdateLayout();

private:
    CPropertyScrollFrame m_Frame; // Scrollable content holder
    CArray<CStatic*, CStatic*> m_Labels;
    CArray<CWnd*, CWnd*> m_Controls;

    int m_nTotalHeight;
    int m_nScrollPos;
    int m_nNextY;
    int m_LabelWidth;
    int m_CtrlWidth;
    int m_CtrlHeight;
    int m_Spacing;

public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#endif //_PROPERTYSCROLLVIEW_H_
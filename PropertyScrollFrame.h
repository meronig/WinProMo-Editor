/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _PROPERTYSCROLLFRAME_H_
#define _PROPERTYSCROLLFRAME_H_

class CPropertyScrollFrame : public CWnd
{
	afx_msg BOOL OnCommand(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#endif // _PROPERTYSCROLLFRAME_H_


/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
/////////////////////////////////////////////////////////////////////////////
// CGridSizeDialog dialog
#ifndef _GRIDSIZEDIALOG_H_
#define _GRIDSIZEDIALOG_H_

#include "resource.h"

class CGridSizeDialog : public CDialog
{
// Construction
public:
	CGridSizeDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGridSizeDialog)
	enum { IDD = IDD_DIALOG_GRID_SIZE };
	int		m_height;
	int		m_width;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGridSizeDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGridSizeDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif _GRIDSIZEDIALOG_H_

#include "resource.h"
#ifndef _CANVASSIZEDIALOG_H_
#define _CANVASSIZEDIALOG_H_

/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
// CCanvasSizeDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCanvasSizeDialog dialog

class CCanvasSizeDialog : public CDialog
{
// Construction
public:
	CCanvasSizeDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCanvasSizeDialog)
	enum { IDD = IDD_DIALOG_CANVAS_SIZE };
	int		m_width;
	int		m_height;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCanvasSizeDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCanvasSizeDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // _CANVASSIZEDIALOG_H_

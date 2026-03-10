/* ==========================================================================

	Copyright © 2026 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
// ProMoDiagramAuto.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProMoDiagramAuto command target
#ifndef _PROMODIAGRAMAUTO_H_
#define _PROMODIAGRAMAUTO_H_

#include "../../../WinProMo/src/Automation/ProMoDiagramAutoAbs.h"
#include "../WinProMoDoc.h"

class CProMoDiagramAuto : public CProMoDiagramAutoAbs
{
	DECLARE_DYNCREATE(CProMoDiagramAuto)

	CProMoDiagramAuto();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProMoDiagramAuto)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual CProMoEntityContainer* GetContainer();

	virtual void RefreshWindow();

protected:
	virtual ~CProMoDiagramAuto();

	virtual CWinProMoDoc* GetDocument();

	virtual void SaveDiagramAs(const CString& fileName);
	virtual void SaveDiagram(BOOL noPrompt);
	virtual void CloseDiagram();

	// Generated message map functions
	//{{AFX_MSG(CProMoDiagramAuto)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
public:
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CProMoDiagramAuto)
	afx_msg void ClosePrintPreview();
	afx_msg void PrintPreview();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

};

#endif //_PROMODIAGRAMAUTO_H_
/////////////////////////////////////////////////////////////////////////////

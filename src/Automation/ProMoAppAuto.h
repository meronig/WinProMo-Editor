/* ==========================================================================

	Copyright © 2026 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
// ProMoAppAuto.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProMoAppAuto command target
#ifndef _PROMOAPPAUTO_H_
#define _PROMOAPPAUTO_H_

#include "../../../WinProMo/src/Automation/ProMoAppAutoAbs.h"

class CProMoAppAuto : public CProMoAppAutoAbs
{
	DECLARE_DYNCREATE(CProMoAppAuto)

	CProMoAppAuto();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProMoAppAuto)
	public:
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CProMoAppAuto();

	// Generated message map functions
	//{{AFX_MSG(CProMoAppAuto)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CProMoAppAuto)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CProMoAppAuto)
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	virtual void GetRegisteredDiagrams(CStringArray& diagramTypes);
	virtual CProMoDiagramsAutoAbs* CreateDiagramsAutoObject();
	virtual CProMoDiagramAutoAbs* GetActiveDiagram();

};

#endif //_PROMOAPPAUTO_H_
/////////////////////////////////////////////////////////////////////////////

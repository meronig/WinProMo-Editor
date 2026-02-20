/* ==========================================================================

	Copyright © 2026 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
// ProMoDiagramsAuto.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProMoDiagramsAuto command target
#ifndef _PROMODIAGRAMSAUTO_H_
#define _PROMODIAGRAMSAUTO_H_

#include "ProMoDiagramAuto.h"
#include "../../../WinProMo/src/Automation/ProMoDiagramsAutoAbs.h"

class CProMoDiagramsAuto : public CProMoDiagramsAutoAbs
{
	DECLARE_DYNCREATE(CProMoDiagramsAuto)

	CProMoDiagramsAuto();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
protected:
	virtual CProMoDiagramAutoAbs* GetDiagramAutoObject(CDocument* pDoc);


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProMoDiagramsAuto)
	public:
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CProMoDiagramsAuto();

	
	virtual int GetOpenDiagramsCount();
	virtual CProMoDiagramAutoAbs* GetDiagramAutoObject(int index);
	virtual CProMoDiagramAutoAbs* GetDiagramAutoObject(const CString& name);
	virtual CProMoDiagramAutoAbs* AddNewDiagram(const CString& type);
	virtual CProMoDiagramAutoAbs* OpenDiagram(const CString& fileName);
	virtual void GetOpenDiagrams(CStringArray& diagramList);


	// Generated message map functions
	//{{AFX_MSG(CProMoDiagramsAuto)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CProMoDiagramsAuto)
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

#endif //_PROMODIAGRAMSAUTO_H_
/////////////////////////////////////////////////////////////////////////////

/* ==========================================================================

	Copyright © 2026 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/

#include "stdafx.h"
#include "..\WinProMo.h"
#include "ProMoAppAuto.h"
#include "ProMoDiagramsAuto.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProMoAppAuto

IMPLEMENT_DYNCREATE(CProMoAppAuto, CProMoAppAutoAbs)

CProMoAppAuto::CProMoAppAuto()
{

}

void CProMoAppAuto::GetRegisteredDiagrams(CStringArray& diagramTypes)
{
	diagramTypes.RemoveAll();
	
	CObArray* exts = &((CWinProMoApp*)AfxGetApp())->m_Extensions;

	for (int i = 0; i < exts->GetSize(); ++i)
	{
		ExtensionDLL* pExt = (ExtensionDLL*)exts->GetAt(i);
		if (pExt)
		{
			diagramTypes.Add(pExt->docType);
		}
	}
}

CProMoDiagramsAutoAbs* CProMoAppAuto::CreateDiagramsAutoObject()
{
	return new CProMoDiagramsAuto();
}

CProMoDiagramAutoAbs* CProMoAppAuto::GetActiveDiagram()
{
	// TODO: implement this method
	return NULL;
}

CProMoAppAuto::~CProMoAppAuto()
{

}


BEGIN_MESSAGE_MAP(CProMoAppAuto, CProMoAppAutoAbs)
	//{{AFX_MSG_MAP(CProMoAppAuto)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CProMoAppAuto, CProMoAppAutoAbs)
	//{{AFX_DISPATCH_MAP(CProMoAppAuto)
	DISP_PROPERTY_EX(CProMoAppAuto, "Diagrams", GetDiagrams, SetDiagrams, VT_DISPATCH)
	DISP_PROPERTY_EX(CProMoAppAuto, "CreatableDiagramTypes", GetCreatableDiagramTypes, SetCreatableDiagramTypes, VT_VARIANT)
	DISP_FUNCTION(CProMoAppAuto, "ActiveDocument", ActiveDiagram, VT_DISPATCH, VTS_NONE)
	DISP_FUNCTION(CProMoAppAuto, "Quit", Quit, VT_EMPTY, VTS_BOOL)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IWinProMoAuto to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {358D4990-FD35-11F0-9740-000C2976A615}
static const IID IID_IWinProMoAuto =
{ 0x358d4990, 0xfd35, 0x11f0, { 0x97, 0x40, 0x0, 0xc, 0x29, 0x76, 0xa6, 0x15 } };

BEGIN_INTERFACE_MAP(CProMoAppAuto, CProMoAppAutoAbs)
	INTERFACE_PART(CProMoAppAuto, IID_IWinProMoAuto, Dispatch)
END_INTERFACE_MAP()

// {458D4990-FD35-11F0-9740-000C2976A615}
IMPLEMENT_OLECREATE(CProMoAppAuto, "WinProMo.Application", 0x458d4990, 0xfd35, 0x11f0, 0x97, 0x40, 0x0, 0xc, 0x29, 0x76, 0xa6, 0x15)

/////////////////////////////////////////////////////////////////////////////
// CWinProMoAuto message handlers



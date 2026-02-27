/* ==========================================================================

	Copyright © 2026 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/

#include "stdafx.h"
#include "..\WinProMo.h"
#include "ProMoDiagramAuto.h"
#include "..\WinProMoDoc.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProMoDiagramAuto

IMPLEMENT_DYNCREATE(CProMoDiagramAuto, CProMoDiagramAutoAbs)

CProMoDiagramAuto::CProMoDiagramAuto()
{
}

CProMoDiagramAuto::~CProMoDiagramAuto()
{
}

CWinProMoDoc* CProMoDiagramAuto::GetDocument()
{
	CWinProMoDoc* pDoc = dynamic_cast<CWinProMoDoc*>(m_pInternalObject);
	return pDoc;
}

CProMoEntityContainer* CProMoDiagramAuto::GetContainer() 
{
	ThrowIfDetached();
	
	if (GetDocument()) {
		return GetDocument()->GetData();
	}
	return NULL;
}

void CProMoDiagramAuto::RefreshWindow()
{
	if (GetDocument()) {
		GetDocument()->UpdateAllViews(NULL);
	}	
}

void CProMoDiagramAuto::SaveDiagramAs(CString fileName)
{
	if (GetDocument()) {
		GetDocument()->OnSaveDocument(fileName);
	}
}

void CProMoDiagramAuto::CloseDiagram()
{
	if (GetDocument()) {
		GetDocument()->OnCloseDocument();
	}

}

void CProMoDiagramAuto::SaveDiagram()
{
	if (GetDocument()) {
		GetDocument()->OnSaveDocument(GetDocument()->GetPathName());
	}
}

BEGIN_MESSAGE_MAP(CProMoDiagramAuto, CProMoDiagramAutoAbs)
	//{{AFX_MSG_MAP(CProMoDiagramAuto)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CProMoDiagramAuto, CProMoDiagramAutoAbs)
	//{{AFX_DISPATCH_MAP(CProMoDiagramAuto)
	DISP_PROPERTY_EX(CProMoDiagramAutoAbs, "Elements", GetElements, SetElements, VT_DISPATCH)
	DISP_PROPERTY_EX(CProMoDiagramAutoAbs, "Width", GetWidth, SetWidth, VT_I4)
	DISP_PROPERTY_EX(CProMoDiagramAutoAbs, "Height", GetHeight, SetHeight, VT_I4)
	DISP_PROPERTY_EX(CProMoDiagramAutoAbs, "Labels", GetLabels, SetLabels, VT_DISPATCH)
	DISP_PROPERTY_EX(CProMoDiagramAutoAbs, "CreatableElementTypes", GetCreatableElementTypes, SetCreatableElementTypes, VT_VARIANT)
	DISP_FUNCTION(CProMoDiagramAutoAbs, "SaveAs", SaveAs, VT_EMPTY, VTS_VARIANT)
	DISP_FUNCTION(CProMoDiagramAutoAbs, "Activate", Activate, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CProMoDiagramAutoAbs, "Close", Close, VT_EMPTY, VTS_BOOL)
	DISP_FUNCTION(CProMoDiagramAutoAbs, "Undo", Undo, VT_EMPTY, VTS_I2)
	DISP_FUNCTION(CProMoDiagramAutoAbs, "Redo", Redo, VT_EMPTY, VTS_I2)
	DISP_FUNCTION(CProMoDiagramAutoAbs, "Save", Save, VT_EMPTY, VTS_BOOL)
	DISP_FUNCTION(CProMoDiagramAutoAbs, "Path", Path, VT_BSTR, VTS_NONE)
	DISP_FUNCTION(CProMoDiagramAutoAbs, "Type", Type, VT_BSTR, VTS_NONE)
	DISP_FUNCTION(CProMoDiagramAuto, "PrintPreview", PrintPreview, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CProMoDiagramAuto, "ClosePrintPreview", ClosePrintPreview, VT_EMPTY, VTS_NONE)
	// Common to CProMoAppChildAuto
	DISP_FUNCTION(CProMoAppChildAuto, "Application", Application, VT_DISPATCH, VTS_NONE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IProMoDiagramAuto to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {358D4991-FD35-11F0-9740-000C2976A615}
static const IID IID_IWinProMo =
{ 0x358d4991, 0xfd35, 0x11f0, { 0x97, 0x40, 0x0, 0xc, 0x29, 0x76, 0xa6, 0x15 } };

BEGIN_INTERFACE_MAP(CProMoDiagramAuto, CProMoDiagramAutoAbs)
	INTERFACE_PART(CProMoDiagramAuto, IID_IWinProMo, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProMoDiagramAuto message handlers

void CProMoDiagramAuto::ClosePrintPreview() 
{
	// TODO: Add your dispatch handler code here

}

void CProMoDiagramAuto::PrintPreview() 
{
	// TODO: Add your dispatch handler code here

}


/* ==========================================================================

	Copyright © 2026 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/

#include "stdafx.h"
#include "..\WinProMo.h"
#include "ProMoDiagramsAuto.h"
#include "../../../WinProMo/src/Automation/ProMoDiagramsAutoAbs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProMoDiagramsAuto

IMPLEMENT_DYNCREATE(CProMoDiagramsAuto, CProMoDiagramsAutoAbs)

CProMoDiagramsAuto::CProMoDiagramsAuto()
{
}

CProMoDiagramsAuto::~CProMoDiagramsAuto()
{
}

CProMoDiagramAutoAbs* CProMoDiagramsAuto::GetDiagramAutoObject(CDocument* pDoc)
{
	IProMoAutomationHost* pHost = dynamic_cast<IProMoAutomationHost*>(pDoc);
	if (pHost) {
		return dynamic_cast<CProMoDiagramAutoAbs*>(pHost->GetAutomationObject());
	}

	return NULL;
}


int CProMoDiagramsAuto::GetOpenDiagramsCount()
{
	CWinProMoApp* pApp = (CWinProMoApp*)AfxGetApp();
	ASSERT(pApp);
	ASSERT(pApp->m_docTemplate);

	POSITION posDoc = pApp->m_docTemplate->GetFirstDocPosition();
	short nCount = 0;
	while (posDoc)
	{
		CDocument* pDoc = pApp->m_docTemplate->GetNextDoc(posDoc);
		ASSERT(pDoc);
		nCount++;
	}

	return nCount;
}

CProMoDiagramAutoAbs* CProMoDiagramsAuto::GetDiagramAutoObject(int index)
{
	CWinProMoApp* pApp = (CWinProMoApp*)AfxGetApp();
	ASSERT(pApp);
	ASSERT(pApp->m_docTemplate);
	POSITION posDoc = pApp->m_docTemplate->GetFirstDocPosition();
	short nCount = 0;
	CProMoAppChildAuto* pDiagramAuto = NULL;
	while (posDoc)
	{
		CDocument* pDoc = pApp->m_docTemplate->GetNextDoc(posDoc);
		CProMoDiagramAutoAbs* pAutoObj = GetDiagramAutoObject(pDoc);
		if (pAutoObj) {

			if (nCount == index) {
				return pAutoObj;
				
			}
		}
		nCount++;
	}
	return NULL;
}

CProMoDiagramAutoAbs* CProMoDiagramsAuto::GetDiagramAutoObject(const CString& name)
{
	CWinProMoApp* pApp = (CWinProMoApp*)AfxGetApp();
	ASSERT(pApp);
	ASSERT(pApp->m_docTemplate);
	POSITION posDoc = pApp->m_docTemplate->GetFirstDocPosition();
	CProMoAppChildAuto* pDiagramAuto = NULL;
	while (posDoc)
	{
		CDocument* pDoc = pApp->m_docTemplate->GetNextDoc(posDoc);
		CProMoDiagramAutoAbs* pAutoObj = GetDiagramAutoObject(pDoc);
		if (pAutoObj) {

			if (pDoc->GetTitle() == name) {
				return pAutoObj;

			}
		}
	}
	return NULL;
}

CProMoDiagramAutoAbs* CProMoDiagramsAuto::AddNewDiagram(const CString& type)
{
	CDocument* pDoc = ((CWinProMoApp*)AfxGetApp())->m_docTemplate->OpenDocumentFile(NULL, TRUE, type);
	return GetDiagramAutoObject(pDoc);
}

CProMoDiagramAutoAbs* CProMoDiagramsAuto::OpenDiagram(const CString& fileName)
{
	CDocument* pDoc = ((CWinProMoApp*)AfxGetApp())->m_docTemplate->OpenDocumentFile(fileName);
	return GetDiagramAutoObject(pDoc);
}

void CProMoDiagramsAuto::GetOpenDiagrams(CStringArray& diagramList)
{
	CWinProMoApp* pApp = (CWinProMoApp*)AfxGetApp();
	ASSERT(pApp);
	ASSERT(pApp->m_docTemplate);
	POSITION posDoc = pApp->m_docTemplate->GetFirstDocPosition();
	while (posDoc)
	{
		CDocument* pDoc = pApp->m_docTemplate->GetNextDoc(posDoc);
		diagramList.Add(pDoc->GetTitle());
	}
}


BEGIN_MESSAGE_MAP(CProMoDiagramsAuto, CProMoDiagramsAutoAbs)
	//{{AFX_MSG_MAP(CProMoDiagramsAuto)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CProMoDiagramsAuto, CProMoDiagramsAutoAbs)
	//{{AFX_DISPATCH_MAP(CProMoDiagramsAuto)
	DISP_PROPERTY_EX(CProMoDiagramsAutoAbs, "IDs", GetIDs, SetIDs, VT_VARIANT)
	DISP_FUNCTION(CProMoDiagramsAutoAbs, "Count", Count, VT_I2, VTS_NONE)
	DISP_FUNCTION(CProMoDiagramsAutoAbs, "Add", Add, VT_DISPATCH, VTS_VARIANT)
	DISP_FUNCTION(CProMoDiagramsAutoAbs, "Open", Open, VT_DISPATCH, VTS_VARIANT)
	DISP_FUNCTION(CProMoDiagramsAutoAbs, "Save", Save, VT_EMPTY, VTS_BOOL)
	DISP_FUNCTION(CProMoDiagramsAutoAbs, "Close", Close, VT_EMPTY, VTS_BOOL)
	// Common to CProMoAppChildAuto
	DISP_FUNCTION(CProMoAppChildAuto, "Application", Application, VT_DISPATCH, VTS_NONE)
	DISP_PROPERTY_PARAM_ID(CProMoDiagramsAutoAbs, "Item", 0, GetItem, SetItem, VT_DISPATCH, VTS_VARIANT)
	DISP_DEFVALUE(CProMoDiagramsAutoAbs, "Item")

	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IProMoDiagramsAuto to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {358D4992-FD35-11F0-9740-000C2976A615}
static const IID IID_IProMoDiagramsAuto =
{ 0x358d4992, 0xfd35, 0x11f0, { 0x97, 0x40, 0x0, 0xc, 0x29, 0x76, 0xa6, 0x15 } };

BEGIN_INTERFACE_MAP(CProMoDiagramsAuto, CProMoDiagramsAutoAbs)
	INTERFACE_PART(CProMoDiagramsAuto, IID_IProMoDiagramsAuto, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProMoDiagramsAuto message handlers


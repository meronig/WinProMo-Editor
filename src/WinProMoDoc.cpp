/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/

#include "stdafx.h"
#include "WinProMoDoc.h"
#include "WinProMoView.h"
#include "../../WinProMo/src/FileUtils/FileSerializer.h"
#include "WinProMo.h"
#include "../../WinProMo/src/FileUtils/FileParser.h"
#include "OleSrvItem.h"
#include "Automation/ProMoDiagramAuto.h"
#include <windows.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWinProMoDoc

IMPLEMENT_DYNCREATE(CWinProMoDoc, COleServerDoc)

BEGIN_MESSAGE_MAP(CWinProMoDoc, COleServerDoc)
	//{{AFX_MSG_MAP(CWinProMoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CWinProMoDoc, COleServerDoc)
	//{{AFX_DISPATCH_MAP(CWinProMoDoc)
	DISP_PROPERTY_EX(CWinProMoDoc, "Elements", GetElements, SetElements, VT_DISPATCH)
	DISP_PROPERTY_EX(CWinProMoDoc, "Width", GetWidth, SetWidth, VT_I4)
	DISP_PROPERTY_EX(CWinProMoDoc, "Height", GetHeight, SetHeight, VT_I4)
	DISP_PROPERTY_EX(CWinProMoDoc, "Labels", GetLabels, SetLabels, VT_DISPATCH)
	DISP_PROPERTY_EX(CWinProMoDoc, "CreatableElementTypes", GetCreatableElementTypes, SetCreatableElementTypes, VT_VARIANT)
	DISP_FUNCTION(CWinProMoDoc, "SaveAs", SaveAs, VT_EMPTY, VTS_VARIANT)
	DISP_FUNCTION(CWinProMoDoc, "Activate", Activate, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CWinProMoDoc, "Close", Close, VT_EMPTY, VTS_BOOL)
	DISP_FUNCTION(CWinProMoDoc, "Redo", Redo, VT_EMPTY, VTS_I2)
	DISP_FUNCTION(CWinProMoDoc, "Save", Save, VT_EMPTY, VTS_BOOL)
	DISP_FUNCTION(CWinProMoDoc, "Undo", Undo, VT_EMPTY, VTS_BOOL)
	DISP_FUNCTION(CWinProMoDoc, "Path", Path, VT_BSTR, VTS_NONE)
	DISP_FUNCTION(CWinProMoDoc, "Type", Type, VT_BSTR, VTS_NONE)
	// NOTE - the ClassWizard will add and remove mapping macros here.
		//      DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IOleTes to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {E107DFA0-CD1A-11F0-9739-000C2976A615}
static const IID IID_IWinProMo =
{ 0xe107dfa0, 0xcd1a, 0x11f0, { 0x97, 0x39, 0x0, 0xc, 0x29, 0x76, 0xa6, 0x15 } };

BEGIN_INTERFACE_MAP(CWinProMoDoc, COleServerDoc)
	INTERFACE_PART(CWinProMoDoc, IID_IWinProMo, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinProMoDoc construction/destruction

CWinProMoDoc::CWinProMoDoc()
{
	// Use OLE compound files
	EnableCompoundFile();

	m_objs = NULL;
	m_renderer = NULL;
	m_pluginReference = NULL;
	m_autoObject = NULL;

	//Automation for embedded objects is disabled until support for in-place activation is introduced.
	//EnableAutomation();

	AfxOleLockApp();
}

CProMoEntityContainer* CWinProMoDoc::GetData()
{
	return m_objs;
}

CProMoRenderer* CWinProMoDoc::GetRenderer() {
	return m_renderer;
}

void CWinProMoDoc::SetClipboardHandler(CProMoClipboardHandler* clip)
{
	if(m_objs)
		m_objs->SetClipboardHandler(clip);
}

void CWinProMoDoc::CreateContainer()
{
	if (m_pluginReference) {
		if (m_objs) {
			delete m_objs;
		}
		m_objs = m_pluginReference->pluginInterface->GetContainer();
		m_objs->Clear();
	}
}

void CWinProMoDoc::CreateRenderer()
{
	if (m_pluginReference) {
		if (m_renderer) {
			delete m_renderer;
		}
		m_renderer = m_pluginReference->pluginInterface->GetRenderer();
		if (m_renderer) {
			m_renderer->SetEntityContainer(GetData());
		}
	}
}

BOOL CWinProMoDoc::SelectPluginInterface(CString& docType)
{
	
	CWinProMoApp* pApp = (CWinProMoApp*)AfxGetApp();
	int i;
	for (i = 0; i < pApp->m_Extensions.GetSize(); i++) {
		ExtensionDLL* plug = dynamic_cast<ExtensionDLL*>(pApp->m_Extensions.GetAt(i));
		if (plug) {
			if (plug->docType == docType) {
				m_pluginReference = plug;
				CreateContainer();
				CreateRenderer();
				return TRUE;
			}
		}
	}
	CString str;
	str.Format(_T("Cannot find a compatible plugin for " + docType + ". %i plugins were found."), i);
	AfxMessageBox(str);
	return FALSE;
}

void CWinProMoDoc::SetPluginInterface(ExtensionDLL* inter)
{
	if (!m_pluginReference) {
		m_pluginReference = inter;
	}
}

BOOL CWinProMoDoc::IsFileExisting(const CString& path)
{
	DWORD attr = GetFileAttributes(path);
	return (attr != INVALID_FILE_ATTRIBUTES) &&
		!(attr & FILE_ATTRIBUTE_DIRECTORY);
}

CWinProMoDoc::~CWinProMoDoc()
{
	if (m_objs)
		delete m_objs;
	if (m_renderer)
		delete m_renderer;
	AfxOleUnlockApp();

	ReleaseAutomationObject();
}

CProMoAppChildAuto* CWinProMoDoc::GetAutomationObject()
{
	if (!m_autoObject) {
		m_autoObject = new CProMoDiagramAuto();
		m_autoObject->Initialize(this);
	}
	return m_autoObject;
}

void CWinProMoDoc::ReleaseAutomationObject()
{
	if (m_autoObject) {
		CProMoAppChildAuto* autoObject = m_autoObject;
		m_autoObject = NULL;
		autoObject->Detach();
	}
}

BOOL CWinProMoDoc::OnNewDocument()
{
	
	if (!COleServerDoc::OnNewDocument())
		return FALSE;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CWinProMoDoc serialization

void CWinProMoDoc::Serialize(CArchive& ar)
{
	CString str;
	CStringArray data;

	CFile* pFile = ar.GetFile();
	
	if (ar.IsStoring())
	{
		if (m_objs) {
			m_objs->Save(data);

			if (ar.GetFile()->GetFilePath().IsEmpty()) {
				data.Serialize(ar);

			}
			else {
				CFileSerializer::Save(ar, data);
			}
		}
	}
	else
	{
		if (m_objs) {
			m_objs->Clear();
		}
		if (!IsFileExisting(ar.GetFile()->GetFilePath())) {
			data.Serialize(ar);
		}
		else {
			CFileSerializer::Load(ar, data);
		}

		if (data.GetSize() > 0) {

			CString modelType;
			CFileParser::GetHeaderFromString(data.GetAt(0), modelType);

			if (SelectPluginInterface(modelType)) {

				CWinProMoApp* pApp = (CWinProMoApp*)AfxGetApp();

				SetClipboardHandler(&pApp->m_clip);

				if (m_objs) {
					m_objs->Load(data);
				}
			}

		}
	
	}
	
}

BOOL CWinProMoDoc::SaveModified()
{
	if (m_objs) {
		SetModifiedFlag(m_objs->IsModified());
		NotifyChanged();
	}
	return COleServerDoc::SaveModified();
}

/////////////////////////////////////////////////////////////////////////////
// CWinProMoDoc diagnostics

#ifdef _DEBUG
void CWinProMoDoc::AssertValid() const
{
	COleServerDoc::AssertValid();
}

void CWinProMoDoc::Dump(CDumpContext& dc) const
{
	COleServerDoc::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWinProMoDoc commands

BOOL CWinProMoDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	BOOL isOle = IsEmbedded();

	if (!IsFileExisting(lpszPathName)) 
		return COleServerDoc::OnOpenDocument(lpszPathName);
			
	CFile file(lpszPathName, CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	Serialize(ar);
	if (isOle) {
		SetModifiedFlag(TRUE);
	}
	return TRUE;
}

COleServerItem* CWinProMoDoc::OnGetEmbeddedItem()
{
	// OnGetEmbeddedItem is called by the framework to get the COleServerItem
	//  that is associated with the document.  It is only called when necessary.

	CWinProMoOleSrvItem* pItem = new CWinProMoOleSrvItem(this);
	ASSERT_VALID(pItem);
	return pItem;
}


BOOL CWinProMoDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	if (CString(lpszPathName).IsEmpty())
		return COleServerDoc::OnSaveDocument(lpszPathName);

	CFile file(lpszPathName, CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);

	Serialize(ar);   // your normal file serializer
	ar.Close();
	file.Close();

	SetModifiedFlag(FALSE);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CWinProMoDoc message handlers

void CWinProMoDoc::Activate()
{
	// TODO: Add your dispatch handler code here

}

void CWinProMoDoc::Redo(short times)
{
	CProMoDiagramAutoAbs* autoObject = dynamic_cast<CProMoDiagramAutoAbs*>(GetAutomationObject());
	if (autoObject) {
		autoObject->Redo(times);
	}
}

void CWinProMoDoc::Undo(BOOL times)
{
	CProMoDiagramAutoAbs* autoObject = dynamic_cast<CProMoDiagramAutoAbs*>(GetAutomationObject());
	if (autoObject) {
		autoObject->Undo(times);
	}
}

BSTR CWinProMoDoc::Path()
{
	CString strResult;
	
	CProMoDiagramAutoAbs* autoObject = dynamic_cast<CProMoDiagramAutoAbs*>(GetAutomationObject());
	if (autoObject) {
		return autoObject->Path();
	}

	return strResult.AllocSysString();
}

BSTR CWinProMoDoc::Type()
{
	CString strResult;
	
	CProMoDiagramAutoAbs* autoObject = dynamic_cast<CProMoDiagramAutoAbs*>(GetAutomationObject());
	if (autoObject) {
		return autoObject->Type();
	}

	return strResult.AllocSysString();
}

LPDISPATCH CWinProMoDoc::GetElements()
{
	CProMoDiagramAutoAbs* autoObject = dynamic_cast<CProMoDiagramAutoAbs*>(GetAutomationObject());
	if (autoObject) {
		autoObject->GetElements();
	}

	return NULL;
}

void CWinProMoDoc::SetElements(LPDISPATCH newValue)
{
	SetNotSupported();
}

long CWinProMoDoc::GetWidth()
{
	CProMoDiagramAutoAbs* autoObject = dynamic_cast<CProMoDiagramAutoAbs*>(GetAutomationObject());
	if (autoObject) {
		return autoObject->GetWidth();
	}

	return 0;
}

void CWinProMoDoc::SetWidth(long nNewValue)
{
	CProMoDiagramAutoAbs* autoObject = dynamic_cast<CProMoDiagramAutoAbs*>(GetAutomationObject());
	if (autoObject) {
		autoObject->SetWidth(nNewValue);
	}
}

long CWinProMoDoc::GetHeight()
{
	CProMoDiagramAutoAbs* autoObject = dynamic_cast<CProMoDiagramAutoAbs*>(GetAutomationObject());
	if (autoObject) {
		return autoObject->GetHeight();
	}

	return 0;
}

void CWinProMoDoc::SetHeight(long nNewValue)
{
	CProMoDiagramAutoAbs* autoObject = dynamic_cast<CProMoDiagramAutoAbs*>(GetAutomationObject());
	if (autoObject) {
		autoObject->SetHeight(nNewValue);
	}
}

void CWinProMoDoc::Save(BOOL noPrompt)
{
	CProMoDiagramAutoAbs* autoObject = dynamic_cast<CProMoDiagramAutoAbs*>(GetAutomationObject());
	if (autoObject) {
		autoObject->Save(noPrompt);
	}
}

void CWinProMoDoc::SaveAs(const VARIANT FAR& fileName)
{
	CProMoDiagramAutoAbs* autoObject = dynamic_cast<CProMoDiagramAutoAbs*>(GetAutomationObject());
	if (autoObject) {
		autoObject->SaveAs(fileName);
	}
}

void CWinProMoDoc::Close(BOOL saveChanges)
{
	CProMoDiagramAutoAbs* autoObject = dynamic_cast<CProMoDiagramAutoAbs*>(GetAutomationObject());
	
	POSITION pos = GetFirstViewPosition();
	if (!pos)
		return;

	CView* pView = GetNextView(pos);
	if (!pView)
		return;

	CFrameWnd* pFrame = pView->GetParentFrame();
	if (!pFrame)
		return;

	pFrame->PostMessage(WM_CLOSE);
}

LPDISPATCH CWinProMoDoc::GetLabels()
{
	CProMoDiagramAutoAbs* autoObject = dynamic_cast<CProMoDiagramAutoAbs*>(GetAutomationObject());
	if (autoObject) {
		autoObject->GetLabels();
	}

	return NULL;
}

void CWinProMoDoc::SetLabels(LPDISPATCH newValue)
{
	SetNotSupported();

}

VARIANT CWinProMoDoc::GetCreatableElementTypes()
{
	VARIANT vaResult;
	VariantInit(&vaResult);

	CProMoDiagramAutoAbs* autoObject = dynamic_cast<CProMoDiagramAutoAbs*>(GetAutomationObject());
	if (autoObject) {
		return autoObject->GetCreatableElementTypes();
	}

	return vaResult;
}

void CWinProMoDoc::SetCreatableElementTypes(const VARIANT FAR& newValue)
{
	SetNotSupported();

}



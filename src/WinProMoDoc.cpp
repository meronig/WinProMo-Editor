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
	//{{AFX_DISPATCH_MAP(COleTestDoc)
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
	m_fact = NULL;
	m_renderer = NULL;
	m_pluginReference = NULL;

	EnableAutomation();

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
				CreateControlFactory();
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

void CWinProMoDoc::CreateControlFactory()
{
	if (m_pluginReference) {
		if (m_fact) {
			delete m_fact;
		}
		m_fact = m_pluginReference->pluginInterface->GetControlFactory();
	}
}

CWinProMoDoc::~CWinProMoDoc()
{
	if (m_objs)
		delete m_objs;
	if (m_fact)
		delete m_fact;
	if (m_renderer)
		delete m_renderer;
	AfxOleUnlockApp();
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

				if (m_fact && m_objs) {
					m_objs->Load(data, *m_fact);
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

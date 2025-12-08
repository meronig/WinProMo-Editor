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
#include "SelectDocumentTypeDlg.h"
#include "MainFrm.h"

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
	m_pluginInterface = NULL;

	EnableAutomation();

	AfxOleLockApp();
}

CProMoEntityContainer* CWinProMoDoc::GetData()
{
	return m_objs;
}

void CWinProMoDoc::SetClipboardHandler(CProMoClipboardHandler* clip)
{
	if(m_objs)
		m_objs->SetClipboardHandler(clip);
}

void CWinProMoDoc::CreateContainer()
{
	if (m_pluginInterface) {
		if (m_objs) {
			delete m_objs;
		}
		m_objs = m_pluginInterface->GetContainer();
		m_objs->Clear();
	}
}

void CWinProMoDoc::SelectPluginInterface(CString& docType)
{
	
	CWinProMoApp* pApp = (CWinProMoApp*)AfxGetApp();
	int i;
	for (i = 0; i < pApp->m_Extensions.GetSize(); i++) {
		ExtensionDLL* plug = dynamic_cast<ExtensionDLL*>(pApp->m_Extensions.GetAt(i));
		if (plug) {
			if (plug->docType == docType) {
				m_pluginInterface = plug->pluginInterface;
				return;
			}
		}
	}
	CString str;
	str.Format(_T("Cannot find a compatible plugin for " + docType + ". %i plugins were found."), i);
	AfxMessageBox(str);
}

void CWinProMoDoc::SetPluginInterface(CWinProMoPluginInterface* inter)
{
	if (!m_pluginInterface) {
		m_pluginInterface = inter;
	}
}

void CWinProMoDoc::CreateControlFactory()
{
	if (m_pluginInterface) {
		if (m_fact) {
			delete m_fact;
		}
		m_fact = m_pluginInterface->GetControlFactory();
	}
}

CWinProMoDoc::~CWinProMoDoc()
{
	if (m_objs)
		delete m_objs;
	if (m_fact)
		delete m_fact;
	AfxOleUnlockApp();
}

BOOL CWinProMoDoc::OnNewDocument()
{
	if (IsEmbedded())  // true for OLE insertion, false for standalone/new user doc
    {
		CWinProMoApp* pApp = (CWinProMoApp*)AfxGetApp();
		pApp->m_init++;
		if ((pApp->m_init)%2 == 1) {
			return TRUE;
		}
        
    }
	
	if (!COleServerDoc::OnNewDocument())
		return FALSE;

	CSelectDocumentTypeDlg dlg;
	if (dlg.DoModal() == IDOK) {
		CString selectedDocType = dlg.GetSelectedDocType();

		SelectPluginInterface(selectedDocType);
		CreateControlFactory();
		CreateContainer();

		CWinProMoApp* pApp = (CWinProMoApp*)AfxGetApp();

		SetClipboardHandler(&pApp->m_clip);

		if (!m_objs) {
			return FALSE;
		}

		m_objs->Clear();
		CWinProMoView* pView = NULL;
		POSITION pos = GetFirstViewPosition();
		if (pos != NULL) {
			pView = (CWinProMoView*)GetNextView(pos);
			if (pView) {
				CClientDC dc(pView);

				int screenResolutionX = dc.GetDeviceCaps(LOGPIXELSX);
				int screenResolutionY = dc.GetDeviceCaps(LOGPIXELSY);

				CDC printDC;

				// Canvas size equals to current page size
				if (pView->GetPrinterDC(printDC)) {
					int printResolutionX = printDC.GetDeviceCaps(LOGPIXELSX);
					int printResolutionY = printDC.GetDeviceCaps(LOGPIXELSY);

					int horzSize = round((double)printDC.GetDeviceCaps(HORZRES) * (double)screenResolutionX / printResolutionX);
					int vertSize = round((double)printDC.GetDeviceCaps(VERTRES) * (double)screenResolutionY / printResolutionY);

					m_objs->SetVirtualSize(CSize(horzSize - 1, vertSize - 1));

					printDC.DeleteDC();
				}
				// No printer, so default to 8x11
				else {
					m_objs->SetVirtualSize(CSize(8 * screenResolutionX, 11 * screenResolutionX));
				}

			}
		}

		return TRUE;
	}
	
	return FALSE;
	
}

/////////////////////////////////////////////////////////////////////////////
// CWinProMoDoc serialization

void CWinProMoDoc::Serialize(CArchive& ar)
{
	CString str;
	CStringArray data;

	CFile* pFile = ar.GetFile();
	BOOL isOle = (pFile == NULL);
	
	if (ar.IsStoring())
	{
		if (m_objs) {
			m_objs->Save(data);

			if (isOle) {
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
			
		if (isOle) {
			data.Serialize(ar);
		}
		else {
			CFileSerializer::Load(ar, data);
		}

		if (data.GetSize() > 0) {

			CString modelType;
			CFileParser::GetHeaderFromString(data.GetAt(0), modelType);

			SelectPluginInterface(modelType);
			CreateControlFactory();
			CreateContainer();

			CWinProMoApp* pApp = (CWinProMoApp*)AfxGetApp();

			SetClipboardHandler(&pApp->m_clip);

			if (m_fact && m_objs) {
				m_objs->Load(data, *m_fact);
			}

		}
	
	}
	
}

BOOL CWinProMoDoc::SaveModified()
{
	if (m_objs) {
		SetModifiedFlag(m_objs->IsModified());
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
	if (!COleServerDoc::OnOpenDocument(lpszPathName))
		return FALSE;

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

void CWinProMoDoc::OnDeactivateUI(BOOL bUndoable)
{
	// TODO: Add your specialized code here and/or call the base class

	COleServerDoc::OnDeactivateUI(bUndoable);

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	if (pFrame) {
		pFrame->m_pPropertyDlg.ShowWindow(SW_HIDE);
		pFrame->m_pElementListDlg.ShowWindow(SW_HIDE);
	}
}

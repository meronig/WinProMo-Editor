/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
// WinProMo.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "WinProMo.h"

#include "MainFrm.h"
#include "ChildFrm.h"

#include "../../WinProMo/src/DiagramEditor/Tokenizer.h"
#include "WinProMoDoc.h"
#include "WinProMoView.h"
#include "../../WinProMo/src/Resource.h"
#include <winreg.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWinProMoApp

BEGIN_MESSAGE_MAP(CWinProMoApp, CWinApp)
	//{{AFX_MSG_MAP(CWinProMoApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinProMoApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinProMoApp construction

CWinProMoApp::CWinProMoApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	m_pMainFrame = NULL;
	g_hCurrentAccel = NULL;
	m_docTemplate = NULL;
	m_init = 0;
}

CWinProMoApp::~CWinProMoApp()
{
	UnloadExtensions();
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CWinProMoApp object

CWinProMoApp theApp;

// This identifier was generated to be statistically unique for your app.
// You may change it if you prefer to choose a specific identifier.

// {E107DF9E-CD1A-11F0-9739-000C2976A615}
static const CLSID clsid =
{ 0xe107df9e, 0xcd1a, 0x11f0, { 0x97, 0x39, 0x0, 0xc, 0x29, 0x76, 0xa6, 0x15 } };

/////////////////////////////////////////////////////////////////////////////
// CWinProMoApp initialization

BOOL CWinProMoApp::InitInstance()
{
	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	SetRegistryKey(_T("DTU Compute"));

#if (_MSC_VER <= 1200) 
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
#endif
	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Load and register available documents from plug-in libraries
	LoadExtensions();

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	m_docTemplate = new CMultiDocTemplate(
		IDR_WINPROTYPE,
		RUNTIME_CLASS(CWinProMoDoc),
		RUNTIME_CLASS(CChildFrame),
		RUNTIME_CLASS(CWinProMoView));
	m_docTemplate->SetServerInfo(
		IDR_WINPROTYPE_SRVR_EMB, IDR_WINPROTYPE_SRVR_IP,
		NULL);

	AddDocTemplate(m_docTemplate);

	// Connect the COleTemplateServer to the document template.
	//  The COleTemplateServer creates new documents on behalf
	//  of requesting OLE containers by using information
	//  specified in the document template.
	m_server.ConnectTemplate(clsid, m_docTemplate, FALSE);

	// Register all OLE server factories as running.  This enables the
	//  OLE libraries to create objects from other applications.
	COleTemplateServer::RegisterAll();
	// Note: MDI applications register all server objects without regard
	//  to the /Embedding or /Automation on the command line.

	// create main MDI Frame window
	m_pMainFrame = new CMainFrame;
	if (!m_pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = m_pMainFrame;

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Check to see if launched as OLE server
	if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	{
		// Application was run with /Embedding or /Automation.  Don't show the
		//  main window in this case.
		return TRUE;
	}

	// When a server application is launched stand-alone, it is a good idea
	//  to update the system registry in case it has been damaged.
	m_server.UpdateRegistry(OAT_INPLACE_SERVER);
	COleObjectFactory::UpdateRegistryAll();

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	
	LPCTSTR lpCmdLine = m_lpCmdLine;

	if (lpCmdLine != NULL && *lpCmdLine != 0)
	{
		if (_tcsicmp(lpCmdLine, _T("/RegServer")) == 0 ||
			_tcsicmp(lpCmdLine, _T("-RegServer")) == 0)
		{
			RegisterTypeLibrary(FALSE);

			// Register file extension
			HKEY hKey;
			CString key = _T(".wpd");
			LONG lRes = RegCreateKeyEx(HKEY_CLASSES_ROOT, key, 0, NULL,
				REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL);
			if (lRes == ERROR_SUCCESS)
			{
				RegSetValueEx(hKey, NULL, 0, REG_SZ,
					(BYTE*)_T("WinProMo.Document"),
					(_tcslen(_T("WinProMo.Document")) + 1) * sizeof(TCHAR));
				RegCloseKey(hKey);
			}

			return FALSE;   // do not start UI
		}

		if (_tcsicmp(lpCmdLine, _T("/UnregServer")) == 0 ||
			_tcsicmp(lpCmdLine, _T("-UnregServer")) == 0)
		{
			RegisterTypeLibrary(TRUE);
			return FALSE;
		}
	}

	// The main window has been initialized, so show and update it.
	m_pMainFrame->ShowWindow(m_nCmdShow);
	m_pMainFrame->UpdateWindow();

	return TRUE;
}

void CWinProMoApp::RegisterTypeLibrary(BOOL deregister)
{
	TCHAR tlbPath[MAX_PATH];
	// TODO: generate TLB file from exe name without extension
	CreatePath(_T("WinProMo.tlb"), tlbPath);

	USES_CONVERSION;  // required for T2OLE
	LPOLESTR lpszOlePath = T2OLE(tlbPath);

	ITypeLib* pTypeLib = NULL;

	if (deregister) {
		//UnRegisterTypeLib(LIBID_WinProMoApp, 1, 0, LOCALE_USER_DEFAULT, SYS_WIN32);
	}
	else {
		if (SUCCEEDED(LoadTypeLib(lpszOlePath, &pTypeLib)))
		{
			RegisterTypeLib(pTypeLib, lpszOlePath, NULL);
			pTypeLib->Release();
		}
	}

	//test

	CreatePath(_T("WinProMo-App.tlb"), tlbPath);

	//USES_CONVERSION;  // required for T2OLE
	lpszOlePath = T2OLE(tlbPath);

	pTypeLib = NULL;

	if (deregister) {
		//UnRegisterTypeLib(LIBID_WinProMoApp, 1, 0, LOCALE_USER_DEFAULT, SYS_WIN32);
	}
	else {
		if (SUCCEEDED(LoadTypeLib(lpszOlePath, &pTypeLib)))
		{
			RegisterTypeLib(pTypeLib, lpszOlePath, NULL);
			pTypeLib->Release();
		}
	}

}

//Custom, clean up once everything works
void CWinProMoApp::LoadExtensions() {

	TCHAR searchPath[MAX_PATH];
	CreatePath(_T("*.dll"), searchPath);

	WIN32_FIND_DATA findFileData;
	HANDLE hFind = FindFirstFile(searchPath, &findFileData);
	
	if (hFind == INVALID_HANDLE_VALUE) {
		DWORD err = GetLastError();
		return;
	}

	do {
		//create full path
		TCHAR fullFilePath[MAX_PATH];

		CreatePath(findFileData.cFileName, fullFilePath);
		HMODULE hModule = LoadLibrary(fullFilePath);
		if (hModule) {
			CreatePluginInstanceFunc createPluginInterface = (CreatePluginInstanceFunc)GetProcAddress(hModule, "CreatePluginInstance");

			if (createPluginInterface) {
				CWinProMoPluginInterface* pluginInterface = createPluginInterface();
				if (pluginInterface) {
					CString docType = pluginInterface->GetDocumentType();
					CObArray* elements = pluginInterface->GetElements();
					UINT docID = pluginInterface->GetDocumentID();
					CString descr = pluginInterface->GetDocumentDescr();
					ExtensionDLL* ext = new ExtensionDLL;
					ext->hModule = hModule;
					ext->docType = docType;
					ext->docID = docID;
					ext->descr = descr;
					ext->elements = elements;
					ext->pluginInterface = pluginInterface;
					m_Extensions.Add(ext);
				}
			
			}
			else {
				FreeLibrary(hModule);
			}
			
			
		}
	} while (FindNextFile(hFind, &findFileData));

	FindClose(hFind);
}

void CWinProMoApp::UnloadExtensions()
{
	// Clear the clipboard to avoid lingering objects
	m_clip.ClearPaste();
	int i = 0;
	for (i = (int)m_Extensions.GetSize() - 1; i >= 0; i--) {
		ExtensionDLL* ext = static_cast<ExtensionDLL*>(m_Extensions.GetAt(i));
		if (ext) {
			ext->pluginInterface->Destroy();
			DeleteCommands(ext->elements);
			FreeLibrary(ext->hModule);
			m_Extensions.RemoveAt(i);
		}
		delete ext;
	}
}

void CWinProMoApp::DeleteCommands(CObArray* commands)
{
	if (commands) {
		for (int i = 0; i < commands->GetSize(); i++) {
			CWinProMoPluginCommand* command = dynamic_cast<CWinProMoPluginCommand*>(commands->GetAt(i));
			if (command) {
				DeleteCommands(command->m_subCommands);
				delete command;
			}
		}
		delete commands;
	}
}

void CWinProMoApp::CreatePath(const TCHAR* fileName, TCHAR* fullPath)
{
	TCHAR exePath[MAX_PATH];
	GetModuleFileName(NULL, exePath, MAX_PATH);

	// Remove the executable name to get the directory path
	TCHAR* lastSlash = _tcsrchr(exePath, _T('\\'));
	if (lastSlash) *(lastSlash + 1) = _T('\0');

	// Append "*.dll" to search in that directory
#if _MSC_VER < 1200
	_stprintf(fullPath, fileName, exePath);
#else
	_stprintf_s(fullPath, MAX_PATH, _T("%s%s"), exePath, fileName);
#endif

}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CWinProMoApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

void CWinProMoApp::OnFilePrintSetup()
{
	CWinApp::OnFilePrintSetup();

	// Notify changes to all child windows
	POSITION pos = AfxGetApp()->GetFirstDocTemplatePosition();
	while (pos)
	{
		CDocTemplate* pTemplate = AfxGetApp()->GetNextDocTemplate(pos);
		POSITION docPos = pTemplate->GetFirstDocPosition();
		while (docPos)
		{
			CDocument* pDoc = pTemplate->GetNextDoc(docPos);
			POSITION viewPos = pDoc->GetFirstViewPosition();
			while (viewPos)
			{
				CWinProMoView* pView = static_cast<CWinProMoView*>(pDoc->GetNextView(viewPos));
				pView->SetPageSize();
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWinProMoApp commands

BOOL CWinProMoApp::PreTranslateMessage(MSG* pMsg)
{
	if (g_hCurrentAccel && ::TranslateAccelerator(AfxGetMainWnd()->m_hWnd, g_hCurrentAccel, pMsg))
		return TRUE;

	return CWinApp::PreTranslateMessage(pMsg);
}

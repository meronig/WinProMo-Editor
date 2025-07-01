// WinProMo.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "WinProMo.h"

#include "MainFrm.h"
#include "ChildFrm.h"

#include "../WinProMo/DiagramEditor/Tokenizer.h"
#include "../WinProMo/WinProMoDoc.h"
//#include "../WinProMo/WinProMoDocTemplate.h"


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
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinProMoApp construction

CWinProMoApp::CWinProMoApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	m_pMainFrame = NULL;
}

CWinProMoApp::~CWinProMoApp()
{
	UnloadExtensions();
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CWinProMoApp object

CWinProMoApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CWinProMoApp initialization

BOOL CWinProMoApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#if (_MSC_VER <= 1200) 
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
#endif
	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// create main MDI Frame window
	m_pMainFrame = new CMainFrame;
	if (!m_pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = m_pMainFrame;

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Load and register available documents from plug-in libraries
	LoadExtensions();

	// The main window has been initialized, so show and update it.
	m_pMainFrame->ShowWindow(m_nCmdShow);
	m_pMainFrame->UpdateWindow();
	
	//Commented out as it causes a crash
	//OnFileNew();
	
	return TRUE;
}

//Custom, clean up once everything works
void CWinProMoApp::LoadExtensions() {
	TCHAR exePath[MAX_PATH];
	GetModuleFileName(NULL, exePath, MAX_PATH);

	// Remove the executable name to get the directory path
	TCHAR* lastSlash = _tcsrchr(exePath, _T('\\'));
	if (lastSlash) *(lastSlash + 1) = _T('\0');

	// Append "*.dll" to search in that directory
	TCHAR searchPath[MAX_PATH];
#if _MSC_VER < 1200
	_stprintf(searchPath, _T("%s*.dll"), exePath);
#else
	_stprintf_s(searchPath, _T("%s*.dll"), exePath);
#endif

	//std::wcout << L"Searching for DLLs in: " << searchPath << std::endl;

	WIN32_FIND_DATA findFileData;
	HANDLE hFind = FindFirstFile(searchPath, &findFileData);

	if (hFind == INVALID_HANDLE_VALUE) {
		DWORD err = GetLastError();
		//std::wcerr << L"No DLLs found. Error Code: " << err << std::endl;
		return;
	}

	do {
		HMODULE hModule = LoadLibrary(findFileData.cFileName);
		if (hModule) {
			CreatePluginInstanceFunc createPluginInterface = (CreatePluginInstanceFunc)GetProcAddress(hModule, "CreatePluginInstance");

			if (createPluginInterface) {
				CWinProMoPluginInterface* pluginInterface = createPluginInterface();
				if (pluginInterface) {
					CString docType = pluginInterface->GetDocumentType();
					CObArray* elements = pluginInterface->GetElements();
					UINT docID = pluginInterface->GetDocumentID();
					CMultiDocTemplate* pTemplate = pluginInterface->RegisterPlugin(RUNTIME_CLASS(CChildFrame), &m_clip);
					if (pTemplate) {
						AddDocTemplate(pTemplate);
						ExtensionDLL* ext = new ExtensionDLL;
						ext->hModule = hModule;
						ext->docType = docType;
						ext->docID = docID;
						ext->elements = elements;
						ext->pTemplate = pTemplate;
						ext->pluginInterface = pluginInterface;
						m_Extensions.Add(ext);
					}
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
	for (int i = m_Extensions.GetSize() - 1; i >= 0; i--) {
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

//Override
CDocument* CWinProMoApp::OpenDocumentFile(LPCTSTR lpszFileName)
{
	CString docType = DetectDocTypeFromFile(lpszFileName);
	for (size_t i = 0; i < m_Extensions.GetSize(); ++i) {
		ExtensionDLL* ext = static_cast<ExtensionDLL*>(m_Extensions.GetAt(i));
		if (ext) {
			if (ext->docType == docType) {
				CDocument* doc = ext->pTemplate->OpenDocumentFile(lpszFileName);
				return doc;
			}
		}
	}
	
	AfxMessageBox(_T("No suitable plugin found for this file."));
	return NULL;
}

//Custom
CString CWinProMoApp::DetectDocTypeFromFile(LPCTSTR lpszFileName)
{
	
	CFile file;
	CFileException feError;
	if (file.Open(lpszFileName, CFile::modeRead, &feError)) {
		DWORD size = (DWORD)file.GetLength();
		char* buffer = new char[size + 1];
		file.Read(buffer, size);
		buffer[size] = '\0';

		CString content(buffer);
		delete[] buffer;

		int pos = 0;
		while (pos >= 0)
		{
			int next = content.Mid(pos).Find(_T("\r\n"));

			if (next != -1)
			{
				next += pos;  // adjust to full string position
			}

			CString line;
			if (next == -1)
			{
				line = content.Mid(pos);
				pos = -1;
			}
			else
			{
				line = content.Mid(pos, next - pos);
				pos = next + 2; // skip past "\r\n"
			}
			CTokenizer main(line, _T(":"));
			CString header;
			if (main.GetSize() == 2)
			{
				main.GetAt(0, header);
				header.TrimLeft();
				header.TrimRight();
				return header;
			}
		}
	}
	AfxMessageBox(_T("Cannot read input file or input file is malformed"));
	return _T("");
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

/////////////////////////////////////////////////////////////////////////////
// CWinProMoApp commands

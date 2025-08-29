/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
// WinProMo.h : main header file for the WINPROMO application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "../../WinProMo/src/ProMoEditor/ProMoClipboardHandler.h"
#include "../../WinProMo/src/WinProMoPluginInterface.h"

typedef CWinProMoPluginInterface* (*CreatePluginInstanceFunc)();

class ExtensionDLL : public CObject 
{
public:
	HMODULE hModule;
	CString docType;
	UINT docID;
	CObArray* elements;
	CMultiDocTemplate* pTemplate;
	CWinProMoPluginInterface* pluginInterface;
};


/////////////////////////////////////////////////////////////////////////////
// CWinProMoApp:
// See WinProMo.cpp for the implementation of this class
//

class CWinProMoApp : public CWinApp
{
public:
	CWinProMoApp();
	~CWinProMoApp();

	CObArray m_Extensions;
	CMDIFrameWnd* m_pMainFrame;
	CProMoClipboardHandler	m_clip;
	HACCEL g_hCurrentAccel;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinProMoApp)
public:
	virtual BOOL InitInstance();
	CDocument* OpenDocumentFile(LPCTSTR lpszFileName);
	//}}AFX_VIRTUAL

protected:
	void LoadExtensions();
	void UnloadExtensions();
	void DeleteCommands(CObArray* commands);
	CString DetectDocTypeFromFile(LPCTSTR lpszFileName);

// Implementation

	//{{AFX_MSG(CWinProMoApp)
	afx_msg void OnAppAbout();
	afx_msg void OnFilePrintSetup();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};


/////////////////////////////////////////////////////////////////////////////

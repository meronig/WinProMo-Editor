/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
// WinProMo.h : main header file for the WINPROMO application
//

#ifndef _WINPROMO_H_
#define _WINPROMO_H_

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
	COleTemplateServer m_server;
	CMultiDocTemplate* m_docTemplate;
	UINT m_init;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinProMoApp)
public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

protected:
	void LoadExtensions();
	void UnloadExtensions();
	void DeleteCommands(CObArray* commands);

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
#endif _WINPROMO_H_
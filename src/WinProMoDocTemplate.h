/* ==========================================================================

	Copyright © 2026 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
   // WinProMoDocTemplate.h : interface of the CWinProMoDoc class
   //
   /////////////////////////////////////////////////////////////////////////////
#ifndef _WINPROMODOCTEMPLATE_H_
#define _WINPROMODOCTEMPLATE_H_


#include "stdafx.h"

class CWinProMoDocTemplate : public CMultiDocTemplate
{
public:

	CWinProMoDocTemplate(UINT nIDResource, CRuntimeClass* pDocClass, CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass);
	virtual ~CWinProMoDocTemplate();

	virtual CDocument* OpenDocumentFile(LPCTSTR lpszPathName, BOOL bMakeVisible = 1, CString modelType = CString(""));

	virtual CDocument* CreateNewDocument();

private:
	CString m_modelType;
};

#endif //_WINPROMODOCTEMPLATE_H_
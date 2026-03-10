/* ==========================================================================

	Copyright © 2026 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/

#include "stdafx.h"
#include "WinProMoDocTemplate.h"
#include "WinProMoDoc.h"

CWinProMoDocTemplate::CWinProMoDocTemplate(UINT nIDResource, CRuntimeClass* pDocClass, CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass)
	: CMultiDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
{
}

CWinProMoDocTemplate::~CWinProMoDocTemplate()
{
}

CDocument* CWinProMoDocTemplate::OpenDocumentFile(LPCTSTR lpszPathName, BOOL bMakeVisible, CString modelType)
{
	m_modelType = modelType;
	CDocument* pDoc = CMultiDocTemplate::OpenDocumentFile(lpszPathName, bMakeVisible);
	m_modelType = CString();
	return pDoc;
}

CDocument* CWinProMoDocTemplate::CreateNewDocument()
{
	CWinProMoDoc* pDoc = dynamic_cast<CWinProMoDoc*>(CMultiDocTemplate::CreateNewDocument());
	if (pDoc && m_modelType != CString()) {
		pDoc->SelectPluginInterface(m_modelType);
	}
	return pDoc;
}

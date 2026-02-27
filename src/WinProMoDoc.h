/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
// WinProMoDoc.h : interface of the CWinProMoDoc class
//
/////////////////////////////////////////////////////////////////////////////
#ifndef _WINPROMODOC_H_
#define _WINPROMODOC_H_


#include "stdafx.h"
#include "../../WinProMo/src/ProMoEditor/ProMoEntityContainer.h"
#include "../../WinProMo/src/ProMoEditor/ProMoClipboardHandler.h"
#include "WinProMo.h"
#include "../../WinProMo/src/Automation/ProMoAppChildAuto.h"
#include "../../WinProMo/src/Automation/ProMoAutomationHost.h"

class CWinProMoOleSrvItem;

class CWinProMoDoc : public COleServerDoc, public IProMoAutomationHost
{
protected: // create from serialization only
	CWinProMoDoc();
	DECLARE_DYNCREATE(CWinProMoDoc)
	
// Attributes
public:
	CWinProMoOleSrvItem* GetEmbeddedItem()
		{ return (CWinProMoOleSrvItem*)COleServerDoc::GetEmbeddedItem();}
	
	ExtensionDLL* m_pluginReference;
	
// Operations
public:
	
	virtual CProMoEntityContainer* GetData();
	virtual CProMoRenderer* GetRenderer();
	virtual void SetClipboardHandler(CProMoClipboardHandler* clip);
	
	virtual BOOL SelectPluginInterface(CString& docType);

protected:
	virtual void CreateContainer();
	virtual void CreateRenderer();
	virtual void SetPluginInterface(ExtensionDLL* inter);
	virtual BOOL IsFileExisting(const CString& path);


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinProMoDoc)
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
protected:
	virtual COleServerItem* OnGetEmbeddedItem();
	virtual BOOL SaveModified();
	//}}AFX_VIRTUAL



// Implementation
public:
	virtual ~CWinProMoDoc();
	
	virtual CProMoAppChildAuto* GetAutomationObject();
	virtual void ReleaseAutomationObject();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWinProMoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CWinProMoDoc)
	afx_msg LPDISPATCH GetElements();
	afx_msg void SetElements(LPDISPATCH newValue);
	afx_msg long GetWidth();
	afx_msg void SetWidth(long nNewValue);
	afx_msg long GetHeight();
	afx_msg void SetHeight(long nNewValue);
	afx_msg LPDISPATCH GetLabels();
	afx_msg void SetLabels(LPDISPATCH newValue);
	afx_msg VARIANT GetCreatableElementTypes();
	afx_msg void SetCreatableElementTypes(const VARIANT FAR& newValue);
	afx_msg void SaveAs(const VARIANT FAR& fileName);
	afx_msg void Activate();
	afx_msg void Close(BOOL saveChanges);
	afx_msg void Redo(short times);
	afx_msg void Save(BOOL noPrompt);
	afx_msg void Undo(BOOL times);
	afx_msg BSTR Path();
	afx_msg BSTR Type();
	afx_msg void ClosePrintPreview();
	afx_msg void PrintPreview();
	afx_msg LPDISPATCH Application();
	// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	CProMoEntityContainer* m_objs;
	CProMoRenderer* m_renderer;
	CProMoAppChildAuto* m_autoObject;


public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
};

#endif // _WINPROMODOC_H_
/////////////////////////////////////////////////////////////////////////////

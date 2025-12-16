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

class CWinProMoOleSrvItem;

class CWinProMoDoc : public COleServerDoc
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
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinProMoDoc)
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
protected:
	virtual COleServerItem* OnGetEmbeddedItem();
	virtual BOOL SaveModified();

	virtual void CreateControlFactory();
	virtual void CreateContainer();
	virtual void CreateRenderer();
	virtual void SetPluginInterface(ExtensionDLL* inter);
	virtual BOOL IsFileExisting(const CString& path);

	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWinProMoDoc();
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
	//{{AFX_DISPATCH(COleTestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

	CProMoEntityContainer* m_objs;
	CProMoControlFactory* m_fact;
	CProMoRenderer* m_renderer;
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
};

#endif // _WINPROMODOC_H_
/////////////////////////////////////////////////////////////////////////////

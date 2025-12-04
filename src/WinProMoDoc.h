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
#include "../../WinProMo/src/WinProMoPluginInterface.h"

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
	
	CWinProMoPluginInterface* m_pluginInterface;

// Operations
public:
	
	virtual CProMoEntityContainer* GetData();
	virtual void SetClipboardHandler(CProMoClipboardHandler* clip);
	
	virtual void CreateControlFactory();
	virtual void CreateContainer();
	virtual void SelectPluginInterface(CString& docType);
	virtual void SetPluginInterface(CWinProMoPluginInterface* inter);

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
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	
};

#endif // _WINPROMODOC_H_
/////////////////////////////////////////////////////////////////////////////

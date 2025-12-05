/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _SELECTDOCUMENTTYPEDIALOG_H_
#define _SELECTDOCUMENTTYPEDIALOG_H_

#include "resource.h"

// CSelectDocumentTypeDlg dialog

class CSelectDocumentTypeDlg : public CDialog
{
	DECLARE_DYNAMIC(CSelectDocumentTypeDlg)

public:
	CSelectDocumentTypeDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSelectDocumentTypeDlg();

	virtual CString GetSelectedDocType();

	// Dialog Data
	//{{AFX_DATA(CPropertyDialog)
	enum { IDD = IDD_SELECT_DOCUMENT_TYPE };
	//}}AFX_DATA

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void OnBnClickedOk();

	DECLARE_MESSAGE_MAP()
private:
	CListBox m_listBox;
	CString m_selectedDocType;
public:
	virtual BOOL OnInitDialog();
};

#endif //_SELECTDOCUMENTTYPEDIALOG_H_
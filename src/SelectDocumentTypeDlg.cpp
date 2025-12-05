/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
// SelectDocumentTypeDlg.cpp : implementation file
//

#include "StdAfx.h"
#include "SelectDocumentTypeDlg.h"
#include "WinProMo.h"


// CSelectDocumentTypeDlg dialog

IMPLEMENT_DYNAMIC(CSelectDocumentTypeDlg, CDialog)

CSelectDocumentTypeDlg::CSelectDocumentTypeDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SELECT_DOCUMENT_TYPE, pParent)
{
	
}

CSelectDocumentTypeDlg::~CSelectDocumentTypeDlg()
{
}

CString CSelectDocumentTypeDlg::GetSelectedDocType()
{
	return m_selectedDocType;
}

void CSelectDocumentTypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSelectDocumentTypeDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CSelectDocumentTypeDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CSelectDocumentTypeDlg message handlers

void CSelectDocumentTypeDlg::OnBnClickedOk()
{
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST_DOCUMENT_TYPES);
	int sel = pListBox->GetCurSel();
	if (sel != LB_ERR) {
		pListBox->GetText(sel, m_selectedDocType);
	}
	CDialog::OnOK();
}

BOOL CSelectDocumentTypeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST_DOCUMENT_TYPES);
	CWinProMoApp* pApp = (CWinProMoApp*)AfxGetApp();
	int i;
	
	for (i = 0; i < pApp->m_Extensions.GetSize(); i++) {
		ExtensionDLL* plug = dynamic_cast<ExtensionDLL*>(pApp->m_Extensions.GetAt(i));
		if (plug) {
			pListBox->AddString(plug->docType);
		}
	}

	pListBox->SetCurSel(0); // Select the first item by default

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

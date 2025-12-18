/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
   // ExportDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ExportDlg.h"
#include "resource.h"

// CExportDlg dialog

IMPLEMENT_DYNAMIC(CExportDlg, CDialog)

CExportDlg::CExportDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_EXPORT, pParent)
{
	m_Resolution = -1;
	m_Scale = -1;
	m_Mode = EXPORT_RASTER;
	m_Element = EXPORT_DIAGRAM;
	m_SelectionAvailable = FALSE;
}

CExportDlg::~CExportDlg()
{
}

void CExportDlg::SetExportMode(ExportMode mode)
{
	m_Mode = mode;
	
}

void CExportDlg::SetSelectionAvailable(BOOL available)
{
	m_SelectionAvailable = available;
}

int CExportDlg::GetResolution()
{
	return m_Resolution;
}

double CExportDlg::GetZoom()
{
	return m_Scale / 100.0;
}

ExportMode CExportDlg::GetExportMode()
{
	return m_Mode;
}

ExportElement CExportDlg::GetExportElement()
{
	return m_Element;
}

void CExportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CExportDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CExportDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CExportDlg message handlers

void CExportDlg::OnBnClickedOk()
{
	CButton* pSelectionRadio = (CButton*)GetDlgItem(IDC_RADIO_SELECTION);
	if (pSelectionRadio) {
		if (pSelectionRadio->GetCheck() == BST_CHECKED) {
			m_Element = EXPORT_SELECTION;
		}
		else {
			CButton* pDiagramRadio = (CButton*)GetDlgItem(IDC_RADIO_DIAGRAM);
			if (pDiagramRadio && pDiagramRadio->GetCheck() == BST_CHECKED) {
				m_Element = EXPORT_DIAGRAM;
			}
			else {
				m_Element = EXPORT_CANVAS;
			}
		}
	}

	CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_RES);
	if (pComboBox) {
		CString data;
		pComboBox->GetWindowText(data);
		if (m_Mode == EXPORT_RASTER) {
			m_Resolution = _ttoi(data);
		}
		else if (m_Mode == EXPORT_METAFILE) {
			m_Scale = _ttoi(data);
		}
	}

	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}

BOOL CExportDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	int visibleItems = 8;

	CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_RES);
	if (pComboBox) {
		pComboBox->ResetContent();
		if (m_Mode == EXPORT_RASTER) {
			pComboBox->AddString(_T("72"));
			pComboBox->AddString(_T("150"));
			pComboBox->AddString(_T("300"));
			pComboBox->AddString(_T("600"));
			pComboBox->AddString(_T("1200"));
			pComboBox->SetWindowText(_T("600")); // default 300 dpi
		}
		else if (m_Mode == EXPORT_METAFILE) {
			pComboBox->AddString(_T("25"));
			pComboBox->AddString(_T("50"));
			pComboBox->AddString(_T("75"));
			pComboBox->AddString(_T("100"));
			pComboBox->AddString(_T("150"));
			pComboBox->AddString(_T("200"));
			pComboBox->AddString(_T("300"));
			pComboBox->AddString(_T("400"));
			pComboBox->SetWindowText(_T("100")); // default 100%
		}
		int itemHeight = pComboBox->GetItemHeight(-1); // list item height
		int ctrlHeight = pComboBox->GetItemHeight(0);  // closed control height

		CRect rc;
		pComboBox->GetWindowRect(&rc);
		pComboBox->GetParent()->ScreenToClient(&rc);

		pComboBox->SetWindowPos(
			NULL,
			rc.left,
			rc.top,
			rc.Width(),
			ctrlHeight + visibleItems * itemHeight,
			SWP_NOZORDER
		);
	}
	
	CStatic* pLabel = (CStatic*)GetDlgItem(IDC_STATIC_RES);
	if (pLabel) {
		if (m_Mode == EXPORT_RASTER) {
			pLabel->SetWindowText(_T("Resolution (DPI):"));
		}
		else if (m_Mode == EXPORT_METAFILE) {
			pLabel->SetWindowText(_T("Scale (percentage):"));
		}
	}

	CButton* pSelectionRadio = (CButton*)GetDlgItem(IDC_RADIO_SELECTION);
	if (pSelectionRadio) {
		pSelectionRadio->EnableWindow(m_SelectionAvailable);
		if (m_SelectionAvailable) {
			pSelectionRadio->SetCheck(BST_CHECKED);
		} else {
			pSelectionRadio->SetCheck(BST_UNCHECKED);
			CButton* pAllRadio = (CButton*)GetDlgItem(IDC_RADIO_DIAGRAM);
			if (pAllRadio) {
				pAllRadio->SetCheck(BST_CHECKED);
			}
		}
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

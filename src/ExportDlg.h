/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _EXPORTDIALOG_H_
#define _EXPORTDIALOG_H_

// CExportDlg dialog

#include "WinProMoDoc.h"

class CExportDlg : public CDialog
{
	DECLARE_DYNAMIC(CExportDlg)

public:
	CExportDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CExportDlg();
	void SetExportFormat(ExportFormat mode);
	void SetSelectionAvailable(BOOL available);
	int GetResolution();
	double GetZoom();
	ExportFormat GetExportFormat();
	ExportElement GetExportElement();
	
private:
	int m_Resolution;
	int m_Scale;
	ExportFormat m_Mode;
	ExportElement m_Element;
	BOOL m_SelectionAvailable;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXPORT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};

#endif //_EXPORTDIALOG_H_
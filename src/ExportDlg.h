/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _EXPORTDIALOG_H_
#define _EXPORTDIALOG_H_

// CExportDlg dialog

enum ExportMode
{
	EXPORT_RASTER,
	EXPORT_METAFILE
};

enum ExportElement
{
	EXPORT_SELECTION,
	EXPORT_DIAGRAM,
	EXPORT_CANVAS
};

class CExportDlg : public CDialog
{
	DECLARE_DYNAMIC(CExportDlg)

public:
	CExportDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CExportDlg();
	void SetExportMode(ExportMode mode);
	void SetSelectionAvailable(BOOL available);
	int GetResolution();
	double GetZoom();
	ExportMode GetExportMode();
	ExportElement GetExportElement();
	
private:
	int m_Resolution;
	int m_Scale;
	ExportMode m_Mode;
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
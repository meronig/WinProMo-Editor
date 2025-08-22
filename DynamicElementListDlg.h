/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _DIAGRAMELEMLISTYDIALOG_H_
#define _DIAGRAMELEMLISTYDIALOG_H_

#include "resource.h"


// CDynamicElementListDlg dialog

class CDynamicElementListDlg : public CDialog
{
	DECLARE_DYNAMIC(CDynamicElementListDlg)

public:
	CDynamicElementListDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDynamicElementListDlg();

// Dialog Data

	enum { IDD = IDD_DIALOG_ELEMENTLIST_DYNAMIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	virtual BOOL OnInitDialog();
};

#endif //_DIAGRAMELEMLISTYDIALOG_H_
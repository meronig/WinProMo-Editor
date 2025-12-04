/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _DYNAMICLEMLISTYDIALOG_H_
#define _DYNAMICLEMLISTYDIALOG_H_

#include "resource.h"


// CDynamicElementListDlg dialog

class CDynamicElementListDlg : public CDialog
{
	DECLARE_DYNAMIC(CDynamicElementListDlg)

public:
	CDynamicElementListDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDynamicElementListDlg();
	void Show(BOOL visible);

// Dialog Data

	enum { IDD = IDD_DIALOG_ELEMENTLIST_DYNAMIC };

private:
	BOOL m_visible;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	virtual BOOL OnInitDialog();
};

#endif //_DYNAMICLEMLISTYDIALOG_H_
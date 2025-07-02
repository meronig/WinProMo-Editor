#ifndef _DIAGRAMPROPERTYDIALOG_H_
#define _DIAGRAMPROPERTYDIALOG_H_

#include "../WinProMo/DiagramEditor/DiagramPropertyDlg.h"
#include "resource.h"

class CDynamicPropertyDlg : public CDiagramPropertyDlg
{
public:
    CDynamicPropertyDlg(CWnd* pParent = NULL);
    virtual ~CDynamicPropertyDlg();

    // Override creation to build dialog dynamically
    BOOL Create(UINT nIDTemplate, CWnd* pParentWnd);

    // To be called when a new entity is selected
    virtual void SetValues();

    // Dialog Data
    //{{AFX_DATA(CPropertyDialog)
    enum { IDD = IDD_DIALOG_PROPERTY_DYNAMIC };
    //}}AFX_DATA

protected:
    DECLARE_MESSAGE_MAP()

    afx_msg void OnTextChanged();

    CEdit m_edit; // Example: simple text edit control

    void UpdateEntity();
public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);
};

#endif //_DIAGRAMPROPERTYDIALOG_H_
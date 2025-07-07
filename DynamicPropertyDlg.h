#ifndef _DIAGRAMPROPERTYDIALOG_H_
#define _DIAGRAMPROPERTYDIALOG_H_

#include "../WinProMo/DiagramEditor/DiagramPropertyDlg.h"
#include "resource.h"
#include "PropertyScrollView.h"

class CDynamicPropertyDlg : public CDiagramPropertyDlg
{
public:
    CDynamicPropertyDlg(CWnd* pParent = NULL);
    virtual ~CDynamicPropertyDlg();

    virtual void SetValues();

    void ClearProperties();
    void SetProperties(CObArray* properties);

    // Called externally to rebuild dialog controls for the new properties
    void RebuildControls();
    
    // Override creation to build dialog dynamically
    BOOL Create(UINT nIDTemplate, CWnd* pParentWnd);

    // Dialog Data
    //{{AFX_DATA(CPropertyDialog)
    enum { IDD = IDD_DIALOG_PROPERTY_DYNAMIC };
    //}}AFX_DATA

protected:
    CObArray m_properties; // Array of CPropertyItem*

    
    UINT m_nextCtrlID;
    CPropertyScrollView m_ScrollView;  // the scroll container

    
    int m_nScrollPos;      // Current vertical scroll position
    int m_nTotalHeight;    // Total height of all controls

    // Called when a control changes - updates property value and triggers redraw
    afx_msg void OnPropertyControlChanged(UINT ctrlID);

    DECLARE_MESSAGE_MAP()

public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    virtual BOOL OnInitDialog();
    afx_msg void OnDestroy();
};

#endif //_DIAGRAMPROPERTYDIALOG_H_
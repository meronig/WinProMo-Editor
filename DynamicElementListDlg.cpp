// DynamicElementListDlg.cpp : implementation file
//

#include "StdAfx.h"
#include "DynamicElementListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// CDynamicElementListDlg dialog

IMPLEMENT_DYNAMIC(CDynamicElementListDlg, CDialog)

CDynamicElementListDlg::CDynamicElementListDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(CDynamicElementListDlg::IDD, pParent)
{

}

CDynamicElementListDlg::~CDynamicElementListDlg()
{
}

void CDynamicElementListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDynamicElementListDlg, CDialog)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDynamicElementListDlg message handlers

void CDynamicElementListDlg::OnDestroy()
{
	CRect rect;
	GetWindowRect(&rect);

	AfxGetApp()->WriteProfileInt(_T("ElementListDialog"), _T("Left"), rect.left);
	AfxGetApp()->WriteProfileInt(_T("ElementListDialog"), _T("Top"), rect.top);
	AfxGetApp()->WriteProfileInt(_T("ElementListDialog"), _T("Width"), rect.Width());
	AfxGetApp()->WriteProfileInt(_T("ElementListDialog"), _T("Height"), rect.Height());
	
	CDialog::OnDestroy();

}

BOOL CDynamicElementListDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

    int left = AfxGetApp()->GetProfileInt(_T("ElementListDialog"), _T("Left"), -1);
    int top = AfxGetApp()->GetProfileInt(_T("ElementListDialog"), _T("Top"), -1);
    int width = AfxGetApp()->GetProfileInt(_T("ElementListDialog"), _T("Width"), -1);
    int height = AfxGetApp()->GetProfileInt(_T("ElementListDialog"), _T("Height"), -1);

    if (left != -1 && top != -1 && width > 0 && height > 0)
    {
        CRect desired(left, top, left + width, top + height);

        // Optional: Clamp to virtual screen to avoid placing the dialog off-screen

        CRect virtualScreen;
        virtualScreen.left = GetSystemMetrics(SM_XVIRTUALSCREEN);
        virtualScreen.top = GetSystemMetrics(SM_YVIRTUALSCREEN);
        virtualScreen.right = virtualScreen.left + GetSystemMetrics(SM_CXVIRTUALSCREEN);
        virtualScreen.bottom = virtualScreen.top + GetSystemMetrics(SM_CYVIRTUALSCREEN);

        if (!virtualScreen.IsRectEmpty())
        {
            // Ensure dialog fits at least partially on screen
            if (desired.right > virtualScreen.right)
                desired.OffsetRect(virtualScreen.right - desired.right, 0);
            if (desired.bottom > virtualScreen.bottom)
                desired.OffsetRect(0, virtualScreen.bottom - desired.bottom);
            if (desired.left < virtualScreen.left)
                desired.OffsetRect(virtualScreen.left - desired.left, 0);
            if (desired.top < virtualScreen.top)
                desired.OffsetRect(0, virtualScreen.top - desired.top);
        }

        MoveWindow(desired);

    }

    return TRUE;
}

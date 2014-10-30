// SubmitPaperDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SubmitPaper.h"
#include "SubmitPaperDlg.h"
#include "OpUser.h"
#include "Enroll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubmitPaperDlg dialog

CSubmitPaperDlg::CSubmitPaperDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSubmitPaperDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSubmitPaperDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	pAdminDlg = NULL;
}

void CSubmitPaperDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubmitPaperDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSubmitPaperDlg, CDialog)
	//{{AFX_MSG_MAP(CSubmitPaperDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_LOGIN, OnBtnLogin)
	ON_BN_CLICKED(IDC_BTN_ENROLL, OnBtnEnroll)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubmitPaperDlg message handlers

BOOL CSubmitPaperDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSubmitPaperDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSubmitPaperDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSubmitPaperDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSubmitPaperDlg::OnBtnLogin() 
{
	// TODO: Add your control notification handler code here
	CString strName,strPwd;
	GetDlgItemText(IDC_EDIT_USERNAME, strName);
	if (strName.IsEmpty())
	{
		AfxMessageBox("用户名不能为空");
		return;
	}
	GetDlgItemText(IDC_EDIT_PASSWORD, strPwd);
	if (strPwd.IsEmpty())
	{
		AfxMessageBox("密码不能为空");
		return;
	}
	m_user.SetUserName(strName.GetBuffer(0));
	strName.ReleaseBuffer();
	m_user.SetPassword(strPwd.GetBuffer(0));
	strPwd.ReleaseBuffer();
	COpUser opUser(m_user);
	if (opUser.Verify())
	{
		m_user = opUser.GetUser();
 		pAdminDlg = new CAdminDlg;
 		pAdminDlg->Create(IDD_DLG_ADMIN,this);
		ShowWindow(SW_HIDE);
 		pAdminDlg->pUser = new CUser(m_user);
		pAdminDlg->InitData();
		pAdminDlg->CenterWindow(GetDesktopWindow());
 		pAdminDlg->ShowWindow(SW_SHOWNORMAL);
 		pAdminDlg->Show();
	}
	else
	{
		AfxMessageBox("username or password is error !");
	}
}

void CSubmitPaperDlg::OnBtnEnroll() 
{
	// TODO: Add your control notification handler code here
	CEnroll enrollDlg;
	enrollDlg.DoModal();
}

LRESULT CSubmitPaperDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (message == WM_USER+1)
	{
		OnOK();
	}
	return CDialog::WindowProc(message, wParam, lParam);
}

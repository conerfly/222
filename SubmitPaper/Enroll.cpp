// Enroll.cpp : implementation file
//

#include "stdafx.h"
#include "SubmitPaper.h"
#include "Enroll.h"
#include "User.h"
#include "OpUser.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnroll dialog


CEnroll::CEnroll(CWnd* pParent /*=NULL*/)
	: CDialog(CEnroll::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnroll)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEnroll::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnroll)
	DDX_Control(pDX, IDC_COMBO_ROLE, m_combo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEnroll, CDialog)
	//{{AFX_MSG_MAP(CEnroll)
	ON_BN_CLICKED(IDC_BTN_ENROLL, OnBtnEnroll)
	ON_BN_CLICKED(IDC_BTN_CANCEL, OnBtnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnroll message handlers

void CEnroll::OnBtnEnroll() 
{
	// TODO: Add your control notification handler code here
	CString strName,strPwd,strConfirm,strPro,strMail,strRole;
	GetDlgItemText(IDC_EDIT_USERNAME, strName);
	if (strName.IsEmpty())
	{
		AfxMessageBox("the username could't be null.");
		return;
	}
	GetDlgItemText(IDC_EDIT_PASSWORD, strPwd);
	if (strPwd.IsEmpty())
	{
		AfxMessageBox("the password could't be null.");
		return;
	}
	GetDlgItemText(IDC_EDIT_CONFIRM, strConfirm);
	if (strConfirm.Compare(strPwd)!=0)
	{
		AfxMessageBox("The second password is not the same as the first!");
		return;
	}
	GetDlgItemText(IDC_EDIT_PROFESSION, strPro);
	if (strName.IsEmpty())
	{
		AfxMessageBox("the profession could't be null.");
		return;
	}
	GetDlgItemText(IDC_EDIT_MAIL, strMail);
	if (strPwd.IsEmpty())
	{
		AfxMessageBox("the mail could't be null.");
		return;
	}
	m_combo.GetWindowText(strRole);
	CUser user;
	user.SetUserName(strName.GetBuffer(0));
	user.SetPassword(strPwd.GetBuffer(0));
	user.SetProfession(strPro.GetBuffer(0));
	user.SetMail(strMail.GetBuffer(0));
	user.SetPermission(strRole.GetBuffer(0));
	strName.ReleaseBuffer();
	strPwd.ReleaseBuffer();
	strPro.ReleaseBuffer();
	strMail.ReleaseBuffer();
	strRole.ReleaseBuffer();
	COpUser opUser(user);
	if (opUser.Existed())
	{
		CString temp;
		temp+="username warning: '"+strName;
		temp += "' has existed!";
		AfxMessageBox(temp);
		return;
	}
	if (opUser.Add())
	{
		AfxMessageBox("success!");
		OnOK();
	}
	else
	{
		AfxMessageBox("failed!");
	}
}

void CEnroll::OnBtnCancel() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

BOOL CEnroll::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitDlg();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEnroll::InitDlg()
{
	m_combo.InsertString(0,"admin");
	m_combo.InsertString(1,"chair");
	m_combo.InsertString(2,"member");
	m_combo.InsertString(3,"author");
	m_combo.SetCurSel(3);
	if (strcmp(m_user.GetPermission(),"admin")==0)
	{
		GetDlgItem(IDC_BTN_ENROLL)->SetWindowText("Add User");
	}
	else
	{
		GetDlgItem(IDC_ST_PROFESSION)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_PROFESSION)->ShowWindow(SW_HIDE);
		m_combo.EnableWindow(FALSE);
	}
}

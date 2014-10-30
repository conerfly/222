// DelUser.cpp : implementation file
//

#include "stdafx.h"
#include "submitpaper.h"
#include "DelUser.h"
#include "User.h"
#include "OpUser.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDelUser dialog


CDelUser::CDelUser(CWnd* pParent /*=NULL*/)
	: CDialog(CDelUser::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDelUser)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDelUser::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDelUser)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDelUser, CDialog)
	//{{AFX_MSG_MAP(CDelUser)
	ON_BN_CLICKED(IDC_BTN_DELUSER, OnBtnDeluser)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDelUser message handlers

void CDelUser::OnBtnDeluser() 
{
	// TODO: Add your control notification handler code here
	CString strName;
	GetDlgItemText(IDC_EDIT1,strName);
	if (strName.IsEmpty())
	{
		AfxMessageBox("the username could't be null.");
		return;
	}
	CUser user;
	user.SetUserName(strName.GetBuffer(0));
	strName.ReleaseBuffer();
	COpUser opUser(user);
	if (opUser.Existed())
	{
		CString temp;
		temp+="username warning: '"+strName;
		temp += "' don't existed!";
		AfxMessageBox(temp);
		return;
	}
	if (opUser.Delete())
	{
		AfxMessageBox("success!");
		OnOK();
	}
	else
	{
		AfxMessageBox("failed!");
	}
}

// Notice.cpp : implementation file
//

#include "stdafx.h"
#include "submitpaper.h"
#include "Notice.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNotice dialog


CNotice::CNotice(CWnd* pParent /*=NULL*/)
	: CDialog(CNotice::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNotice)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNotice::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNotice)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNotice, CDialog)
	//{{AFX_MSG_MAP(CNotice)
	ON_BN_CLICKED(IDC_BTN_ADD, OnBtnAdd)
	ON_BN_CLICKED(IDC_BTN_CANCEL, OnBtnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNotice message handlers

void CNotice::OnBtnAdd() 
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_EDIT_NOTICE,m_strNotice);
	m_strNotice.TrimLeft();
	m_strNotice.TrimRight();
	if (m_strNotice.IsEmpty())
	{
		AfxMessageBox("please input notice first.");
		return;
	}
	else
	{
		OnOK();
	}
}

void CNotice::OnBtnCancel() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

BOOL CNotice::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

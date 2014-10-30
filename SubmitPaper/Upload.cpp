// Upload.cpp : implementation file
//

#include "stdafx.h"
#include "submitpaper.h"
#include "Upload.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUpload dialog


CUpload::CUpload(CWnd* pParent /*=NULL*/)
	: CDialog(CUpload::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUpload)
	m_combotype = -1;
	//}}AFX_DATA_INIT
}


void CUpload::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUpload)
	DDX_Control(pDX, IDC_COMBO_CLASS, m_combo);
	DDX_CBIndex(pDX, IDC_COMBO_TYPE, m_combotype);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUpload, CDialog)
	//{{AFX_MSG_MAP(CUpload)
	ON_BN_CLICKED(IDC_BTN_BROWSE, OnBtnBrowse)
	ON_BN_CLICKED(IDC_BTN_CANCEL, OnBtnCancel)
	ON_BN_CLICKED(IDC_BTN_OK, OnBtnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUpload message handlers

void CUpload::OnBtnBrowse() 
{
	// TODO: Add your control notification handler code here
	CFileDialog filedlg(TRUE,"txt","txt",OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"Text Files (*.txt)|*.txt",this);
	if (filedlg.DoModal()==IDOK)
	{
		CString strPath = filedlg.GetFileName();
		SetDlgItemText(IDC_EDIT_PATH,strPath);
	}
}

void CUpload::OnBtnCancel() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CUpload::OnBtnOk() 
{
	// TODO: Add your control notification handler code here
	CString strPath,strTitle,strClass;
	GetDlgItemText(IDC_EDIT_PATH,strPath);
	GetDlgItemText(IDC_EDIT_TITLE,strTitle);
	
	if (strPath.IsEmpty())
	{
		AfxMessageBox("please input filepath");
		return;
	}
	strTitle.TrimLeft();
	strTitle.TrimRight();
	if (strTitle.IsEmpty())
	{
		AfxMessageBox("please input filepath");
		return;
	}
	m_combo.GetWindowText(strClass);

}

BOOL CUpload::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
//	m_combotype.InsertString(0,"upload for remark");
//	m_combotype.InsertString(1,"upload for save");
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

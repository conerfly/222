// AdminDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SubmitPaper.h"
#include "AdminDlg.h"
#include "Notice.h"
#include "Enroll.h"
#include "Upload.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdminDlg dialog


CAdminDlg::CAdminDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdminDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdminDlg)
	//}}AFX_DATA_INIT

}


void CAdminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdminDlg)
	DDX_Control(pDX, IDC_COMBO_SEARCH, m_combosearch);
	DDX_Control(pDX, IDC_BTN_ADD, m_btnadd);
	DDX_Control(pDX, IDC_EDIT_COMMENT, m_editcomment);
	DDX_Control(pDX, IDC_EDIT_PAPER, m_editpaper);
	DDX_Control(pDX, IDC_EDIT_NOTICE, m_editnotice);
	DDX_Control(pDX, IDC_COMBO_PROFESSION, m_combo);
	DDX_Control(pDX, IDC_LIST_PAPER, m_listctrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAdminDlg, CDialog)
	//{{AFX_MSG_MAP(CAdminDlg)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTN_LASTNOTICE, OnBtnLastnotice)
	ON_BN_CLICKED(IDC_BTN_NEXTNOTICE, OnBtnNextnotice)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_PAPER, OnDblclkListPaper)
	ON_BN_CLICKED(IDC_BTN_ADD, OnBtnAdd)
	ON_BN_CLICKED(IDC_BTN_REMOVE, OnBtnRemove)
	ON_BN_CLICKED(IDC_BTN_SEARCH, OnBtnSearch)
	ON_BN_CLICKED(IDC_BTN_ADDUSER, OnBtnAdduser)
	ON_BN_CLICKED(IDC_BTN_DELUSER, OnBtnDeluser)
	ON_CBN_SELCHANGE(IDC_COMBO_PROFESSION, OnSelchangeComboProfession)
	ON_BN_CLICKED(IDC_BTN_REMARK, OnBtnRemark)
	ON_BN_CLICKED(IDC_BTN_SAVE, OnBtnSave)
	ON_BN_CLICKED(IDC_BTN_UPLOAD, OnBtnUpload)
	ON_BN_CLICKED(IDC_BTN_DOWNLOAD, OnBtnDownload)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdminDlg message handlers

void CAdminDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	GetParent()->SendMessage(WM_USER+1,0,0);
	return;
	CDialog::OnClose();
}

void CAdminDlg::OnBtnLastnotice() 
{
	// TODO: Add your control notification handler code here
	CRect rc1,rc2,rc3,rc4;
	m_editnotice.GetWindowRect(rc1);
	m_editcomment.GetWindowRect(rc2);
 	m_listctrl.GetWindowRect(rc3);
// 	m_editnotice.GetWindowRect(rc1);
	CString s;
	s.Format("%d:%d:%d:%d\r\n%d:%d:%d:%d\r\n%d:%d:%d:%d\r\n",
		rc1.left,rc1.top,rc1.right,rc1.bottom,
		rc2.left,rc2.top,rc2.right,rc2.bottom,
		rc3.left,rc3.top,rc3.right,rc3.bottom);
	AfxMessageBox(s);
	return;
	if (ActCurNum-1<0)
	{
		GetDlgItem(IDC_BTN_LASTNOTICE)->EnableWindow(FALSE);
		return;
	}
	ShowActivity(vecAct[--ActCurNum]);
	GetDlgItem(IDC_BTN_NEXTNOTICE)->EnableWindow(TRUE);
}

void CAdminDlg::OnBtnNextnotice() 
{
	// TODO: Add your control notification handler code here
	if (ActCurNum+1>vecAct.size()-1)
	{
		GetDlgItem(IDC_BTN_NEXTNOTICE)->EnableWindow(FALSE);
		return;
	}
	ShowActivity(vecAct[++ActCurNum]);
	GetDlgItem(IDC_BTN_LASTNOTICE)->EnableWindow(TRUE);
}

void CAdminDlg::InitListCtrl()
{
		m_listctrl.InsertColumn(0, "NO.", LVCFMT_LEFT, 40);
		m_listctrl.InsertColumn(1, "title", LVCFMT_CENTER, 200);
		m_listctrl.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);//|LVS_EX_GRIDLINES
}

BOOL CAdminDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitListCtrl();
	InitCombo();
	InitAllCtrl();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAdminDlg::InitCombo()
{
	m_combo.InsertString(0,"All");
	m_combo.InsertString(1,"wait");
	m_combo.InsertString(2,"Remarked");
	m_combo.InsertString(3,"Accepted");
	m_combo.InsertString(4,"extra");
	m_combo.SetCurSel(0);
	m_combosearch.InsertString(0,"According to the title");
	m_combosearch.InsertString(1,"According to the uploadtime");
	m_combosearch.SetCurSel(0);
}

void CAdminDlg::InitData()
{
	pActView = new CViewActivity;
	pPaperView = new CViewPaper;
	pActView->GetAllActivity(vecAct);
	pPaperView->GetAllPaper(vecPaper,*pUser);
	ActCurNum = 0;
	bDelay = false;
	pLastPaper = NULL;
}

void CAdminDlg::Show()
{
	if (vecAct.size()>0)
	{
		ShowActivity(vecAct[0]);
	}
	ShowPaperList();
	ShowPaper(vecPaper[0]);
	ShowPernsonCtrl();
	CheckDelay();
}

void CAdminDlg::ShowActivity( CActivity *p )
{
	CString s;
	s.Format("System Nnotice\t\t\t\tRelease Time:\t%s\r\n\t%s",p->GetReleaseTime(),p->GetContent());
	m_editnotice.SetWindowText(s);
}

void CAdminDlg::ShowPaper( CPaper *p )
{
	SetDlgItemText(IDC_ST_AUTHOR,p->GetAuthorName());
	SetDlgItemText(IDC_ST_DEFAULT,p->GetAdvisorName());
	SetDlgItemText(IDC_ST_CURRENT,p->GetNewAdvisor());
	SetDlgItemText(IDC_ST_REMARK,p->GetRemarkTime());
	SetDlgItemText(IDC_ST_UPLOAD,p->GetUploadTime());
	SetDlgItemText(IDC_ST_DEADLINE,p->GetDeadLine());
	CString s;
	if (p->GetDays()<0)
	{
		s="Delay: no";
	}
	else if (p->GetDays()<=7) 
	{
		bDelay = true;
		p->SetState("extra");
		s.Format("Extra: %d days",p->GetDays());
	}
	else
	{
		if (p->GetDays()>7)
		{
			p->SetState("change");
			pPaperView->UpdateNewAdvisor(*p);
		}
		s.Format("Delay: %d days",p->GetDays());
	}
	SetDlgItemText(IDC_ST_DELAY,s);
	s.Format("State: %s",p->GetState());
	SetDlgItemText(IDC_ST_STATE,s);
	m_editpaper.SetWindowText(p->GetContent());
	m_editcomment.SetWindowText(p->GetComment());
}

void CAdminDlg::ShowPaperList()
{
	CString s;
	for (int i=0; i<vecPaper.size(); i++)
	{
		ShowListItem(vecPaper[i]);
	}
	m_listctrl.SetItemState(0,LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
}


void CAdminDlg::OnDblclkListPaper(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	NM_LISTVIEW *pListView = (NM_LISTVIEW *)pNMHDR;
	int nRow = pListView->iItem;
	CPaper *pPaper = (CPaper *)m_listctrl.GetItemData(nRow);
	CString s;
	if (pLastPaper != NULL)
	{
		pPaperView->ClearPaperData(*pLastPaper);
	}
	pPaperView->GetPaperData(*pPaper);
	ShowPaper(pPaper);	
	pLastPaper = pPaper;
	*pResult = 0;
}

void CAdminDlg::InitAllCtrl()
{
	GetDlgItem(IDC_BTN_LASTNOTICE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_SAVE)->EnableWindow(FALSE);
	//ADMIN
	GetDlgItem(IDC_BTN_ADDUSER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BTN_DELUSER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BTN_ADD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BTN_REMOVE)->ShowWindow(SW_HIDE);
	//CHAIR
	GetDlgItem(IDC_BTN_SUBMIT)->ShowWindow(SW_HIDE);
	//MEMBER
	GetDlgItem(IDC_BTN_REMARK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BTN_SAVE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BTN_DOWNLOAD)->ShowWindow(SW_HIDE);
	//AUTHOR
	GetDlgItem(IDC_BTN_UPLOAD)->ShowWindow(SW_HIDE);
}

void CAdminDlg::OnBtnAdd() 
{
	// TODO: Add your control notification handler code here
	if (IDYES == MessageBox("Do you want to add a notice?","tips",MB_ICONQUESTION|MB_YESNO))
	{
		CNotice dlg;
		if (IDOK==dlg.DoModal())
		{
			CActivity *p = new CActivity;
			p->SetContent(dlg.m_strNotice.GetBuffer(0));
			dlg.m_strNotice.ReleaseBuffer();
			pActView->AddNotice(*p);
			vecAct.push_back(p);
			ActCurNum = vecAct.size()-1;
			ShowActivity(p);
			GetDlgItem(IDC_BTN_LASTNOTICE)->EnableWindow(TRUE);
			GetDlgItem(IDC_BTN_NEXTNOTICE)->EnableWindow(FALSE);
		}
		
	}
}

void CAdminDlg::OnBtnRemove() 
{
	// TODO: Add your control notification handler code here
	if (IDYES == MessageBox("are you sure to remove this notice?","warning",MB_ICONQUESTION|MB_YESNO))
	{
		CActivity *p = vecAct[ActCurNum];
		if (ActCurNum+1==vecAct.size())
		{
			OnBtnLastnotice();
		}
		else
		{
			OnBtnNextnotice();
		}
		pActView->RemoveNotice(*p);
		vector<CActivity*>::iterator iter;
		for (iter=vecAct.begin();iter!=vecAct.end();iter++)
		{
			if (*iter = p)
			{
				vecAct.erase(iter);
				break;
			}

		}
	}
	
}


bool CAdminDlg::SearchByTitle(char *strTitle)
{
	int num = m_listctrl.GetItemCount();
	CString s;
	for (int i=0; i<num; i++)
	{
		CPaper *pPaper = (CPaper*)m_listctrl.GetItemData(i);
		s =  pPaper->GetTitle();
		if (s.Find(strTitle) != -1)
		{
			
			if (pLastPaper != NULL)
			{
				pPaperView->ClearPaperData(*pLastPaper);
			}
			pPaperView->GetPaperData(*pPaper);
			ShowPaper(pPaper);	
			pLastPaper = pPaper;
			m_listctrl.SetFocus();
			m_listctrl.SetItemState(i, LVIS_SELECTED| LVIS_FOCUSED, LVIS_SELECTED| LVIS_FOCUSED);
			return true;
		}
	}
	AfxMessageBox("can't find the paper");
	return false;
}

bool CAdminDlg::SearchByDate(char *strDate)
{
	int num = m_listctrl.GetItemCount();
	CString s;
	for (int i=0; i<num; i++)
	{
		CPaper *pPaper = (CPaper*)m_listctrl.GetItemData(i);
		s =  pPaper->GetUploadTime();
		if (s.Find(strDate) != -1)
		{
			
			if (pLastPaper != NULL)
			{
				pPaperView->ClearPaperData(*pLastPaper);
			}
			pPaperView->GetPaperData(*pPaper);
			ShowPaper(pPaper);	
			pLastPaper = pPaper;
			m_listctrl.SetFocus();
			m_listctrl.SetItemState(i, LVIS_SELECTED| LVIS_FOCUSED, LVIS_SELECTED| LVIS_FOCUSED);
			return true;
		}
	}
	AfxMessageBox("can't find the paper");
	return false;
}

void CAdminDlg::OnBtnSearch() 
{
	// TODO: Add your control notification handler code here
	m_combosearch.SetFocus();
	int n = m_combosearch.GetCurSel();	
	CString s;
	GetDlgItemText(IDC_EDIT_SEARCH,s);
	
	if (n == 0)
	{	
		SearchByTitle(s.GetBuffer(0));
	}
	else if (n == 1)
	{
		SearchByDate(s.GetBuffer(0));
	}
	s.ReleaseBuffer();
}

void CAdminDlg::ShowPernsonCtrl()
{
	CString s = pUser->GetPermission();
	if (s.Compare("admin")==0)
	{
		ShowAdminCtrl();
	}
	else if (s.Compare("chair")==0)
	{
		ShowChairCtrl();
	}
	else if (s.Compare("member")==0)
	{
		ShowMemberCtrl();
	}
	else
	{
		ShowAuthorCtrl();
	}
}

void CAdminDlg::ShowAdminCtrl()
{
	GetDlgItem(IDC_BTN_ADDUSER)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTN_DELUSER)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTN_ADD)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTN_REMOVE)->ShowWindow(SW_SHOW);
	SetCommentWidth(240);
}

void CAdminDlg::ShowChairCtrl()
{
	CRect rc;
	GetDlgItem(IDC_BTN_SUBMIT)->GetWindowRect(rc);
	ScreenToClient(&rc);
	GetDlgItem(IDC_BTN_SUBMIT)->SetWindowPos(&wndNoTopMost,rc.left+180,rc.top,0,0,SWP_NOSIZE|SWP_NOZORDER|SWP_SHOWWINDOW);
/*	GetDlgItem(IDC_BTN_SUBMIT)->ShowWindow(SW_SHOW);*/
	SetCommentWidth(180);
	SetActivityCtrl();
}

void CAdminDlg::ShowMemberCtrl()
{
	GetDlgItem(IDC_BTN_REMARK)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTN_SAVE)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTN_DOWNLOAD)->ShowWindow(SW_SHOW);
	SetCommentWidth(100);
	SetActivityCtrl();
	CRect rc;
	GetDlgItem(IDC_BTN_REMARK)->GetWindowRect(rc);
	ScreenToClient(&rc);
	GetDlgItem(IDC_BTN_SAVE)->SetWindowPos(&wndNoTopMost,rc.left+50,rc.top,0,0,SWP_NOSIZE|SWP_NOZORDER|SWP_SHOWWINDOW);
}

void CAdminDlg::ShowAuthorCtrl()
{
	GetDlgItem(IDC_BTN_UPLOAD)->ShowWindow(SW_SHOW);
	SetActivityCtrl();
	SetCommentWidth(100);
}

void CAdminDlg::OnBtnAdduser() 
{
	// TODO: Add your control notification handler code here
	CEnroll dlg;
	dlg.m_user = *pUser;
	dlg.DoModal();

}

void CAdminDlg::OnBtnDeluser() 
{
	// TODO: Add your control notification handler code here
	
}

void CAdminDlg::OnSelchangeComboProfession() 
{
	// TODO: Add your control notification handler code here
	m_listctrl.DeleteAllItems();
	int n = m_combo.GetCurSel();
	switch(n)
	{
	case 0:
		ShowPaperList();
		break;
	case 1:
		ShowWaitList();
		break;
	case 2:
		ShowRemarkList();
		break;
	case 3:
		ShowAcceptList();
		break;
	case 4:
		ShowExtraList();
		break;
	}
//	CPaper *p = (CPaper*)m_listctrl.GetItemData(0);
}

void CAdminDlg::CheckDelay()
{
	if (bDelay)
	{	
		m_listctrl.DeleteAllItems();
		ShowExtraList();
		CPaper *pPaper = (CPaper*)m_listctrl.GetItemData(0);
		if (pLastPaper != NULL)
		{
			pPaperView->ClearPaperData(*pLastPaper);
		}
		pPaperView->GetPaperData(*pPaper);
		ShowPaper(pPaper);	
		pLastPaper = pPaper;
		m_combo.SetCurSel(4);
		m_listctrl.SetFocus();
		m_listctrl.SetItemState(0, LVIS_SELECTED| LVIS_FOCUSED, LVIS_SELECTED| LVIS_FOCUSED);
		AfxMessageBox("attention: you have some papers over time!");
	}
}

void CAdminDlg::ShowWaitList()
{
	CPaper *pPaper = NULL;
	vector<CPaper*>::iterator iter;
	for (iter=vecPaper.begin();iter!=vecPaper.end();iter++)
	{
		pPaper = *iter;
		if (strcmp("wait",pPaper->GetState())==0)
		{
			ShowListItem(pPaper);
		}
		
	}
}

void CAdminDlg::ShowRemarkList()
{
	CPaper *pPaper = NULL;
	vector<CPaper*>::iterator iter;
	for (iter=vecPaper.begin();iter!=vecPaper.end();iter++)
	{
		pPaper = *iter;
		if (strcmp("remarked",pPaper->GetState())==0)
		{
			ShowListItem(pPaper);
		}
		
	}
}

void CAdminDlg::ShowAcceptList()
{
	CPaper *pPaper = NULL;
	vector<CPaper*>::iterator iter;
	for (iter=vecPaper.begin();iter!=vecPaper.end();iter++)
	{
		pPaper = *iter;
		if (strcmp("accepted",pPaper->GetState())==0)
		{
			ShowListItem(pPaper);
		}
		
	}
}

void CAdminDlg::ShowExtraList()
{
	CPaper *pPaper = NULL;
	vector<CPaper*>::iterator iter;
	for (iter=vecPaper.begin();iter!=vecPaper.end();iter++)
	{
		pPaper = *iter;
		if (strcmp("extra",pPaper->GetState())==0)
		{
			ShowListItem(pPaper);
		}
		
	}
}

void CAdminDlg::ShowListItem( CPaper *p )
{
	int i = m_listctrl.GetItemCount();
	CString s;
	s.Format("%d",i+1);
	m_listctrl.InsertItem(i,NULL);
	m_listctrl.SetItemText(i,0,s);
	m_listctrl.SetItemText(i,1,p->GetTitle());
	m_listctrl.SetItemData(i,(DWORD)p);
}

void CAdminDlg::OnBtnRemark() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BTN_REMARK)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_SAVE)->EnableWindow(TRUE);
	m_editcomment.SetReadOnly(FALSE);
}

void CAdminDlg::OnBtnSave() 
{
	// TODO: Add your control notification handler code here
	
	CString s;
	m_editcomment.GetWindowText(s);
	s.TrimRight();
	s.TrimLeft();
	if (s.IsEmpty())
	{
		AfxMessageBox("please input remark content!");
		return;
	}
	else
	{
		pLastPaper->SetComment(s.GetBuffer(0));
		s.ReleaseBuffer();
		if (pPaperView->UpdateComment(*pLastPaper))
		{
			AfxMessageBox("remark success!");
		}
	}
	GetDlgItem(IDC_BTN_REMARK)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_SAVE)->EnableWindow(FALSE);
	m_editcomment.SetReadOnly(TRUE);
	
}

void CAdminDlg::OnBtnUpload() 
{
	// TODO: Add your control notification handler code here
	CUpload updlg;
	updlg.m_pPaper = pLastPaper;
}

void CAdminDlg::OnBtnDownload() 
{
	// TODO: Add your control notification handler code here
	
}

void CAdminDlg::SetCommentWidth( int n )
{
	CRect rc;
	m_editcomment.GetClientRect(rc);
	m_editcomment.SetWindowPos(&wndNoTopMost,0,0,rc.Width()+n,rc.Height(),SWP_NOMOVE|SWP_NOZORDER);
}

void CAdminDlg::SetActivityCtrl()
{
	CRect rc;
	m_editnotice.GetClientRect(rc);
	m_editnotice.SetWindowPos(&wndNoTopMost,0,0,rc.Width()+100,rc.Height(),SWP_NOMOVE|SWP_NOZORDER);
	GetDlgItem(IDC_BTN_LASTNOTICE)->GetWindowRect(rc);
	ScreenToClient(&rc);
	GetDlgItem(IDC_BTN_LASTNOTICE)->SetWindowPos(&wndNoTopMost,rc.left+100,rc.top,0,0,SWP_NOSIZE|SWP_NOZORDER);
	GetDlgItem(IDC_BTN_NEXTNOTICE)->GetWindowRect(rc);
	ScreenToClient(&rc);
	GetDlgItem(IDC_BTN_NEXTNOTICE)->SetWindowPos(&wndNoTopMost,rc.left+100,rc.top,0,0,SWP_NOSIZE|SWP_NOZORDER);
}

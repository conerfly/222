#if !defined(AFX_ADMINDLG_H__55560A47_1A32_4021_B3BD_7CCE9E1BBA82__INCLUDED_)
#define AFX_ADMINDLG_H__55560A47_1A32_4021_B3BD_7CCE9E1BBA82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ViewActivity.h"
#include "ViewPaper.h"
#include "ViewUser.h"

// AdminDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAdminDlg dialog

class CAdminDlg : public CDialog
{
// Construction
public:
	CAdminDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAdminDlg)
	enum { IDD = IDD_DLG_ADMIN };
	CComboBox	m_combosearch;
	CButton	m_btnadd;
	CEdit	m_editcomment;
	CEdit	m_editpaper;
	CEdit	m_editnotice;
	CComboBox	m_combo;
	CListCtrl	m_listctrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdminDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAdminDlg)
	afx_msg void OnClose();
	afx_msg void OnBtnLastnotice();
	afx_msg void OnBtnNextnotice();
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkListPaper(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtnAdd();
	afx_msg void OnBtnRemove();
	afx_msg void OnBtnSearch();
	afx_msg void OnBtnAdduser();
	afx_msg void OnBtnDeluser();
	afx_msg void OnSelchangeComboProfession();
	afx_msg void OnBtnRemark();
	afx_msg void OnBtnSave();
	afx_msg void OnBtnUpload();
	afx_msg void OnBtnDownload();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	void InitListCtrl();
	void InitCombo();
	void InitData();
	void InitAllCtrl();
	void Show();
	void ShowActivity(CActivity *p );;
	void ShowPaper(CPaper *p );
	void ShowListItem(CPaper *p );
	void ShowPaperList();
	void ShowWaitList();
	void ShowRemarkList();
	void ShowAcceptList();
	void ShowExtraList();
	void ShowPernsonCtrl();
	void ShowAdminCtrl();
	void ShowChairCtrl();
	void ShowMemberCtrl();
	void ShowAuthorCtrl();
	bool SearchByTitle(char *strTitle);
	bool SearchByDate(char *strDate);
	bool bDelay;
	void CheckDelay();
	void SetCommentWidth(int n);
	void SetActivityCtrl();
	CViewActivity *pActView;
	CViewPaper *pPaperView;
	CViewUser *pUserView;
	CUser *pUser;
	CPaper *pLastPaper;
	vector<CActivity*>vecAct;
	vector<CPaper*>vecPaper;
	vector<CUser*>vecUser;
	int ActCurNum;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADMINDLG_H__55560A47_1A32_4021_B3BD_7CCE9E1BBA82__INCLUDED_)

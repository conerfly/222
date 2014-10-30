// SubmitPaperDlg.h : header file
//

#if !defined(AFX_SUBMITPAPERDLG_H__6621D129_6D3D_4619_93E5_9DEBDDB946A1__INCLUDED_)
#define AFX_SUBMITPAPERDLG_H__6621D129_6D3D_4619_93E5_9DEBDDB946A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSubmitPaperDlg dialog
#include "User.h"
#include "Paper.h"
#include "Activity.h"
#include "AdoConn.h"
#include "AdminDlg.h"
#include <VECTOR>
using namespace std;
class CSubmitPaperDlg : public CDialog
{
// Construction
public:
	CSubmitPaperDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSubmitPaperDlg)
	enum { IDD = IDD_SUBMITPAPER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubmitPaperDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSubmitPaperDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnLogin();
	afx_msg void OnBtnEnroll();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	
	CUser m_user;
	CAdminDlg *pAdminDlg;
	vector<CPaper*> m_vecPaper;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBMITPAPERDLG_H__6621D129_6D3D_4619_93E5_9DEBDDB946A1__INCLUDED_)

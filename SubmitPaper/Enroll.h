#if !defined(AFX_ENROLL_H__77A1678B_8F15_427A_9A39_CAE331CC76FF__INCLUDED_)
#define AFX_ENROLL_H__77A1678B_8F15_427A_9A39_CAE331CC76FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "User.h"
// Enroll.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEnroll dialog

class CEnroll : public CDialog
{
// Construction
public:
	CEnroll(CWnd* pParent = NULL);   // standard constructor
	CUser m_user;
	void InitDlg();
// Dialog Data
	//{{AFX_DATA(CEnroll)
	enum { IDD = IDD_DLG_ENROLL };
	CComboBox	m_combo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnroll)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEnroll)
	afx_msg void OnBtnEnroll();
	afx_msg void OnBtnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENROLL_H__77A1678B_8F15_427A_9A39_CAE331CC76FF__INCLUDED_)

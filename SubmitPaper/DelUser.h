#if !defined(AFX_DELUSER_H__34720B9D_6601_477B_B16A_C52F7F90CB90__INCLUDED_)
#define AFX_DELUSER_H__34720B9D_6601_477B_B16A_C52F7F90CB90__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DelUser.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDelUser dialog

class CDelUser : public CDialog
{
// Construction
public:
	CDelUser(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDelUser)
	enum { IDD = IDD_DLG_DELUSER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDelUser)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDelUser)
	afx_msg void OnBtnDeluser();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELUSER_H__34720B9D_6601_477B_B16A_C52F7F90CB90__INCLUDED_)

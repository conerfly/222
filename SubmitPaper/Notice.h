#if !defined(AFX_NOTICE_H__FE615C5F_08A5_4173_9574_2D3B9D04EC1F__INCLUDED_)
#define AFX_NOTICE_H__FE615C5F_08A5_4173_9574_2D3B9D04EC1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Notice.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNotice dialog

class CNotice : public CDialog
{
// Construction
public:
	CNotice(CWnd* pParent = NULL);   // standard constructor
	CString m_strNotice;
// Dialog Data
	//{{AFX_DATA(CNotice)
	enum { IDD = IDD_DLG_NOTICE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNotice)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNotice)
	afx_msg void OnBtnAdd();
	afx_msg void OnBtnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTICE_H__FE615C5F_08A5_4173_9574_2D3B9D04EC1F__INCLUDED_)

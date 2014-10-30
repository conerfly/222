#if !defined(AFX_UPLOAD_H__8B0672D4_6223_48DD_B168_F90560CAD350__INCLUDED_)
#define AFX_UPLOAD_H__8B0672D4_6223_48DD_B168_F90560CAD350__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Paper.h"
// Upload.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUpload dialog

class CUpload : public CDialog
{
// Construction
public:
	CUpload(CWnd* pParent = NULL);   // standard constructor
	CPaper *m_pPaper;
// Dialog Data
	//{{AFX_DATA(CUpload)
	enum { IDD = IDD_DLG_UPLOAD };
	CComboBox	m_combo;
	int		m_combotype;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUpload)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUpload)
	afx_msg void OnBtnBrowse();
	afx_msg void OnBtnCancel();
	afx_msg void OnBtnOk();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPLOAD_H__8B0672D4_6223_48DD_B168_F90560CAD350__INCLUDED_)

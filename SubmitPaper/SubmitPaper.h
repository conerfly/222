// SubmitPaper.h : main header file for the SUBMITPAPER application
//

#if !defined(AFX_SUBMITPAPER_H__CA11C9EB_495E_4915_AC64_ED8743511A57__INCLUDED_)
#define AFX_SUBMITPAPER_H__CA11C9EB_495E_4915_AC64_ED8743511A57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSubmitPaperApp:
// See SubmitPaper.cpp for the implementation of this class
//

class CSubmitPaperApp : public CWinApp
{
public:
	CSubmitPaperApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubmitPaperApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSubmitPaperApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBMITPAPER_H__CA11C9EB_495E_4915_AC64_ED8743511A57__INCLUDED_)

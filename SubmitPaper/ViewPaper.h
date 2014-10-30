// ViewPaper.h: interface for the CViewPaper class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWPAPER_H__841A608C_226D_4967_8F88_FCACF9511B4E__INCLUDED_)
#define AFX_VIEWPAPER_H__841A608C_226D_4967_8F88_FCACF9511B4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <VECTOR>
#include "Paper.h"
#include "User.h"
#include "OpPaper.h"
using namespace std;
class CViewPaper  
{
public:
	CViewPaper();
	virtual ~CViewPaper();
	bool UpdateNewAdvisor(CPaper &p);
	bool UpdateComment(CPaper &p );
	void GetPaperData(CPaper &p );
	void ClearPaperData(const CPaper &p);
	void GetAllPaper(vector<CPaper*>&vec,CUser &u);
	COpPaper opPaper;
};

#endif // !defined(AFX_VIEWPAPER_H__841A608C_226D_4967_8F88_FCACF9511B4E__INCLUDED_)

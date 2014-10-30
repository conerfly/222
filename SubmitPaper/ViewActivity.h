// ViewActivity.h: interface for the CViewActivity class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWACTIVITY_H__0FCCEE90_462D_49C4_A677_6B6662A9793A__INCLUDED_)
#define AFX_VIEWACTIVITY_H__0FCCEE90_462D_49C4_A677_6B6662A9793A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "OpActivity.h"

class CViewActivity  
{
public:
	CViewActivity();
	CViewActivity(const COpActivity &op);
	virtual ~CViewActivity();

 	COpActivity opAct;
	void RemoveNotice(const CActivity &act);
	void AddNotice(CActivity &act);
	void UpdateNotice(const CActivity &act);
	void GetAllActivity(vector<CActivity*>&vec);
// 	vector<CActivity *>vecActivity;
};

#endif // !defined(AFX_VIEWACTIVITY_H__0FCCEE90_462D_49C4_A677_6B6662A9793A__INCLUDED_)

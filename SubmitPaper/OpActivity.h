// OpActivity.h: interface for the COpActivity class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPACTIVITY_H__1BD30DE3_49E5_47CF_A5E6_6ADB8B6AA510__INCLUDED_)
#define AFX_OPACTIVITY_H__1BD30DE3_49E5_47CF_A5E6_6ADB8B6AA510__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Activity.h"
#include <vector>
using namespace std;
class COpActivity  
{
public:
	COpActivity();
	virtual ~COpActivity();
	bool Add();
	bool Delete();
	bool Update();
	void SetActivity(const CActivity &act);
	CActivity &GetActivity();
	void  GetAllActivity(vector<CActivity *> &vecActivity);
	int m_CurNum;
	int m_TotalNum;
	CActivity m_Activity;
};

#endif // !defined(AFX_OPACTIVITY_H__1BD30DE3_49E5_47CF_A5E6_6ADB8B6AA510__INCLUDED_)

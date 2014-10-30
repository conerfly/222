// OpUser.h: interface for the COpUser class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPUSER_H__7E115346_0FBA_4504_AFAA_9A81796CFA0D__INCLUDED_)
#define AFX_OPUSER_H__7E115346_0FBA_4504_AFAA_9A81796CFA0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "User.h"
class COpUser  
{
public:
	COpUser();
	COpUser(const CUser &u);
	virtual ~COpUser();
public:
	bool Add();
	bool Delete();
	bool Verify();
	bool Existed();
	bool Update();
	void SetUser(const CUser &u);
	int GetUserNum();
	CUser &GetUser();
private:
	CUser user;
};

#endif // !defined(AFX_OPUSER_H__7E115346_0FBA_4504_AFAA_9A81796CFA0D__INCLUDED_)

// Activity.h: interface for the CActivity class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACTIVITY_H__C370413B_74F0_4F6E_BE0F_D96A8E3DC16C__INCLUDED_)
#define AFX_ACTIVITY_H__C370413B_74F0_4F6E_BE0F_D96A8E3DC16C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CActivity  
{
public:
	CActivity();
	virtual ~CActivity();
	CActivity(const CActivity &act);
	void SetAid(int id);
	void SetContent(char *s);
	void SetReleaseTime(char *s);
	int GetAid();
	char *GetContent();
	char *GetReleaseTime();
private:
	int aid;
	char *pContent;
	char releasetime[50];

};

#endif // !defined(AFX_ACTIVITY_H__C370413B_74F0_4F6E_BE0F_D96A8E3DC16C__INCLUDED_)

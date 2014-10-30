// User.h: interface for the CUser class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USER_H__03D856FC_1F33_45ED_8570_46CE02DBF93A__INCLUDED_)
#define AFX_USER_H__03D856FC_1F33_45ED_8570_46CE02DBF93A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUser  
{
public:
	CUser();
	virtual ~CUser();
	CUser(const CUser &user);
	CUser&operator=(const CUser &user);
	void SetUserName(char *s);
	void SetPassword(char *s);
	void SetPermission(char *s);
	void SetProfession(char *s);
	void SetMail(char *s);
	void SetEnrollTime(char *s);
	void SetLoginTime(char *s);	
	char *GetUserName();
	char *GetPassword();
	char *GetPermission();
	char *GetProfession();
	char *GetMail();
	char *GetEnrollTime();
	char *GetLoginTime();
private:
	char username[20];
	char password[20];
	char permission[10];
	char profession[50];
	char mail[50];
	char enrolltime[20];
	char logintime[20];

};

#endif // !defined(AFX_USER_H__03D856FC_1F33_45ED_8570_46CE02DBF93A__INCLUDED_)

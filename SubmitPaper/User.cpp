// User.cpp: implementation of the CUser class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SubmitPaper.h"
#include "User.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CUser::CUser()
{
	memset(username, 0, sizeof(username));
	memset(password, 0, sizeof(password));
	memset(mail, 0, sizeof(mail));
	memset(permission, 0, sizeof(permission));
	memset(profession, 0, sizeof(profession));
	memset(enrolltime, 0, sizeof(enrolltime));
	memset(logintime, 0, sizeof(logintime));
}

CUser::CUser( const CUser &user )
{
	strcpy(username, user.username);
	strcpy(password, user.password);
	strcpy(permission, user.permission);
	strcpy(mail, user.mail);
	strcpy(enrolltime, user.enrolltime);
	strcpy(logintime, user.logintime);
}

CUser::~CUser()
{

}

void CUser::SetUserName( char *s )
{
	strcpy(username, s);
}

void CUser::SetPermission( char *s )
{
	strcpy(permission, s);
}

void CUser::SetProfession( char *s )
{
	strcpy(profession, s);
}

void CUser::SetPassword(char *s)
{
	strcpy(password, s);
}

void CUser::SetMail(char *s)
{
	strcpy(mail, s);
}

void CUser::SetEnrollTime(char *s)
{
	strcpy(enrolltime, s);
}
void CUser::SetLoginTime(char *s)
{
	strcpy(logintime, s);
}



char *CUser::GetUserName()
{
	return username;
}

char *CUser::GetPermission()
{
	return permission;
}

char *CUser::GetProfession()
{
	return profession;
}

char *CUser::GetPassword()
{

	return password;
}

char *CUser::GetMail()
{
	return mail;
}

char *CUser::GetEnrollTime()
{
	return enrolltime;
}

char *CUser::GetLoginTime()
{
	return logintime;
}



CUser& CUser::operator=( const CUser &user )
{
	strcpy(username, user.username);
	strcpy(password, user.password);
	strcpy(permission, user.permission);
	strcpy(profession, user.profession);
	strcpy(mail, user.mail);
	strcpy(enrolltime, user.enrolltime);
	strcpy(logintime, user.logintime);
	return *this;
}

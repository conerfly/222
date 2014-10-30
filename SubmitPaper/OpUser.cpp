// OpUser.cpp: implementation of the COpUser class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SubmitPaper.h"
#include "OpUser.h"
#include "AdoConn.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COpUser::COpUser()
{

}

COpUser::COpUser( const CUser &u )
{
	user = u;
}

COpUser::~COpUser()
{

}

bool COpUser::Add()
{
	ADOConn con;
	CString s;
	CString temp = "','";
	s = "insert into Login(username,password,permission,profession,mail,enrolltime,logintime) values('";
	s += user.GetUserName() + temp;
	s += user.GetPassword() + temp;
	s += user.GetPermission() + temp;
	s += user.GetProfession() + temp;
	s += user.GetMail();
	s += "',";
	s += "getdate(),";
	s += "getdate() )";
	bool b = con.ExecuteSQL((_bstr_t)s);
	con.ExitADOconn();
	return b;
}

bool COpUser::Delete()
{
	ADOConn con;
	CString s;
	s = "delete Login where username='";
	s += user.GetUserName();
	s += "'";
	bool b = con.ExecuteSQL((_bstr_t)s);
	con.ExitADOconn();
	return b;
}

bool COpUser::Existed()
{
	ADOConn con;
	CString s;
	char szText[40] = {0};
	s = "select * from Login where username = '";
	s += user.GetUserName();
	s += "'";
	con.GetRecordset((_bstr_t)s);
	bool b = true;
	if (con.m_pRecordset->adoEOF)
	{
		b = false;
	}
	con.ExitADOconn();
	return b;
}

bool COpUser::Verify()
{
	ADOConn con;
	CString s;
	s = "select * from Login where username = '";
	s += user.GetUserName();
	s += "' and password = '";
	s += user.GetPassword();
	s += "'";
	con.GetRecordset((_bstr_t)s);
	bool b = false;
	if (!con.m_pRecordset->adoEOF)
	{
		b = true;
		s = "update Login set logintime=getdate() where username = '";
		s += user.GetUserName();
		s += "'";
		con.ExecuteSQL((_bstr_t)s);
	}
	con.ExitADOconn();
	return b;
}

bool COpUser::Update()
{
	ADOConn con;
	CString s;
	CString temp = "',";
	char szText[40] = {0};
// 	s = "update Login set ";
// 	s += "nickname = '";
// 	s += user.GetNickName() + temp;
// 	s += "password = '";
// 	s += user.GetPassword() + temp;
// 	s += "mail = '";
// 	s += user.GetMail();
// 	s += "',";
// 	s += "logintime = '";
// 	s += user.GetLoginTime();
// 	s += "' where username='";
// 	s += user.GetUserName();
// 	s += "'";
	bool b = con.ExecuteSQL((_bstr_t)s);
	con.ExitADOconn();
	return b;
}

void COpUser::SetUser(const CUser &u)
{
	user = u;
}

CUser &COpUser::GetUser()
{
	ADOConn con;
	CString s;
	char szText[40] = {0};
	s = "select permission,profession,mail,";
	s += "convert(varchar(10),enrolltime,102) as enrolltime, ";
	s += "convert(varchar(10),logintime,102) as logintime ";
	s += " from Login where username = '";
	s += user.GetUserName();
	s += "'";
	con.GetRecordset((_bstr_t)s);
	if (!con.m_pRecordset->adoEOF)
	{
		strcpy(szText,(char*)(_bstr_t)con.m_pRecordset->GetCollect("permission"));
		user.SetPermission(szText);
		strcpy(szText,(char*)(_bstr_t)con.m_pRecordset->GetCollect("profession"));
		user.SetProfession(szText);
		strcpy(szText,(char*)(_bstr_t)con.m_pRecordset->GetCollect("mail"));
		user.SetMail(szText);
		strcpy(szText,(char*)(_bstr_t)con.m_pRecordset->GetCollect("enrolltime"));
		user.SetEnrollTime(szText);
		strcpy(szText,(char*)(_bstr_t)con.m_pRecordset->GetCollect("logintime"));
		user.SetLoginTime(szText);
	}
	con.ExitADOconn();
	return user;
}

int COpUser::GetUserNum()
{
	ADOConn con;
	int n = 0;
	CString s;
	s = "select count(username) as num from Login";
	con.GetRecordset((_bstr_t)s);
	if (!con.m_pRecordset->adoEOF)
	{
		_variant_t num = con.m_pRecordset->GetCollect("num");
		n = num.intVal;
	}
	con.ExitADOconn();
	return n;
}



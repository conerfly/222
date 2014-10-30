// OpActivity.cpp: implementation of the COpActivity class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SubmitPaper.h"
#include "OpActivity.h"
#include "AdoConn.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COpActivity::COpActivity()
{
	m_TotalNum = 0;
	m_CurNum = 0;
}


COpActivity::~COpActivity()
{

}

bool COpActivity::Add()
{
	ADOConn con;
	CString sql;
	_variant_t id;
	CString s;
	CString temp = "','";
	char szText[50]={0};
	s = "insert into Activity(content,releasetime) values('";
	temp.Format("%s, ",m_Activity.GetContent());
	s +=temp + "', getdate() )";
	bool b = con.ExecuteSQL((_bstr_t)s);
	s = "select aid,content,releasetime from Activity order by releasetime desc";
	con.GetRecordset((_bstr_t)s);
	if (!con.m_pRecordset->adoEOF)
	{
		id = con.m_pRecordset->GetCollect("aid");
		m_Activity.SetAid(id.intVal);
		strcpy(szText,(char*)(_bstr_t)con.m_pRecordset->GetCollect("releasetime"));
		m_Activity.SetReleaseTime(szText);
	}
	con.ExitADOconn();
	return b;
}

bool COpActivity::Delete()
{
	ADOConn con;
	CString s;
	CString temp;
	temp.Format("%d",m_Activity.GetAid());
	s = "delete activity where aid = " + temp; 
	bool b = con.ExecuteSQL((_bstr_t)s);
	con.ExitADOconn();
	return b;
}

bool COpActivity::Update()
{
	ADOConn con;
	CString s;
	CString temp = "','";
	s = "insert into Activity(content,releasetime) values('";
	temp.Format("%s', ",m_Activity.GetContent());
	s +=temp;
	s += "getdate() )";
	bool b = con.ExecuteSQL((_bstr_t)s);
	con.ExitADOconn();
	return b;
}

void COpActivity::GetAllActivity(vector<CActivity *> &vecActivity)
{
	ADOConn con;
	CString s;
	CActivity *pAct;
	_variant_t id;
	char szText[1000] = {0};
	s = "select * from Activity";
	con.GetRecordset((_bstr_t)s);
	while (!con.m_pRecordset->adoEOF)
	{
		pAct = new CActivity;
		id = con.m_pRecordset->GetCollect("aid");
		pAct->SetAid(id.intVal);
		strcpy(szText,(char*)(_bstr_t)con.m_pRecordset->GetCollect("content"));
		pAct->SetContent(szText);
		strcpy(szText,(char*)(_bstr_t)con.m_pRecordset->GetCollect("releasetime"));
		pAct->SetReleaseTime(szText);
		vecActivity.push_back(pAct);
		m_TotalNum++;
		con.m_pRecordset->MoveNext();
	}
	con.ExitADOconn();
}

void COpActivity::SetActivity( const CActivity &act )
{
	m_Activity = act;
}

CActivity & COpActivity::GetActivity()
{
	return m_Activity;
}



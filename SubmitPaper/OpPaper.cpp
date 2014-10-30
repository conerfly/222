// OpPaper.cpp: implementation of the COpPaper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SubmitPaper.h"
#include "OpPaper.h"
#include "AdoConn.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COpPaper::COpPaper()
{
	
}

COpPaper::COpPaper( const CPaper &p )
{
	m_paper = p;
}

COpPaper::~COpPaper()
{

}

bool COpPaper::AddPaper(  )
{
	ADOConn con;
	CString s;
	CString temp = "','";
	s = "insert into Paper(authorname,advisorname,title,content,comment,";
	s += "uploadtime,deadline,remarktime,delay,state,newadvisor) values('";
	s += m_paper.GetAuthorName() + temp;
	s += m_paper.GetAdvisorName() + temp;
	s += m_paper.GetTitle() + temp;
	s += m_paper.GetContent() + temp;
	s += m_paper.GetComment() + temp;
	s += "',getdate(),";
	s += "getdate(),";
	s += "getdate(),0,'wait','";
	s += m_paper.GetAdvisorName();
	s += "')";
	bool b = con.ExecuteSQL((_bstr_t)s);
	con.ExitADOconn();
	return b;
}

bool COpPaper::DeletePaper( )
{
	ADOConn con;
	CString s;
	CString temp;
	temp.Format("%d",m_paper.GetPid());
	s = "delete Paper where pid=" + temp;
	bool b = con.ExecuteSQL((_bstr_t)s);
	con.ExitADOconn();
	return b;
}


bool COpPaper::SaveState(  )
{
	ADOConn con;
	CString s;
	CString temp;
	temp.Format("%d",m_paper.GetPid());
	s = "update Paper set state='";
	s += m_paper.GetState();
	s += "', where pid=" + temp;
	bool b = con.ExecuteSQL((_bstr_t)s);
	con.ExitADOconn();
	return b;
}

bool COpPaper::SaveTitle(  )
{
	ADOConn con;
	CString s;
	CString temp;
	temp.Format("%d",m_paper.GetPid());
	s = "update Paper set title='";
	s += m_paper.GetTitle();
	s += "', where pid=" + temp;;
	bool b = con.ExecuteSQL((_bstr_t)s);
	con.ExitADOconn();
	return b;
}

void COpPaper::GetAllPaper( vector<CPaper*>&vec,CUser &u )
{
	ADOConn con;
	CString s;
	CPaper *p;
	_variant_t n;
	char szText[50] = {0};
//	s = "select * from Paper";
 	s = "select pid,authorname,advisorname,newadvisor,title,state,delay,";
	s += "datediff(day,deadline,getdate()) as days, ";
 	s += "isnull(convert(varchar(50),uploadtime,120),'') as uploadtime, ";
 	s += "isnull(convert(varchar(50),deadline,120),'') as deadline, ";
 	s += "isnull(convert(varchar(50),remarktime,120),'') as remarktime from Paper ";
	if (strcmp(u.GetPermission(),"member")==0)
	{
		s += " where newadvisor='";
		s += u.GetUserName();
		s += "'";	
	}
	else if(strcmp(u.GetPermission(),"author")==0)
	{
		s += " where authorname='";
		s += u.GetUserName();
		s += "'";
	}
	
	con.GetRecordset((_bstr_t)s);
	while (!con.m_pRecordset->adoEOF)
	{
		p = new CPaper;
		n = con.m_pRecordset->GetCollect("pid");
		p->SetPid(n.intVal);
		strcpy(szText,(char*)(_bstr_t)con.m_pRecordset->GetCollect("authorname"));
		p->SetAuthorName(szText);
		strcpy(szText,(char*)(_bstr_t)con.m_pRecordset->GetCollect("advisorname"));
		p->SetAdvisorName(szText);
		strcpy(szText,(char*)(_bstr_t)con.m_pRecordset->GetCollect("newadvisor"));
		p->SetNewAdvisor(szText);
		strcpy(szText,(char*)(_bstr_t)con.m_pRecordset->GetCollect("title"));
		p->SetTitle(szText);
		strcpy(szText,(char*)(_bstr_t)con.m_pRecordset->GetCollect("uploadtime"));
		p->SetUploadTime(szText);
		strcpy(szText,(char*)(_bstr_t)con.m_pRecordset->GetCollect("deadline"));
		p->SetDeadLine(szText);
		strcpy(szText,(char*)(_bstr_t)con.m_pRecordset->GetCollect("remarktime"));
		p->SetRemarkTime(szText);
		n = con.m_pRecordset->GetCollect("delay");
		p->SetDelay(n.intVal);
		n = con.m_pRecordset->GetCollect("days");
		p->SetDays(n.intVal);
		strcpy(szText,(char*)(_bstr_t)con.m_pRecordset->GetCollect("state"));
		p->SetState(szText);
		vec.push_back(p);
		con.m_pRecordset->MoveNext();
	}
	con.ExitADOconn();
}

void COpPaper::SetPaper( const CPaper &p )
{
	m_paper = p;
}

CPaper & COpPaper::GetPaper()
{

	return m_paper;
}

bool COpPaper::GetPaperData()
{
	ADOConn con;
	CString s;
	CString temp;
	temp.Format("%d",m_paper.GetPid());
	char szText[1024*64] = {0};
	s = "select isnull(content,'') as content,isnull(comment,'') as comment from Paper ";
	s += " where pid =" + temp;
	con.GetRecordset((_bstr_t)s);
	if (!con.m_pRecordset->adoEOF)
	{
		strcpy(szText,(char*)(_bstr_t)con.m_pRecordset->GetCollect("content"));
		m_paper.SetContent(szText);
		strcpy(szText,(char*)(_bstr_t)con.m_pRecordset->GetCollect("comment"));
		m_paper.SetComment(szText);
	}
	else
	{
		return false;
	}
	con.ExitADOconn();
	return true;
}

void COpPaper::ClearPaperData()
{
	m_paper.SetContent(NULL);
	m_paper.SetComment(NULL);
}

bool COpPaper::UpdateNewAdvisor()
{
	ADOConn con;
	CString s;
	CString temp;
	temp.Format("%d",m_paper.GetPid());
	s = "update Paper set deadline=getdate()+14,newadvisor=";
	s += "(select top 1 username from Login where permission ='member' ";
	s += " and username !='";
	s += m_paper.GetAdvisorName();
	s += "' order by newid()) where pid='";
	s += temp;
	bool b = con.ExecuteSQL((_bstr_t)s);
	con.ExitADOconn();
	return b;
}

bool COpPaper::UpdateComment()
{
	ADOConn con;
	CString s;
	CString temp;
	temp.Format("%d",m_paper.GetPid());
	s = "update Paper set comment='";
	s += m_paper.GetComment();
	s += "' where pid = " + temp;
	bool b = con.ExecuteSQL((_bstr_t)s);
	con.ExitADOconn();
	return b;
}

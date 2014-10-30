// Paper.cpp: implementation of the CPaper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SubmitPaper.h"
#include "Paper.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPaper::CPaper()
{
	memset(authorname,0,sizeof(authorname));
	memset(advisorname,0,sizeof(advisorname));
	memset(uploadtiem,0,sizeof(uploadtiem));
	memset(deadline,0,sizeof(deadline));
	memset(remarktime,0,sizeof(remarktime));
	memset(state,0,sizeof(state));
	memset(newadvisor,0,sizeof(newadvisor));
	pContent = NULL;
	pComment = NULL;
	delay = 0;
	days = 0;
}

CPaper::CPaper( const CPaper &p )
{
	strcpy(authorname, p.authorname);
	strcpy(advisorname, p.advisorname);
	strcpy(uploadtiem, p.uploadtiem);
	strcpy(deadline, p.deadline);
	strcpy(remarktime, p.remarktime);
	strcpy(state, p.state);
	strcpy(newadvisor, p.newadvisor);
	SetContent(p.pContent);
	SetComment(p.pComment);
	delay = p.delay;
}

CPaper & CPaper::operator=( const CPaper &p )
{
	pid = p.pid;
	strcpy(authorname, p.authorname);
	strcpy(advisorname, p.advisorname);
	strcpy(uploadtiem, p.uploadtiem);
	strcpy(deadline, p.deadline);
	strcpy(remarktime, p.remarktime);
	strcpy(state, p.state);
	strcpy(newadvisor, p.newadvisor);
	SetContent(p.pContent);
	SetComment(p.pComment);
	delay = p.delay;
	return *this;
}

CPaper::~CPaper()
{
	if (pContent != NULL)
	{
		delete pContent;
		pContent = NULL;
	}
	if (pComment !=NULL)
	{
		delete pComment;
		pComment = NULL;
	}
}

char* CPaper::GetAuthorName() 
{
	return authorname;
}

void CPaper::SetAuthorName(char *s) 
{
	strcpy(authorname, s);
}
char* CPaper::GetAdvisorName() 
{
	return advisorname;
}
void CPaper::SetAdvisorName(char *s) 
{
	strcpy(advisorname, s);
}

char* CPaper::GetUploadTime() 
{
	return uploadtiem;
}
void CPaper::SetUploadTime(char *s) 
{
	strcpy(uploadtiem, s);
}
char* CPaper::GetDeadLine() 
{
	return deadline;
}
void CPaper::SetDeadLine(char *s) 
{
	strcpy(deadline, s);
}

char* CPaper::GetRemarkTime() 
{
	return remarktime;
}
void CPaper::SetRemarkTime(char *s) 
{
	strcpy(remarktime, s);
}
int CPaper::GetDelay() 
{
	return delay;
}
void CPaper::SetDelay(int n) 
{
	delay = n;
}
char* CPaper::GetState() 
{
	return state;
}
void CPaper::SetState(char *s) 
{
	strcpy(state, s);
}
char* CPaper::GetNewAdvisor() 
{
	return newadvisor;
}
void CPaper::SetNewAdvisor(char *s) 
{
	strcpy(newadvisor, s);
}

char* CPaper::GetContent()
{
	return pContent;
}

void CPaper::SetContent( char *s )
{
	
	if (pContent != NULL)
	{
		if(s == NULL)
		{
			delete pContent;
			pContent = NULL;
			return;
		}
		else
		{
			delete pContent;
			pContent = new char[strlen(s)+1];
			strcpy(pContent,s);
		}
	}
	else
	{
		if(s == NULL)
		{
			pContent = NULL;
		}
		else
		{
			pContent = new char[strlen(s)+1];
			strcpy(pContent,s);
		}
	}
}

char* CPaper::GetComment()
{
	return pComment;
}

void CPaper::SetComment( char *s )
{
	if (pComment != NULL)
	{
		if(s == NULL)
		{
			delete pComment;
			pComment = NULL;
			return;
		}
		else
		{
			delete pComment;
			pComment = new char[strlen(s)+1];
			strcpy(pComment,s);
		}
	}
	else
	{
		if(s == NULL)
		{
			pComment = NULL;
		}
		else
		{
			pComment = new char[strlen(s)+1];
			strcpy(pComment,s);
		}
	}
}

char* CPaper::GetTitle()
{
	return title;
}

void CPaper::SetTitle( char *s )
{
	strcpy(title, s);
}

int CPaper::GetPid()
{
	return pid;
}

void CPaper::SetPid( int id )
{
	pid = id;
}

int CPaper::GetDays()
{
	return days;
}

void CPaper::SetDays( int n )
{
	days = 0;
}



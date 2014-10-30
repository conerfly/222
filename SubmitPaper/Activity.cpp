// Activity.cpp: implementation of the CActivity class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SubmitPaper.h"
#include "Activity.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CActivity::CActivity()
{
	aid = 0;
	pContent = NULL;
	memset(releasetime,0, sizeof(releasetime));
}

CActivity::CActivity( const CActivity &act )
{
	aid = act.aid;
	if (pContent != NULL)
	{
		delete pContent;
		pContent = new char[strlen(act.pContent)+1];
		strcpy(pContent, act.pContent);
	}
}

CActivity::~CActivity()
{
	if (pContent != NULL)
	{
		delete pContent;
		pContent = NULL;
	}
}

void CActivity::SetAid( int id )
{
	aid = id;
}

void CActivity::SetContent( char *s )
{
	if (s != NULL)
	{
		pContent = new char[strlen(s)+1];
		strcpy(pContent, s);
	}
}

void CActivity::SetReleaseTime( char *s )
{
	strcpy(releasetime, s);
}

int CActivity::GetAid()
{
	return aid;
}

char * CActivity::GetContent()
{
	return pContent;
}

char * CActivity::GetReleaseTime()
{
	return releasetime;
}

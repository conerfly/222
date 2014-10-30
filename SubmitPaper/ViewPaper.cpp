// ViewPaper.cpp: implementation of the CViewPaper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ViewPaper.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CViewPaper::CViewPaper()
{

}

CViewPaper::~CViewPaper()
{

}

void CViewPaper::GetAllPaper( vector<CPaper*>&vec,CUser &u )
{
	opPaper.GetAllPaper(vec,u);
}



void CViewPaper::GetPaperData(CPaper &p)
{
	opPaper.SetPaper(p);
	opPaper.GetPaperData();
	p.SetContent(opPaper.GetPaper().GetContent());
	p.SetComment(opPaper.GetPaper().GetComment());
}

void CViewPaper::ClearPaperData( const CPaper &p)
{
	opPaper.SetPaper(p);
	opPaper.ClearPaperData();
}

bool CViewPaper::UpdateComment( CPaper &p )
{
	opPaper.SetPaper(p);
	return opPaper.UpdateComment();
}

bool CViewPaper::UpdateNewAdvisor(CPaper &p )
{
	opPaper.SetPaper(p);
	return opPaper.UpdateNewAdvisor();
}


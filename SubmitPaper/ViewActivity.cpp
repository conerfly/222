// ViewActivity.cpp: implementation of the CViewActivity class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ViewActivity.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CViewActivity::CViewActivity()
{

}

CViewActivity::CViewActivity( const COpActivity &op )
{
	opAct = op;
}

CViewActivity::~CViewActivity()
{

}

void CViewActivity::GetAllActivity( vector<CActivity*>&vec )
{
	opAct.GetAllActivity(vec);
}

void CViewActivity::RemoveNotice( const CActivity &act )
{
	opAct.SetActivity(act);
	opAct.Delete();
}

void CViewActivity::AddNotice(CActivity &act )
{
	opAct.SetActivity(act);
	opAct.Add();
	act = opAct.GetActivity();
}

void CViewActivity::UpdateNotice( const CActivity &act )
{
	opAct.SetActivity(act);
	opAct.Update();
}

// OpPaper.h: interface for the COpPaper class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPPAPER_H__0A40FA1C_C749_4391_B97B_C725D9D116D3__INCLUDED_)
#define AFX_OPPAPER_H__0A40FA1C_C749_4391_B97B_C725D9D116D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Paper.h"
#include "User.h"
#include <vector>
using namespace std;
class COpPaper  
{
public:
	COpPaper();
	COpPaper(const CPaper &p);
	virtual ~COpPaper();
	bool AddPaper();
	bool DeletePaper();
	bool UpdateComment();
	bool GetPaperData();//comment and content
	void ClearPaperData();
	bool SaveState();
	bool SaveTitle();
	bool UpdateNewAdvisor();
	void SetPaper(const CPaper &p);
	CPaper &GetPaper();
	void GetAllPaper(vector<CPaper*>&vec,CUser &u);
	CPaper m_paper;
};

#endif // !defined(AFX_OPPAPER_H__0A40FA1C_C749_4391_B97B_C725D9D116D3__INCLUDED_)

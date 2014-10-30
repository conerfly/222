// Paper.h: interface for the CPaper class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PAPER_H__02917E88_CE9E_4041_9A09_9E7D6E796A07__INCLUDED_)
#define AFX_PAPER_H__02917E88_CE9E_4041_9A09_9E7D6E796A07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPaper  
{
public:
	CPaper();
	virtual ~CPaper();
	CPaper(const CPaper &p);
	CPaper &operator=(const CPaper &p);
	char* GetAuthorName();
	void SetAuthorName(char *s); 
	char*GetAdvisorName();
	void SetAdvisorName(char *s);
	char*GetTitle();
	void SetTitle(char *s);
	char* GetUploadTime();
	void SetUploadTime(char *s);
	char *GetDeadLine();
	void SetDeadLine(char *s);
	char* GetRemarkTime();
	void SetRemarkTime(char *s); 
	int GetDelay(); 
	void SetDelay(int n); 
	int GetDays(); 
	void SetDays(int n); 
	int GetPid(); 
	void SetPid(int id); 
	char* GetState(); 
	void SetState(char *s); 
	char* GetNewAdvisor(); 
	void SetNewAdvisor(char *s); 
	char* GetContent();
	void SetContent(char *s);
	char* GetComment();
	void SetComment(char *s);
private:
	char authorname[20];
	char advisorname[20];
	char title[50];
	char *pContent;
	char *pComment;
	char uploadtiem[50];
	char deadline[50];
	char remarktime[50];
	char state[10];
	char newadvisor[50];
	int delay;
	int days;
	int pid;

};

#endif // !defined(AFX_PAPER_H__02917E88_CE9E_4041_9A09_9E7D6E796A07__INCLUDED_)

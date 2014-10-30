
#pragma once
#import "c:\Program Files\Common Files\System\ado\msado15.dll"	no_namespace rename("EOF","adoEOF") rename("BOF","adoBOF")

class ADOConn  
{
public:
	CString m_strConn;
    _ConnectionPtr m_pConnection; 
    _RecordsetPtr m_pRecordset; 
public:
	bool InitADOconn(); 
    _RecordsetPtr& GetRecordset(_bstr_t bstrSQL); 
    bool ExecuteSQL(_bstr_t bstrSQL); 
	bool SaveFileSQL(char *tablename,char *itemname,CFile *pFile);
	bool GetSQLFile(char *tablename,char *itemname,CFile *pFile);
    void CloseRecordset(); 
    void ExitADOconn(); 
	ADOConn();
	virtual ~ADOConn();
	
};

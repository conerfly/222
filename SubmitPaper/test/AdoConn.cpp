
#include "stdafx.h"
#include "AdoConn.h"
#include <afx.h>

ADOConn::ADOConn()
{
	_bstr_t strConnect = "Provider=SQLOLEDB.1;Persist Security Info=False;User ID=sa;Initial Catalog=Paper;Data Source=KMG2014-9-PC\\SQLEXPRESS";
	m_strConn = (char*)strConnect;
	//////这一句很主要，我当时写就卡在这里，那个数据库名称后面要Security /Info=True;Server=127.0.0.1\\SQLEXPRESS;
	//	m_pConnection->Open(strConnect,"sa","123",adModeUnknown);
//	m_strConn = "Provider=SQLOLEDB.1;Persist Security Info=False;User ID=sa;Initial Catalog=Paper;Data Source=KMG2014-9-PC\\SQLEXPRESS";
}

ADOConn::~ADOConn()
{
	
}

bool ADOConn::InitADOconn()
{
	::CoInitialize(NULL);
	try
	{
		m_pConnection.CreateInstance(__uuidof(Connection));
	//	m_pConnection->Open((_bstr_t)m_strConn,"sa","123",adModeUnknown);
		//m_pConnection->Open((_bstr_t)m_strConn,"","",adModeUnknown);
		_bstr_t strConnect = "Provider=SQLOLEDB.1;Persist Security Info=False;User ID=sa;Initial Catalog=Paper;Data Source=KMG2014-9-PC\\SQLEXPRESS";
		//////这一句很主要，我当时写就卡在这里，那个数据库名称后面要Security /Info=True;Server=127.0.0.1\\SQLEXPRESS;
		m_pConnection->Open(strConnect,"sa","123",adModeUnknown);
	}
	catch(_com_error e)
	{
		CString errormessage;
        errormessage.Format("database connect failed!\r\nErrorMessage:%s",e.ErrorMessage());
		AfxMessageBox(e.Description());
		return false;
	}
	return true;
}

_RecordsetPtr& ADOConn::GetRecordset(_bstr_t bstrSQL)
{
	try
	{
		if(m_pConnection == NULL)
		{
			if (!InitADOconn())
			{
				return m_pRecordset;
			}
		}
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error e)
	{
		CString errormessage;
        errormessage.Format("database connect failed!\r\nErrorMessage:%s",e.ErrorMessage());
		AfxMessageBox(e.Description());
	}
	return m_pRecordset;
}

bool ADOConn::ExecuteSQL(_bstr_t bstrSQL)
{
	try
	{
		if(m_pConnection == NULL)
		{
			if (!InitADOconn())
			{
				return NULL;
			}
		}
		m_pConnection->Execute(bstrSQL,NULL,adCmdText);
		return true;
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
		return false;
	}
}

bool ADOConn::SaveFileSQL(char *tablename,char *itemname,CFile *pFile)
{
// 	CFile file;
// 	if (0==file.Open(filepath,CFile::modeRead))
// 	{
// 		return false;
// 	}
	pFile->SeekToBegin();
	byte* pbuf;
	long nLength = pFile->GetLength();
	pbuf = new byte[nLength];
	if(pbuf == NULL)
	{
		return false;       
	}//allocate memory error;
	pFile->Read(pbuf,nLength);          //read the file into memory
	byte *pBufEx = pbuf;
	SAFEARRAY* psa;
	SAFEARRAYBOUND rgsabound[1];
	rgsabound[0].lLbound = 0;
	rgsabound[0].cElements = nLength;
	psa = SafeArrayCreate(VT_UI1, 1, rgsabound);
	for (long i = 0; i < nLength; i++)
	{
		SafeArrayPutElement (psa, &i, pBufEx++);
	}
	VARIANT varBLOB;
	varBLOB.vt = VT_ARRAY | VT_UI1;
	varBLOB.parray = psa;
	_RecordsetPtr pRs = NULL;             
	_ConnectionPtr pConnection = NULL;
	HRESULT hr;
	try
    {
        //Open a connection
        pConnection.CreateInstance(__uuidof(Connection));
        hr = pConnection->Open((_bstr_t)m_strConn,"sa","123",adModeUnknown);   //Connect a DataBase
        pRs.CreateInstance(__uuidof(Recordset));
      //  pRs->Open(tablename,_variant_t((IDispatch *) pConnection,true),adOpenKeyset,adLockOptimistic,adCmdTable);  //Open a Table
		pRs->Open("select *from test where name='content'",_variant_t((IDispatch *) pConnection,true),adOpenKeyset,adLockOptimistic,adCmdText);		

		pRs->AddNew();
		pRs->GetFields()->GetItem("name")->AppendChunk((_bstr_t)itemname);
			pRs->GetFields()->GetItem("content")->AppendChunk(varBLOB);
//		pRs->PutCollect("name",_variant_t(itemname));
//		pRs->PutCollect("content",varBLOB);
		//	pRs->Fields->GetItem(itemname)->AppendChunk(varBLOB);        
       pRs->Update();
        pRs->Close();
       pConnection->Close();
	 }
    catch(_com_error &e)
    {
        // Notify the user of errors if any.
        _bstr_t bstrSource(e.Source());
        _bstr_t bstrDescription(e.Description());
        CString sError;
        sError.Format("Source : %s \n Description : %s\n",(LPCSTR)bstrSource,(LPCSTR)bstrDescription);		
        AfxMessageBox(sError);    
		return false;
	}
	return true;
}

bool ADOConn::GetSQLFile(char *tablename,char *itemname,CFile *pFile)
{
	_RecordsetPtr pRs = NULL;
    _ConnectionPtr pConnection = NULL;	
    _variant_t varChunk;	
    HRESULT hr;	
    VARIANT varBLOB;	
    //_bstr_t strCnn("Provider=SQLOLEDB.1;Integrated Security=SSPI;
	//Persist Security Info=False;Initial Catalog=CUSTOM;Data Source=SERVER");    	
    try		
    {	
        //Open a connection	
        pConnection.CreateInstance(__uuidof(Connection));		
        hr = pConnection->Open((_bstr_t)m_strConn,"sa","123",adModeUnknown);        		
        pRs.CreateInstance(__uuidof(Recordset));		
        pRs->Open("select *from test where name='content'",_variant_t((IDispatch *) pConnection,true),adOpenKeyset,adLockOptimistic,adCmdText);		
		//read  data  	
		long lDataLength = pRs->Fields->GetItem(itemname)->ActualSize;	
		varBLOB = pRs->GetFields()->GetItem(itemname)->GetChunk(lDataLength+1);		
		if(varBLOB.vt == (VT_ARRAY | VT_UI1))        			
		{
			byte *pBuf = NULL;   			
            pBuf = (byte*)GlobalAlloc(GMEM_FIXED,lDataLength+1);			
            SafeArrayAccessData(varBLOB.parray,(void **)pBuf); 			
            //Build a File in Windows Temp Directory			
//             char tmpPath[_MAX_PATH+1];			
//             GetTempPath(_MAX_PATH,tmpPath);			
//             CString strFileName = "temp.bmp";
// 			pFile->
//             strFileName = tmpPath+strFileName;									
//             CFile outFile(strFileName,CFile::modeCreate|CFile::modeWrite);			
			LPSTR buffer = (LPSTR)GlobalLock((HGLOBAL)pBuf);			
            pFile->WriteHuge(buffer,lDataLength);		
            GlobalUnlock((HGLOBAL)pBuf);		
          pFile->Close();           		
            SafeArrayUnaccessData (varBLOB.parray);		
		}		
        pRs->Close();		
        pConnection->Close();		
	}
	catch(_com_error &e)
	{
			// Notify the user of errors if any.	
		_bstr_t bstrSource(e.Source());	
		_bstr_t bstrDescription(e.Description());	
		CString sError;	
		sError.Format("Source : %s \n Description : %s\n",(LPCSTR)bstrSource,(LPCSTR)bstrDescription);	
		AfxMessageBox(sError);   
		return false;
	}
	return true;
}

void ADOConn::CloseRecordset()
{
	if(m_pRecordset != NULL)
		m_pRecordset->Close();
}

void ADOConn::ExitADOconn()
{
	m_pConnection->Close();
	::CoUninitialize();
}
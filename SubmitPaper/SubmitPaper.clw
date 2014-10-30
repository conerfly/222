; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CUpload
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "submitpaper.h"
LastPage=0

ClassCount=11
Class1=CAdminDlg
Class2=CAuthorDlg
Class3=CChairDlg
Class4=CEnroll
Class5=CMemberDlg
Class6=CSubmitPaperApp
Class7=CAboutDlg
Class8=CSubmitPaperDlg

ResourceCount=8
Resource1=IDD_DLG_UPLOAD
Resource2=IDD_DLG_ADMIN
Resource3=IDD_DLG_ENROLL
Resource4=IDD_DLG_NOTICE
Resource5=IDD_ABOUTBOX
Resource6=IDD_SUBMITPAPER_DIALOG
Class9=CNotice
Class10=CDelUser
Resource7=IDD_DLG_DELUSER
Class11=CUpload
Resource8=IDR_MENU

[CLS:CAdminDlg]
Type=0
BaseClass=CDialog
HeaderFile=AdminDlg.h
ImplementationFile=AdminDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CAdminDlg

[CLS:CAuthorDlg]
Type=0
BaseClass=CDialog
HeaderFile=AuthorDlg.h
ImplementationFile=AuthorDlg.cpp

[CLS:CChairDlg]
Type=0
BaseClass=CDialog
HeaderFile=ChairDlg.h
ImplementationFile=ChairDlg.cpp

[CLS:CEnroll]
Type=0
BaseClass=CDialog
HeaderFile=Enroll.h
ImplementationFile=Enroll.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_COMBO_ROLE

[CLS:CMemberDlg]
Type=0
BaseClass=CDialog
HeaderFile=MemberDlg.h
ImplementationFile=MemberDlg.cpp

[CLS:CSubmitPaperApp]
Type=0
BaseClass=CWinApp
HeaderFile=SubmitPaper.h
ImplementationFile=SubmitPaper.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=SubmitPaperDlg.cpp
ImplementationFile=SubmitPaperDlg.cpp

[CLS:CSubmitPaperDlg]
Type=0
BaseClass=CDialog
HeaderFile=SubmitPaperDlg.h
ImplementationFile=SubmitPaperDlg.cpp

[DLG:IDD_DLG_ADMIN]
Type=1
Class=CAdminDlg
ControlCount=36
Control1=IDC_LIST_PAPER,SysListView32,1350631437
Control2=IDC_COMBO_PROFESSION,combobox,1344340227
Control3=IDC_EDIT_PAPER,edit,1350633540
Control4=IDC_EDIT_NOTICE,edit,1350633540
Control5=IDC_BTN_LASTNOTICE,button,1342242816
Control6=IDC_BTN_NEXTNOTICE,button,1342242816
Control7=IDC_EDIT_COMMENT,edit,1350633540
Control8=IDC_STATIC,static,1342308352
Control9=IDC_ST_AUTHOR,static,1342308352
Control10=IDC_ST_AUTHOR2,static,1342308352
Control11=IDC_ST_DEFAULT,static,1342308352
Control12=IDC_ST_CURRENT,static,1342308352
Control13=IDC_ST_AUTHOR4,static,1342308352
Control14=IDC_ST_AUTHOR5,static,1342308352
Control15=IDC_ST_UPLOAD,static,1342308352
Control16=IDC_ST_AUTHOR6,static,1342308352
Control17=IDC_ST_REMARK,static,1342308352
Control18=IDC_ST_AUTHOR7,static,1342308352
Control19=IDC_ST_DEADLINE,static,1342308352
Control20=IDC_ST_DELAY,static,1342308352
Control21=IDC_ST_STATE,static,1342308352
Control22=IDC_BTN_ADD,button,1342242816
Control23=IDC_BTN_REMOVE,button,1342242816
Control24=IDC_COMBO_SEARCH,combobox,1344340227
Control25=IDC_EDIT_SEARCH,edit,1350631424
Control26=IDC_BTN_SEARCH,button,1342242816
Control27=IDC_STATIC,button,1342177287
Control28=IDC_STATIC,button,1342177287
Control29=IDC_STATIC,static,1342181383
Control30=IDC_BTN_ADDUSER,button,1342242816
Control31=IDC_BTN_DELUSER,button,1342242816
Control32=IDC_BTN_REMARK,button,1342242816
Control33=IDC_BTN_SAVE,button,1342242816
Control34=IDC_BTN_DOWNLOAD,button,1342242816
Control35=IDC_BTN_UPLOAD,button,1342242816
Control36=IDC_BTN_SUBMIT,button,1342242816

[DLG:IDD_DLG_ENROLL]
Type=1
Class=CEnroll
ControlCount=14
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_USERNAME,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_PASSWORD,edit,1350631584
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_MAIL,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_CONFIRM,edit,1350631584
Control9=IDC_ST_PROFESSION,static,1342308352
Control10=IDC_EDIT_PROFESSION,edit,1350631552
Control11=IDC_BTN_CANCEL,button,1342242816
Control12=IDC_BTN_ENROLL,button,1342242816
Control13=IDC_STATIC,static,1342308352
Control14=IDC_COMBO_ROLE,combobox,1344340227

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SUBMITPAPER_DIALOG]
Type=1
Class=CSubmitPaperDlg
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_USERNAME,edit,1350631552
Control3=IDC_BTN_LOGIN,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_PASSWORD,edit,1350631584
Control6=IDC_BTN_ENROLL,button,1342242816

[MNU:IDR_MENU]
Type=1
Class=?
Command1=ID_MENUITEM32771
Command2=ID_MENUITEM32772
Command3=ID_MENUITEM32773
Command4=ID_MENUITEM32774
Command5=ID_MENUITEM32775
Command6=ID_MENUITEM32776
Command7=ID_MENUITEM32777
Command8=ID_MENUITEM32778
CommandCount=8

[DLG:IDD_DLG_NOTICE]
Type=1
Class=CNotice
ControlCount=3
Control1=IDC_EDIT_NOTICE,edit,1350631492
Control2=IDC_BTN_CANCEL,button,1342242816
Control3=IDC_BTN_ADD,button,1342242817

[CLS:CNotice]
Type=0
HeaderFile=Notice.h
ImplementationFile=Notice.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_DLG_DELUSER]
Type=1
Class=CDelUser
ControlCount=3
Control1=IDC_BTN_DELUSER,button,1342242816
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_STATIC,static,1342308352

[CLS:CDelUser]
Type=0
HeaderFile=DelUser.h
ImplementationFile=DelUser.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_DLG_UPLOAD]
Type=1
Class=CUpload
ControlCount=11
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_PATH,edit,1350633600
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_TITLE,edit,1350631552
Control6=IDC_COMBO_CLASS,combobox,1344340227
Control7=IDC_BTN_BROWSE,button,1342242816
Control8=IDC_BTN_CANCEL,button,1342242816
Control9=IDC_BTN_OK,button,1342242816
Control10=IDC_STATIC,static,1342308352
Control11=IDC_COMBO_TYPE,combobox,1344340227

[CLS:CUpload]
Type=0
HeaderFile=Upload.h
ImplementationFile=Upload.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_COMBO_CLASS
VirtualFilter=dWC


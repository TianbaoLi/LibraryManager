
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "LibraryManager.h"

#include "MainFrm.h"
#include "Login.h"
#include "StudentManager.h"
#include "BookManager.h"
#include "StaffManager.h"
#include "BookSearch.h"
#include "PasswordEdit.h"
#include "BookLend.h"
#include "BookReturn.h"
#include "BookAdd.h"
#include "BookEdit.h"
#include "BookDelete.h"
#include "StudentAdd.h"
#include "StudentSearch.h"
#include "StudentDelete.h"
#include "StudentEdit.h"
#include "StudentSort.h"
#include "StaffAdd.h"
#include "StaffSearch.h"
#include "StaffDelete.h"
#include "StaffManager.h"
#include "StaffEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_AdminLogin, &CMainFrame::OnAdminlogin)
	ON_COMMAND(ID_LibraryRule, &CMainFrame::OnLibraryrule)
	ON_COMMAND(ID_Exit, &CMainFrame::OnExit)
	ON_COMMAND(ID_ExitLogin, &CMainFrame::OnExitlogin)
	ON_COMMAND(ID_PasswordEdit, &CMainFrame::OnPasswordEdit)
	ON_COMMAND(ID_Lend, &CMainFrame::OnLend)
	ON_COMMAND(ID_Return, &CMainFrame::OnReturn)
	ON_COMMAND(ID_BookSearch, &CMainFrame::OnBooksearch)
	ON_COMMAND(ID_BookSearchByName, &CMainFrame::OnBooksearchbyname)
	ON_COMMAND(ID_BookAdd, &CMainFrame::OnBookadd)
	ON_COMMAND(ID_BookEdit, &CMainFrame::OnBookedit)
	ON_COMMAND(ID_BookDelete, &CMainFrame::OnBookdelete)
	ON_COMMAND(ID_StudentAdd, &CMainFrame::OnStudentadd)
	ON_COMMAND(ID_StudentSearch, &CMainFrame::OnStudentsearch)
	ON_COMMAND(ID_StudentDelete, &CMainFrame::OnStudentdelete)
	ON_COMMAND(ID_StudentShow, &CMainFrame::OnStudentshow)
	ON_COMMAND(ID_StudentEdit, &CMainFrame::OnStudentedit)
	ON_COMMAND(ID_StudentSort, &CMainFrame::OnStudentsort)
	ON_COMMAND(ID_StaffAdd, &CMainFrame::OnStaffadd)
	ON_COMMAND(ID_StaffSearch, &CMainFrame::OnStaffsearch)
	ON_COMMAND(ID_StaffDelete, &CMainFrame::OnStaffdelete)
	ON_COMMAND(ID_StaffShow, &CMainFrame::OnStaffshow)
	ON_COMMAND(ID_StaffEdit, &CMainFrame::OnStaffedit)
	ON_COMMAND(ID_BackUp, &CMainFrame::OnBackup)
	ON_COMMAND(ID_Recovery, &CMainFrame::OnRecovery)
	ON_COMMAND(ID_Guide, &CMainFrame::OnGuide)
	ON_COMMAND(ID_BookShow, &CMainFrame::OnBookshow)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	/*if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);*/


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	m_strTitle="LibraryManager"; 
	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序

void CMainFrame::OnAdminlogin()
{
	// TODO: 在此添加命令处理程序代码
	Login Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnLibraryrule()
{
	// TODO: 在此添加命令处理程序代码
	CStdioFile File;
	CString string,temp;
	File.Open(TEXT("LibraryRule.txt"),CFile::modeRead);
	char* old_locale=_strdup(setlocale(LC_CTYPE,NULL));
	setlocale( LC_CTYPE,"chs");
	while(1)
	{
		if(!File.ReadString(temp))break;
		string+=temp;
		string+="\n";
	}
	setlocale(LC_CTYPE,old_locale);
	free(old_locale);
	File.Close();
	MessageBox(string,TEXT("借阅规则"));
}


void CMainFrame::OnExit()
{
	// TODO: 在此添加命令处理程序代码
	exit(0);
}

void CMainFrame::OnBooksearch()
{
	// TODO: 在此添加命令处理程序代码
	BookSearch Dlg;
	Dlg.DoModal();
}

void CMainFrame::OnExitlogin()
{
	// TODO: 在此添加命令处理程序代码
	CMenu menu;
	menu.LoadMenu(IDR_MAINFRAME);
	AfxGetMainWnd()->SetMenu(&menu);
	menu.Detach();
	CStdioFile File;
	File.Open(TEXT("current user.txt"),CFile::modeWrite|CFile::modeCreate);
	char* old_locale=_strdup(setlocale(LC_CTYPE,NULL));
	setlocale( LC_CTYPE,"chs");
	File.WriteString(TEXT("\n"));
	setlocale(LC_CTYPE,old_locale);
	free(old_locale);
	File.Close();
}

void CMainFrame::OnPasswordEdit()
{
	// TODO: 在此添加命令处理程序代码
	PasswordEdit Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnLend()
{
	// TODO: 在此添加命令处理程序代码
	BookLend Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnReturn()
{
	// TODO: 在此添加命令处理程序代码
	BookReturn Dlg;
	Dlg.DoModal();
}



void CMainFrame::OnBooksearchbyname()
{
	// TODO: 在此添加命令处理程序代码
	BookSearch Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnBookadd()
{
	// TODO: 在此添加命令处理程序代码
	BookAdd Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnBookedit()
{
	// TODO: 在此添加命令处理程序代码
	BookEdit Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnBookdelete()
{
	// TODO: 在此添加命令处理程序代码
	BookDelete Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnStudentadd()
{
	// TODO: 在此添加命令处理程序代码
	StudentAdd Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnStudentsearch()
{
	// TODO: 在此添加命令处理程序代码
	StudentSearch Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnStudentdelete()
{
	// TODO: 在此添加命令处理程序代码
	StudentDelete Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnStudentshow()
{
	// TODO: 在此添加命令处理程序代码
	StudentManager studentmanager;
	studentmanager.ShowStudent();
}


void CMainFrame::OnStudentedit()
{
	// TODO: 在此添加命令处理程序代码
	StudentEdit Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnStudentsort()
{
	// TODO: 在此添加命令处理程序代码
	StudentSort Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnStaffadd()
{
	// TODO: 在此添加命令处理程序代码
	StaffAdd Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnStaffsearch()
{
	// TODO: 在此添加命令处理程序代码
	StaffSearch Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnStaffdelete()
{
	// TODO: 在此添加命令处理程序代码
	StaffDelete Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnStaffshow()
{
	// TODO: 在此添加命令处理程序代码
	StaffManager staffmanager;
	staffmanager.ShowStaff();
}


void CMainFrame::OnStaffedit()
{
	// TODO: 在此添加命令处理程序代码
	StaffEdit Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnBackup()
{
	// TODO: 在此添加命令处理程序代码
	LPITEMIDLIST rootLoation;
	SHGetSpecialFolderLocation(NULL,CSIDL_DESKTOP,&rootLoation);
	BROWSEINFO bi;
	ZeroMemory(&bi,sizeof(bi));
	bi.pidlRoot=rootLoation;
	bi.lpszTitle=_T("选择备份文件根目录");
	LPITEMIDLIST targetLocation=SHBrowseForFolder(&bi);
	if(targetLocation!= NULL)
	{
		TCHAR targetPath[MAX_PATH];
		SHGetPathFromIDList(targetLocation,targetPath);
		CString str;
		str.Format(_T("%s"),targetPath);
		CopyFile(TEXT("student.txt"),str+TEXT("\\student.txt"),FALSE);
		CopyFile(TEXT("admin.txt"), str + TEXT("\\admin.txt"), FALSE);
		CopyFile(TEXT("book.txt"), str + TEXT("\\book.txt"), FALSE);
		CopyFile(TEXT("staff.txt"), str + TEXT("\\staff.txt"), FALSE);
	}
}


void CMainFrame::OnRecovery()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog dlg(TRUE,_T("txt"),_T(""),OFN_FILEMUSTEXIST|OFN_HIDEREADONLY,_T("文本|*.txt|所有文件|*||"));
	if(dlg.DoModal()==IDOK)
	{
		CopyFile(dlg.GetPathName(),dlg.GetFileName(),FALSE);
	}
}


void CMainFrame::OnGuide()
{
	// TODO: 在此添加命令处理程序代码.
	CStdioFile File;
	CString string,temp;
	File.Open(TEXT("Guide.txt"),CFile::modeRead);
	char* old_locale=_strdup(setlocale(LC_CTYPE,NULL));
	setlocale( LC_CTYPE,"chs");
	while(1)
	{
		if(!File.ReadString(temp))break;
		string+=temp;
		string+="\n";
	}
	setlocale(LC_CTYPE,old_locale);
	free(old_locale);
	File.Close();
	MessageBox(string,TEXT("使用方法"));
}


void CMainFrame::OnBookshow()
{
	// TODO: 在此添加命令处理程序代码
	BookManager bookmanager;
	bookmanager.ShowBook();
}

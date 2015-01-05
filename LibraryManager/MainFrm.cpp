
// MainFrm.cpp : CMainFrame ���ʵ��
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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
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
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);*/


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	m_strTitle="LibraryManager"; 
	return TRUE;
}

// CMainFrame ���

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


// CMainFrame ��Ϣ�������

void CMainFrame::OnAdminlogin()
{
	// TODO: �ڴ���������������
	Login Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnLibraryrule()
{
	// TODO: �ڴ���������������
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
	MessageBox(string,TEXT("���Ĺ���"));
}


void CMainFrame::OnExit()
{
	// TODO: �ڴ���������������
	exit(0);
}

void CMainFrame::OnBooksearch()
{
	// TODO: �ڴ���������������
	BookSearch Dlg;
	Dlg.DoModal();
}

void CMainFrame::OnExitlogin()
{
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
	PasswordEdit Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnLend()
{
	// TODO: �ڴ���������������
	BookLend Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnReturn()
{
	// TODO: �ڴ���������������
	BookReturn Dlg;
	Dlg.DoModal();
}



void CMainFrame::OnBooksearchbyname()
{
	// TODO: �ڴ���������������
	BookSearch Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnBookadd()
{
	// TODO: �ڴ���������������
	BookAdd Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnBookedit()
{
	// TODO: �ڴ���������������
	BookEdit Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnBookdelete()
{
	// TODO: �ڴ���������������
	BookDelete Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnStudentadd()
{
	// TODO: �ڴ���������������
	StudentAdd Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnStudentsearch()
{
	// TODO: �ڴ���������������
	StudentSearch Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnStudentdelete()
{
	// TODO: �ڴ���������������
	StudentDelete Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnStudentshow()
{
	// TODO: �ڴ���������������
	StudentManager studentmanager;
	studentmanager.ShowStudent();
}


void CMainFrame::OnStudentedit()
{
	// TODO: �ڴ���������������
	StudentEdit Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnStudentsort()
{
	// TODO: �ڴ���������������
	StudentSort Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnStaffadd()
{
	// TODO: �ڴ���������������
	StaffAdd Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnStaffsearch()
{
	// TODO: �ڴ���������������
	StaffSearch Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnStaffdelete()
{
	// TODO: �ڴ���������������
	StaffDelete Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnStaffshow()
{
	// TODO: �ڴ���������������
	StaffManager staffmanager;
	staffmanager.ShowStaff();
}


void CMainFrame::OnStaffedit()
{
	// TODO: �ڴ���������������
	StaffEdit Dlg;
	Dlg.DoModal();
}


void CMainFrame::OnBackup()
{
	// TODO: �ڴ���������������
	LPITEMIDLIST rootLoation;
	SHGetSpecialFolderLocation(NULL,CSIDL_DESKTOP,&rootLoation);
	BROWSEINFO bi;
	ZeroMemory(&bi,sizeof(bi));
	bi.pidlRoot=rootLoation;
	bi.lpszTitle=_T("ѡ�񱸷��ļ���Ŀ¼");
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
	// TODO: �ڴ���������������
	CFileDialog dlg(TRUE,_T("txt"),_T(""),OFN_FILEMUSTEXIST|OFN_HIDEREADONLY,_T("�ı�|*.txt|�����ļ�|*||"));
	if(dlg.DoModal()==IDOK)
	{
		CopyFile(dlg.GetPathName(),dlg.GetFileName(),FALSE);
	}
}


void CMainFrame::OnGuide()
{
	// TODO: �ڴ���������������.
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
	MessageBox(string,TEXT("ʹ�÷���"));
}


void CMainFrame::OnBookshow()
{
	// TODO: �ڴ���������������
	BookManager bookmanager;
	bookmanager.ShowBook();
}

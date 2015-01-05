// Login.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "Login.h"
#include "afxdialogex.h"
#include "StaffManager.h"
#include "AdminManager.h"


// Login 对话框

IMPLEMENT_DYNAMIC(Login, CDialogEx)

Login::Login(CWnd* pParent /*=NULL*/)
	: CDialogEx(Login::IDD, pParent)
{
	
}

Login::~Login()
{
}

void Login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LoginUserName, Edit_LoginUserName);
	DDX_Control(pDX, IDC_LoginPassword, Edit_LoginPassword);
	DDX_Control(pDX, IDC_LoginClassify, ComboBox_LoginClassify);
}


BEGIN_MESSAGE_MAP(Login, CDialogEx)
	ON_BN_CLICKED(IDLogin, &Login::OnBnClickedLogin)
	ON_BN_CLICKED(IDCANCEL, &Login::OnBnClickedCancel)
END_MESSAGE_MAP()


// Login 消息处理程序

void Login::OnBnClickedLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	CString username,password;
	int choice;
	Edit_LoginUserName.GetWindowTextW(username);
	Edit_LoginPassword.GetWindowTextW(password);
	choice=ComboBox_LoginClassify.GetCurSel();
	if(choice==0)
	{
		//MessageBox(TEXT("工作人员"),NULL);
		Staff loginStaff=Staff(TEXT(""),0,0,0,username,password);
		StaffManager staffmanager;
		if(username==TEXT(""))
			MessageBox(TEXT("请输入用户名"),TEXT("错误"));
		else if(password==TEXT(""))
			MessageBox(TEXT("请输入密码"),TEXT("错误"));
		else if(staffmanager.CheckStaff(loginStaff))
		{
			staffmanager.setCurrentUser(staffmanager.SearchStaff(loginStaff.getUserName(),loginStaff.getPassword()));
			staffmanager.getCurrentUser().ShowMenu();
			Login::OnCancel();
		}
		else
			MessageBox(TEXT("用户名或密码错误"),TEXT("错误"));
	}
	else
	{
		//MessageBox(TEXT("管理员"),NULL);
		Admin loginAdmin=Admin(TEXT(""),0,0,0,username,password);
		AdminManager adminmanager;
		if(username==TEXT(""))
			MessageBox(TEXT("请输入用户名"),TEXT("错误"));
		else if(password==TEXT(""))
			MessageBox(TEXT("请输入密码"),TEXT("错误"));
		else if(adminmanager.CheckAdmin(loginAdmin))
		{
			adminmanager.setCurrentUser(loginAdmin);
			adminmanager.getCurrentUser().ShowMenu();
			Login::OnCancel();
		}
		else
			MessageBox(TEXT("用户名或密码错误"),TEXT("错误"));
	}
	//MessageBox(name+sex+ag+username+password,NULL,MB_OK);
}

void Login::OnBnClickedCancel()
{
	Login::OnCancel();
}

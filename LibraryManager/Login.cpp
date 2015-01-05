// Login.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "Login.h"
#include "afxdialogex.h"
#include "StaffManager.h"
#include "AdminManager.h"


// Login �Ի���

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


// Login ��Ϣ�������

void Login::OnBnClickedLogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString username,password;
	int choice;
	Edit_LoginUserName.GetWindowTextW(username);
	Edit_LoginPassword.GetWindowTextW(password);
	choice=ComboBox_LoginClassify.GetCurSel();
	if(choice==0)
	{
		//MessageBox(TEXT("������Ա"),NULL);
		Staff loginStaff=Staff(TEXT(""),0,0,0,username,password);
		StaffManager staffmanager;
		if(username==TEXT(""))
			MessageBox(TEXT("�������û���"),TEXT("����"));
		else if(password==TEXT(""))
			MessageBox(TEXT("����������"),TEXT("����"));
		else if(staffmanager.CheckStaff(loginStaff))
		{
			staffmanager.setCurrentUser(staffmanager.SearchStaff(loginStaff.getUserName(),loginStaff.getPassword()));
			staffmanager.getCurrentUser().ShowMenu();
			Login::OnCancel();
		}
		else
			MessageBox(TEXT("�û������������"),TEXT("����"));
	}
	else
	{
		//MessageBox(TEXT("����Ա"),NULL);
		Admin loginAdmin=Admin(TEXT(""),0,0,0,username,password);
		AdminManager adminmanager;
		if(username==TEXT(""))
			MessageBox(TEXT("�������û���"),TEXT("����"));
		else if(password==TEXT(""))
			MessageBox(TEXT("����������"),TEXT("����"));
		else if(adminmanager.CheckAdmin(loginAdmin))
		{
			adminmanager.setCurrentUser(loginAdmin);
			adminmanager.getCurrentUser().ShowMenu();
			Login::OnCancel();
		}
		else
			MessageBox(TEXT("�û������������"),TEXT("����"));
	}
	//MessageBox(name+sex+ag+username+password,NULL,MB_OK);
}

void Login::OnBnClickedCancel()
{
	Login::OnCancel();
}

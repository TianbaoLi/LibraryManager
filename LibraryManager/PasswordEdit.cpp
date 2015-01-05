// StaffEdit.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "PasswordEdit.h"
#include "afxdialogex.h"
#include "Person.h"
#include "StaffManager.h"


// StaffEdit 对话框

IMPLEMENT_DYNAMIC(PasswordEdit, CDialogEx)

PasswordEdit::PasswordEdit(CWnd* pParent /*=NULL*/)
	: CDialogEx(PasswordEdit::IDD, pParent)
{

}

PasswordEdit::~PasswordEdit()
{
}

void PasswordEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_StaffEditPassword2, Edit_StaffEditPassword);
	DDX_Control(pDX, IDC_StaffEditPasswordCorrect, Edit_StaffEditPasswordCorrect);
}


BEGIN_MESSAGE_MAP(PasswordEdit, CDialogEx)
	ON_BN_CLICKED(IDStaffEdit, &PasswordEdit::OnBnClickedStaffedit)
END_MESSAGE_MAP()


// StaffEdit 消息处理程序


void PasswordEdit::OnBnClickedStaffedit()
{
	// TODO: 在此添加控件通知处理程序代码
	CString password,passwordCorrect;
	Edit_StaffEditPassword.GetWindowTextW(password);
	Edit_StaffEditPasswordCorrect.GetWindowTextW(passwordCorrect);
	StaffManager staffmanager;
	Staff editStaff=Staff(staffmanager.getCurrentUser().getName(),staffmanager.getCurrentUser().getSex(),staffmanager.getCurrentUser().getAge(),staffmanager.getCurrentUser().getNumber(),staffmanager.getCurrentUser().getUserName(),password);
	if(password==TEXT(""))
		MessageBox(TEXT("请输入密码"),TEXT("错误"));
	else if(passwordCorrect==TEXT(""))
		MessageBox(TEXT("请输入密码"),TEXT("错误"));
	else if(password!=passwordCorrect)
		MessageBox(TEXT("两次密码不一致"),TEXT("错误"));
	else
	{
		staffmanager.EditStaffPassword(editStaff);
		staffmanager.setCurrentUser(editStaff);
		MessageBox(TEXT("成功修改"),TEXT("成功"));
		PasswordEdit::OnCancel();
	}
}

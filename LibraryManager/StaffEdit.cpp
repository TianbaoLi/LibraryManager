// StaffEdit.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "StaffEdit.h"
#include "afxdialogex.h"
#include "StaffManager.h"


// StaffEdit 对话框

IMPLEMENT_DYNAMIC(StaffEdit, CDialogEx)

StaffEdit::StaffEdit(CWnd* pParent /*=NULL*/)
	: CDialogEx(StaffEdit::IDD, pParent)
{

}

StaffEdit::~StaffEdit()
{
}

void StaffEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, Edit_StaffEditName);
	DDX_Control(pDX, IDC_EDIT3, Edit_StaffEditAge);
	DDX_Control(pDX, IDC_EDIT4, Edit_StaffEditNumber);
	DDX_Control(pDX, IDC_LoginClassify, ComboBox_StaffEditSex);
	DDX_Control(pDX, IDC_EDIT5, Edit_StaffEditUserName);
	DDX_Control(pDX, IDC_EDIT7, Edit_StaffEditPassword);
}


BEGIN_MESSAGE_MAP(StaffEdit, CDialogEx)
	ON_BN_CLICKED(IDStaffEdit, &StaffEdit::OnBnClickedStaffedit)
END_MESSAGE_MAP()


// StaffEdit 消息处理程序


void StaffEdit::OnBnClickedStaffedit()
{
	// TODO: 在此添加控件通知处理程序代码
	CString name,temp,username,password;
	char sex;
	int choice,age,number;
	Edit_StaffEditName.GetWindowTextW(name);
	if(name==TEXT(""))
		MessageBox(TEXT("请输入学生名"),TEXT("错误"));
	else
	{
		Edit_StaffEditAge.GetWindowTextW(temp);
		if(temp==TEXT(""))
			MessageBox(TEXT("请输入年龄"),TEXT("错误"));
		else
		{
			age=StrToInt(temp);
			Edit_StaffEditNumber.GetWindowTextW(temp);
			if(temp==TEXT(""))
				MessageBox(TEXT("请输入学号"),TEXT("错误"));
			else
			{
				number=StrToInt(temp);
				Edit_StaffEditUserName.GetWindowTextW(username);
				if(temp==TEXT(""))
					MessageBox(TEXT("请输入用户名"),TEXT("错误"));
				else
				{
					Edit_StaffEditPassword.GetWindowTextW(password);
					if(temp==TEXT(""))
						MessageBox(TEXT("请输入密码"),TEXT("错误"));
					else
					{
						number=StrToInt(temp);
						choice=ComboBox_StaffEditSex.GetCurSel();
						if(choice==0)sex='f';
						else sex='m';
						Staff staff=Staff(name,sex,age,number,username,password);
						StaffManager staffmanager;
						if(staffmanager.EditStaff(staff)==1)
							MessageBox(TEXT("成功修改"),TEXT("成功"));
						else 
							MessageBox(TEXT("修改失败，未找到工作人员"),TEXT("失败"));
						StaffEdit::OnCancel();
					}
				}
			}
		}
	}
}

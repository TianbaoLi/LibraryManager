// StudentAdd.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "StudentAdd.h"
#include "afxdialogex.h"
#include "StudentManager.h"


// StudentAdd 对话框

IMPLEMENT_DYNAMIC(StudentAdd, CDialogEx)

StudentAdd::StudentAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(StudentAdd::IDD, pParent)
{

}

StudentAdd::~StudentAdd()
{
}

void StudentAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, Edit_StudentAddName);
	DDX_Control(pDX, IDC_EDIT3, Edit_StudentAddAge);
	DDX_Control(pDX, IDC_EDIT4, Edit_StudentAddNumber);
	DDX_Control(pDX, IDC_LoginClassify, ComboBox_StudentAddSex);
}


BEGIN_MESSAGE_MAP(StudentAdd, CDialogEx)
	ON_BN_CLICKED(IDStudentAdd, &StudentAdd::OnBnClickedStudentadd)
END_MESSAGE_MAP()


// StudentAdd 消息处理程序


void StudentAdd::OnBnClickedStudentadd()
{
	// TODO: 在此添加控件通知处理程序代码
	CString name,temp;
	char sex;
	int choice,age,number;
	Edit_StudentAddName.GetWindowTextW(name);
	if(name==TEXT(""))
		MessageBox(TEXT("请输入学生名"),TEXT("错误"));
	else
	{
		Edit_StudentAddAge.GetWindowTextW(temp);
		if(temp==TEXT(""))
			MessageBox(TEXT("请输入年龄"),TEXT("错误"));
		else
		{
			age=StrToInt(temp);
			Edit_StudentAddNumber.GetWindowTextW(temp);
			if(temp==TEXT(""))
				MessageBox(TEXT("请输入学号"),TEXT("错误"));
			else
			{
				number=StrToInt(temp);
				choice=ComboBox_StudentAddSex.GetCurSel();
				if(choice==0)sex='f';
				else sex='m';
				Student student=Student(name,sex,age,number);
				StudentManager studentmanager;
				studentmanager.AddStudent(student);
				MessageBox(TEXT("成功添加"),TEXT("成功"));
				StudentAdd::OnCancel();
			}
		}
	}
}

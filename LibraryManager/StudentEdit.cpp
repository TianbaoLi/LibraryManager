// StudentEdit.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "StudentEdit.h"
#include "afxdialogex.h"
#include "StudentManager.h"


// StudentEdit 对话框

IMPLEMENT_DYNAMIC(StudentEdit, CDialogEx)

StudentEdit::StudentEdit(CWnd* pParent /*=NULL*/)
	: CDialogEx(StudentEdit::IDD, pParent)
{

}

StudentEdit::~StudentEdit()
{
}

void StudentEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, Edit_StudentEditName);
	DDX_Control(pDX, IDC_EDIT3, Edit_StudentEditAge);
	DDX_Control(pDX, IDC_EDIT4, Edit_StudentEditNumber);
	DDX_Control(pDX, IDC_LoginClassify, ComboBox_StudentEditSex);
}


BEGIN_MESSAGE_MAP(StudentEdit, CDialogEx)
	ON_BN_CLICKED(IDStudentEdit, &StudentEdit::OnBnClickedStudentedit)
END_MESSAGE_MAP()


// StudentEdit 消息处理程序


void StudentEdit::OnBnClickedStudentedit()
{
	// TODO: 在此添加控件通知处理程序代码
	CString name,temp;
	char sex;
	int choice,age,number;
	Edit_StudentEditName.GetWindowTextW(name);
	if(name==TEXT(""))
		MessageBox(TEXT("请输入学生名"),TEXT("错误"));
	else
	{
		Edit_StudentEditAge.GetWindowTextW(temp);
		if(temp==TEXT(""))
			MessageBox(TEXT("请输入年龄"),TEXT("错误"));
		else
		{
			age=StrToInt(temp);
			Edit_StudentEditNumber.GetWindowTextW(temp);
			if(temp==TEXT(""))
				MessageBox(TEXT("请输入学号"),TEXT("错误"));
			else
			{
				number=StrToInt(temp);
				choice=ComboBox_StudentEditSex.GetCurSel();
				if(choice==0)sex='f';
				else sex='m';
				Student student=Student(name,sex,age,number);
				StudentManager studentmanager;
				if(studentmanager.EditStudent(student)==1)
					MessageBox(TEXT("成功修改"),TEXT("成功"));
				else 
					MessageBox(TEXT("修改失败，未找到学生"),TEXT("失败"));
				StudentEdit::OnCancel();
			}
		}
	}
}

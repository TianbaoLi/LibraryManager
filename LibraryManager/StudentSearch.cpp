// StudentSearch.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "StudentSearch.h"
#include "afxdialogex.h"
#include "StudentManager.h"


// StudentSearch 对话框

IMPLEMENT_DYNAMIC(StudentSearch, CDialogEx)

StudentSearch::StudentSearch(CWnd* pParent /*=NULL*/)
	: CDialogEx(StudentSearch::IDD, pParent)
{

}

StudentSearch::~StudentSearch()
{
}

void StudentSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, Edit_StudentSearchName);
	DDX_Control(pDX, IDC_EDIT10, Edit_StudentSearchNumber);
}


BEGIN_MESSAGE_MAP(StudentSearch, CDialogEx)
	ON_BN_CLICKED(IDStudentSearch, &StudentSearch::OnBnClickedStudentsearch)
END_MESSAGE_MAP()


// StudentSearch 消息处理程序


void StudentSearch::OnBnClickedStudentsearch()
{
	// TODO: 在此添加控件通知处理程序代码
	CString name,temp;
	int number;
	Edit_StudentSearchName.GetWindowTextW(name);
	Edit_StudentSearchNumber.GetWindowTextW(temp);
	if(name==TEXT("")&&temp==TEXT(""))
		MessageBox(TEXT("请输入姓名或学号"),TEXT("错误"));
	else if(temp==TEXT(""))
	{
		StudentManager studentmaneger;
		Student student=studentmaneger.SearchStudent(name);
		if(student.getName()!="")
		{
			studentmaneger.ShowStudent(student);
			StudentSearch::OnCancel();
		}
		else MessageBox(TEXT("未找到学生"),TEXT("错误"));
	}
	else
	{
		number=StrToInt(temp);
		StudentManager studentmaneger;
		Student student=studentmaneger.SearchStudent(number);
		if(student.getName()!="")
		{
			studentmaneger.ShowStudent(student);
			StudentSearch::OnCancel();
		}
		else MessageBox(TEXT("未找到学生"),TEXT("错误"));
	}
}

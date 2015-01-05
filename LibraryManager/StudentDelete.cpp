// StudentDelete.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "StudentDelete.h"
#include "afxdialogex.h"
#include "StudentManager.h"


// StudentDelete 对话框

IMPLEMENT_DYNAMIC(StudentDelete, CDialogEx)

StudentDelete::StudentDelete(CWnd* pParent /*=NULL*/)
	: CDialogEx(StudentDelete::IDD, pParent)
{

}

StudentDelete::~StudentDelete()
{
}

void StudentDelete::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, Edit_StudentDeleteName);
	DDX_Control(pDX, IDC_EDIT10, Edit_StudentDeleteNumber);
}


BEGIN_MESSAGE_MAP(StudentDelete, CDialogEx)
	ON_BN_CLICKED(IDStudentDelete, &StudentDelete::OnBnClickedStudentdelete)
END_MESSAGE_MAP()


// StudentDelete 消息处理程序


void StudentDelete::OnBnClickedStudentdelete()
{
	// TODO: 在此添加控件通知处理程序代码
	CString name,temp;
	int number;
	Edit_StudentDeleteName.GetWindowTextW(name);
	Edit_StudentDeleteNumber.GetWindowTextW(temp);
	if(name==TEXT("")&&temp==TEXT(""))
		MessageBox(TEXT("请输入姓名或学号"),TEXT("错误"));
	else if(temp==TEXT(""))
	{
		StudentManager studentmanager;
		if(studentmanager.DeleteStudent(name)==1)
		{
			MessageBox(TEXT("成功删除"),TEXT("成功"));
			studentmanager.UpdateStudentList();
			StudentDelete::OnCancel();
		}
		else
			MessageBox(TEXT("删除失败，未找到学生"),TEXT("失败"));
	}
	else
	{
		number=StrToInt(temp);
		StudentManager studentmanager;
		if(studentmanager.DeleteStudent(number)==1)
		{
			MessageBox(TEXT("成功删除"),TEXT("成功"));
			studentmanager.UpdateStudentList();
			StudentDelete::OnCancel();
		}
		else
			MessageBox(TEXT("删除失败，未找到学生"),TEXT("失败"));
	}
}

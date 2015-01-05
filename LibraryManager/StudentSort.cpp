// StudentSort.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "StudentSort.h"
#include "afxdialogex.h"
#include "StudentManager.h"


// StudentSort 对话框

IMPLEMENT_DYNAMIC(StudentSort, CDialogEx)

StudentSort::StudentSort(CWnd* pParent /*=NULL*/)
	: CDialogEx(StudentSort::IDD, pParent)
{

}

StudentSort::~StudentSort()
{
}

void StudentSort::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, ComboBox_StudentSortCmp);
}


BEGIN_MESSAGE_MAP(StudentSort, CDialogEx)
	ON_BN_CLICKED(IDStudentSort, &StudentSort::OnBnClickedStudentsort)
END_MESSAGE_MAP()


// StudentSort 消息处理程序


void StudentSort::OnBnClickedStudentsort()
{
	// TODO: 在此添加控件通知处理程序代码
	int choice=ComboBox_StudentSortCmp.GetCurSel();
	StudentManager studentmanager;
	if(choice==0)
	{
		studentmanager.SortStudentByAge();
		studentmanager.UpdateStudentList();
		studentmanager.ShowStudent();
		StudentSort;;OnCancel();
	}
	else
	{
		studentmanager.SortStudentByName();
		studentmanager.UpdateStudentList();
		studentmanager.ShowStudent();
		StudentSort;;OnCancel();
	}
}

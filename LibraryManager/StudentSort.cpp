// StudentSort.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "StudentSort.h"
#include "afxdialogex.h"
#include "StudentManager.h"


// StudentSort �Ի���

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


// StudentSort ��Ϣ�������


void StudentSort::OnBnClickedStudentsort()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

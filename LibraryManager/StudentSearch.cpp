// StudentSearch.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "StudentSearch.h"
#include "afxdialogex.h"
#include "StudentManager.h"


// StudentSearch �Ի���

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


// StudentSearch ��Ϣ�������


void StudentSearch::OnBnClickedStudentsearch()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString name,temp;
	int number;
	Edit_StudentSearchName.GetWindowTextW(name);
	Edit_StudentSearchNumber.GetWindowTextW(temp);
	if(name==TEXT("")&&temp==TEXT(""))
		MessageBox(TEXT("������������ѧ��"),TEXT("����"));
	else if(temp==TEXT(""))
	{
		StudentManager studentmaneger;
		Student student=studentmaneger.SearchStudent(name);
		if(student.getName()!="")
		{
			studentmaneger.ShowStudent(student);
			StudentSearch::OnCancel();
		}
		else MessageBox(TEXT("δ�ҵ�ѧ��"),TEXT("����"));
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
		else MessageBox(TEXT("δ�ҵ�ѧ��"),TEXT("����"));
	}
}

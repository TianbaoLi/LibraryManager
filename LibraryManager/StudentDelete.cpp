// StudentDelete.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "StudentDelete.h"
#include "afxdialogex.h"
#include "StudentManager.h"


// StudentDelete �Ի���

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


// StudentDelete ��Ϣ�������


void StudentDelete::OnBnClickedStudentdelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString name,temp;
	int number;
	Edit_StudentDeleteName.GetWindowTextW(name);
	Edit_StudentDeleteNumber.GetWindowTextW(temp);
	if(name==TEXT("")&&temp==TEXT(""))
		MessageBox(TEXT("������������ѧ��"),TEXT("����"));
	else if(temp==TEXT(""))
	{
		StudentManager studentmanager;
		if(studentmanager.DeleteStudent(name)==1)
		{
			MessageBox(TEXT("�ɹ�ɾ��"),TEXT("�ɹ�"));
			studentmanager.UpdateStudentList();
			StudentDelete::OnCancel();
		}
		else
			MessageBox(TEXT("ɾ��ʧ�ܣ�δ�ҵ�ѧ��"),TEXT("ʧ��"));
	}
	else
	{
		number=StrToInt(temp);
		StudentManager studentmanager;
		if(studentmanager.DeleteStudent(number)==1)
		{
			MessageBox(TEXT("�ɹ�ɾ��"),TEXT("�ɹ�"));
			studentmanager.UpdateStudentList();
			StudentDelete::OnCancel();
		}
		else
			MessageBox(TEXT("ɾ��ʧ�ܣ�δ�ҵ�ѧ��"),TEXT("ʧ��"));
	}
}

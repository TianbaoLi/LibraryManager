// StudentAdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "StudentAdd.h"
#include "afxdialogex.h"
#include "StudentManager.h"


// StudentAdd �Ի���

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


// StudentAdd ��Ϣ�������


void StudentAdd::OnBnClickedStudentadd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString name,temp;
	char sex;
	int choice,age,number;
	Edit_StudentAddName.GetWindowTextW(name);
	if(name==TEXT(""))
		MessageBox(TEXT("������ѧ����"),TEXT("����"));
	else
	{
		Edit_StudentAddAge.GetWindowTextW(temp);
		if(temp==TEXT(""))
			MessageBox(TEXT("����������"),TEXT("����"));
		else
		{
			age=StrToInt(temp);
			Edit_StudentAddNumber.GetWindowTextW(temp);
			if(temp==TEXT(""))
				MessageBox(TEXT("������ѧ��"),TEXT("����"));
			else
			{
				number=StrToInt(temp);
				choice=ComboBox_StudentAddSex.GetCurSel();
				if(choice==0)sex='f';
				else sex='m';
				Student student=Student(name,sex,age,number);
				StudentManager studentmanager;
				studentmanager.AddStudent(student);
				MessageBox(TEXT("�ɹ����"),TEXT("�ɹ�"));
				StudentAdd::OnCancel();
			}
		}
	}
}

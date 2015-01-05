// StudentEdit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "StudentEdit.h"
#include "afxdialogex.h"
#include "StudentManager.h"


// StudentEdit �Ի���

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


// StudentEdit ��Ϣ�������


void StudentEdit::OnBnClickedStudentedit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString name,temp;
	char sex;
	int choice,age,number;
	Edit_StudentEditName.GetWindowTextW(name);
	if(name==TEXT(""))
		MessageBox(TEXT("������ѧ����"),TEXT("����"));
	else
	{
		Edit_StudentEditAge.GetWindowTextW(temp);
		if(temp==TEXT(""))
			MessageBox(TEXT("����������"),TEXT("����"));
		else
		{
			age=StrToInt(temp);
			Edit_StudentEditNumber.GetWindowTextW(temp);
			if(temp==TEXT(""))
				MessageBox(TEXT("������ѧ��"),TEXT("����"));
			else
			{
				number=StrToInt(temp);
				choice=ComboBox_StudentEditSex.GetCurSel();
				if(choice==0)sex='f';
				else sex='m';
				Student student=Student(name,sex,age,number);
				StudentManager studentmanager;
				if(studentmanager.EditStudent(student)==1)
					MessageBox(TEXT("�ɹ��޸�"),TEXT("�ɹ�"));
				else 
					MessageBox(TEXT("�޸�ʧ�ܣ�δ�ҵ�ѧ��"),TEXT("ʧ��"));
				StudentEdit::OnCancel();
			}
		}
	}
}

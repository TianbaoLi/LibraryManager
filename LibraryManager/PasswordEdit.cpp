// StaffEdit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "PasswordEdit.h"
#include "afxdialogex.h"
#include "Person.h"
#include "StaffManager.h"


// StaffEdit �Ի���

IMPLEMENT_DYNAMIC(PasswordEdit, CDialogEx)

PasswordEdit::PasswordEdit(CWnd* pParent /*=NULL*/)
	: CDialogEx(PasswordEdit::IDD, pParent)
{

}

PasswordEdit::~PasswordEdit()
{
}

void PasswordEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_StaffEditPassword2, Edit_StaffEditPassword);
	DDX_Control(pDX, IDC_StaffEditPasswordCorrect, Edit_StaffEditPasswordCorrect);
}


BEGIN_MESSAGE_MAP(PasswordEdit, CDialogEx)
	ON_BN_CLICKED(IDStaffEdit, &PasswordEdit::OnBnClickedStaffedit)
END_MESSAGE_MAP()


// StaffEdit ��Ϣ�������


void PasswordEdit::OnBnClickedStaffedit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString password,passwordCorrect;
	Edit_StaffEditPassword.GetWindowTextW(password);
	Edit_StaffEditPasswordCorrect.GetWindowTextW(passwordCorrect);
	StaffManager staffmanager;
	Staff editStaff=Staff(staffmanager.getCurrentUser().getName(),staffmanager.getCurrentUser().getSex(),staffmanager.getCurrentUser().getAge(),staffmanager.getCurrentUser().getNumber(),staffmanager.getCurrentUser().getUserName(),password);
	if(password==TEXT(""))
		MessageBox(TEXT("����������"),TEXT("����"));
	else if(passwordCorrect==TEXT(""))
		MessageBox(TEXT("����������"),TEXT("����"));
	else if(password!=passwordCorrect)
		MessageBox(TEXT("�������벻һ��"),TEXT("����"));
	else
	{
		staffmanager.EditStaffPassword(editStaff);
		staffmanager.setCurrentUser(editStaff);
		MessageBox(TEXT("�ɹ��޸�"),TEXT("�ɹ�"));
		PasswordEdit::OnCancel();
	}
}

// StaffEdit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "StaffEdit.h"
#include "afxdialogex.h"
#include "StaffManager.h"


// StaffEdit �Ի���

IMPLEMENT_DYNAMIC(StaffEdit, CDialogEx)

StaffEdit::StaffEdit(CWnd* pParent /*=NULL*/)
	: CDialogEx(StaffEdit::IDD, pParent)
{

}

StaffEdit::~StaffEdit()
{
}

void StaffEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, Edit_StaffEditName);
	DDX_Control(pDX, IDC_EDIT3, Edit_StaffEditAge);
	DDX_Control(pDX, IDC_EDIT4, Edit_StaffEditNumber);
	DDX_Control(pDX, IDC_LoginClassify, ComboBox_StaffEditSex);
	DDX_Control(pDX, IDC_EDIT5, Edit_StaffEditUserName);
	DDX_Control(pDX, IDC_EDIT7, Edit_StaffEditPassword);
}


BEGIN_MESSAGE_MAP(StaffEdit, CDialogEx)
	ON_BN_CLICKED(IDStaffEdit, &StaffEdit::OnBnClickedStaffedit)
END_MESSAGE_MAP()


// StaffEdit ��Ϣ�������


void StaffEdit::OnBnClickedStaffedit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString name,temp,username,password;
	char sex;
	int choice,age,number;
	Edit_StaffEditName.GetWindowTextW(name);
	if(name==TEXT(""))
		MessageBox(TEXT("������ѧ����"),TEXT("����"));
	else
	{
		Edit_StaffEditAge.GetWindowTextW(temp);
		if(temp==TEXT(""))
			MessageBox(TEXT("����������"),TEXT("����"));
		else
		{
			age=StrToInt(temp);
			Edit_StaffEditNumber.GetWindowTextW(temp);
			if(temp==TEXT(""))
				MessageBox(TEXT("������ѧ��"),TEXT("����"));
			else
			{
				number=StrToInt(temp);
				Edit_StaffEditUserName.GetWindowTextW(username);
				if(temp==TEXT(""))
					MessageBox(TEXT("�������û���"),TEXT("����"));
				else
				{
					Edit_StaffEditPassword.GetWindowTextW(password);
					if(temp==TEXT(""))
						MessageBox(TEXT("����������"),TEXT("����"));
					else
					{
						number=StrToInt(temp);
						choice=ComboBox_StaffEditSex.GetCurSel();
						if(choice==0)sex='f';
						else sex='m';
						Staff staff=Staff(name,sex,age,number,username,password);
						StaffManager staffmanager;
						if(staffmanager.EditStaff(staff)==1)
							MessageBox(TEXT("�ɹ��޸�"),TEXT("�ɹ�"));
						else 
							MessageBox(TEXT("�޸�ʧ�ܣ�δ�ҵ�������Ա"),TEXT("ʧ��"));
						StaffEdit::OnCancel();
					}
				}
			}
		}
	}
}

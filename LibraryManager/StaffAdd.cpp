// StaffAdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "StaffAdd.h"
#include "afxdialogex.h"
#include "StaffManager.h"


// StaffAdd �Ի���

IMPLEMENT_DYNAMIC(StaffAdd, CDialogEx)

StaffAdd::StaffAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(StaffAdd::IDD, pParent)
{

}

StaffAdd::~StaffAdd()
{
}

void StaffAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, Edit_StaffAddName);
	DDX_Control(pDX, IDC_EDIT3, Edit_StaffAddAge);
	DDX_Control(pDX, IDC_EDIT4, Edit_StaffAddNumber);
	DDX_Control(pDX, IDC_EDIT5, Edit_StaffAddUserName);
	DDX_Control(pDX, IDC_EDIT7, Edit_StaffAddPassword);
	DDX_Control(pDX, IDC_LoginClassify, ComboBox_StaffAddSex);
}


BEGIN_MESSAGE_MAP(StaffAdd, CDialogEx)
	ON_BN_CLICKED(IDStaffAdd, &StaffAdd::OnBnClickedStaffadd)
END_MESSAGE_MAP()


// StaffAdd ��Ϣ�������


void StaffAdd::OnBnClickedStaffadd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString name,temp,username,password;
	char sex;
	int choice,age,number;
	Edit_StaffAddName.GetWindowTextW(name);
	if(name==TEXT(""))
		MessageBox(TEXT("������ѧ����"),TEXT("����"));
	else
	{
		Edit_StaffAddAge.GetWindowTextW(temp);
		if(temp==TEXT(""))
			MessageBox(TEXT("����������"),TEXT("����"));
		else
		{
			age=StrToInt(temp);
			Edit_StaffAddNumber.GetWindowTextW(temp);
			if(temp==TEXT(""))
				MessageBox(TEXT("������ѧ��"),TEXT("����"));
			else
			{
				number=StrToInt(temp);
				Edit_StaffAddUserName.GetWindowTextW(username);
				if(temp==TEXT(""))
					MessageBox(TEXT("�������û���"),TEXT("����"));
				else
				{
					Edit_StaffAddPassword.GetWindowTextW(password);
					if(temp==TEXT(""))
						MessageBox(TEXT("����������"),TEXT("����"));
					else
					{
						number=StrToInt(temp);
						choice=ComboBox_StaffAddSex.GetCurSel();
						if(choice==0)sex='f';
						else sex='m';
						Staff staff=Staff(name,sex,age,number,username,password);
						StaffManager staffmanager;
						staffmanager.AddStaff(staff);
						MessageBox(TEXT("�ɹ����"),TEXT("�ɹ�"));
						StaffAdd::OnCancel();
					}
				}
			}
		}
	}
}

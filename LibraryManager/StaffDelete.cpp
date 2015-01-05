// StaffDelete.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "StaffDelete.h"
#include "afxdialogex.h"
#include "StaffManager.h"


// StaffDelete �Ի���

IMPLEMENT_DYNAMIC(StaffDelete, CDialogEx)

StaffDelete::StaffDelete(CWnd* pParent /*=NULL*/)
	: CDialogEx(StaffDelete::IDD, pParent)
{

}

StaffDelete::~StaffDelete()
{
}

void StaffDelete::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT11, Edit_StaffDeleteName);
}


BEGIN_MESSAGE_MAP(StaffDelete, CDialogEx)
	ON_BN_CLICKED(IDStaffDelete, &StaffDelete::OnBnClickedStaffdelete)
END_MESSAGE_MAP()


// StaffDelete ��Ϣ�������


void StaffDelete::OnBnClickedStaffdelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString name;
	Edit_StaffDeleteName.GetWindowTextW(name);
	if(name==TEXT(""))
		MessageBox(TEXT("����������"),TEXT("����"));
	else
	{
		StaffManager staffmanager;
		if(staffmanager.DeleteStaff(name)==1)
		{
			MessageBox(TEXT("�ɹ�ɾ��"),TEXT("�ɹ�"));
			staffmanager.UpdateStaffList();
			StaffDelete::OnCancel();
		}
		else
			MessageBox(TEXT("ɾ��ʧ�ܣ�δ�ҵ�������Ա"),TEXT("ʧ��"));
	}
}

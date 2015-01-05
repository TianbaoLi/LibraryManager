// StaffSearch.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "StaffSearch.h"
#include "afxdialogex.h"
#include "StaffManager.h"


// StaffSearch �Ի���

IMPLEMENT_DYNAMIC(StaffSearch, CDialogEx)

StaffSearch::StaffSearch(CWnd* pParent /*=NULL*/)
	: CDialogEx(StaffSearch::IDD, pParent)
{

}

StaffSearch::~StaffSearch()
{
}

void StaffSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BookSearch, Edit_StaffSearchName);
}


BEGIN_MESSAGE_MAP(StaffSearch, CDialogEx)
	ON_BN_CLICKED(ID_StaffSearch, &StaffSearch::OnBnClickedStaffsearch)
END_MESSAGE_MAP()


// StaffSearch ��Ϣ�������


void StaffSearch::OnBnClickedStaffsearch()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString name;
	Edit_StaffSearchName.GetWindowTextW(name);
	if(name==TEXT(""))
		MessageBox(TEXT("����������"),TEXT("����"));
	else
	{
		StaffManager staffmanager;
		Staff staff=staffmanager.SearchStaff(name);
		if(staff.getName()!="")
		{
			staffmanager.ShowStaff(staff);
			StaffSearch::OnCancel();
		}
		else MessageBox(TEXT("δ�ҵ�������Ա"),TEXT("����"));
	}
}

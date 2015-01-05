// StaffSearch.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "StaffSearch.h"
#include "afxdialogex.h"
#include "StaffManager.h"


// StaffSearch 对话框

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


// StaffSearch 消息处理程序


void StaffSearch::OnBnClickedStaffsearch()
{
	// TODO: 在此添加控件通知处理程序代码
	CString name;
	Edit_StaffSearchName.GetWindowTextW(name);
	if(name==TEXT(""))
		MessageBox(TEXT("请输入姓名"),TEXT("错误"));
	else
	{
		StaffManager staffmanager;
		Staff staff=staffmanager.SearchStaff(name);
		if(staff.getName()!="")
		{
			staffmanager.ShowStaff(staff);
			StaffSearch::OnCancel();
		}
		else MessageBox(TEXT("未找到工作人员"),TEXT("错误"));
	}
}

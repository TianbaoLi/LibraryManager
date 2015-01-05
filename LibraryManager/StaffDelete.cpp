// StaffDelete.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "StaffDelete.h"
#include "afxdialogex.h"
#include "StaffManager.h"


// StaffDelete 对话框

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


// StaffDelete 消息处理程序


void StaffDelete::OnBnClickedStaffdelete()
{
	// TODO: 在此添加控件通知处理程序代码
	CString name;
	Edit_StaffDeleteName.GetWindowTextW(name);
	if(name==TEXT(""))
		MessageBox(TEXT("请输入姓名"),TEXT("错误"));
	else
	{
		StaffManager staffmanager;
		if(staffmanager.DeleteStaff(name)==1)
		{
			MessageBox(TEXT("成功删除"),TEXT("成功"));
			staffmanager.UpdateStaffList();
			StaffDelete::OnCancel();
		}
		else
			MessageBox(TEXT("删除失败，未找到工作人员"),TEXT("失败"));
	}
}

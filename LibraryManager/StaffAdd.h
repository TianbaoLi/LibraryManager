#pragma once
#include "afxwin.h"


// StaffAdd 对话框

class StaffAdd : public CDialogEx
{
	DECLARE_DYNAMIC(StaffAdd)

public:
	StaffAdd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~StaffAdd();

// 对话框数据
	enum { IDD = IDD_StaffAdd };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();
		ComboBox_StaffAddSex.AddString(TEXT("m"));
		ComboBox_StaffAddSex.AddString(TEXT("f"));
		ComboBox_StaffAddSex.SetCurSel(1);
		return true;
	}
	afx_msg void OnBnClickedStaffadd();
	CEdit Edit_StaffAddName;
	CEdit Edit_StaffAddAge;
	CEdit Edit_StaffAddNumber;
	CEdit Edit_StaffAddUserName;
	CEdit Edit_StaffAddPassword;
	CComboBox ComboBox_StaffAddSex;
};

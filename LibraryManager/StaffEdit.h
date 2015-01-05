#pragma once
#include "afxwin.h"


// StaffEdit 对话框

class StaffEdit : public CDialogEx
{
	DECLARE_DYNAMIC(StaffEdit)

public:
	StaffEdit(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~StaffEdit();

// 对话框数据
	enum { IDD = IDD_StaffEdit };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();
		ComboBox_StaffEditSex.AddString(TEXT("m"));
		ComboBox_StaffEditSex.AddString(TEXT("f"));
		ComboBox_StaffEditSex.SetCurSel(1);
		return true;
	}
	afx_msg void OnBnClickedStaffedit();
	CEdit Edit_StaffEditName;
	CEdit Edit_StaffEditAge;
	CEdit Edit_StaffEditNumber;
	CComboBox ComboBox_StaffEditSex;
	CEdit Edit_StaffEditUserName;
	CEdit Edit_StaffEditPassword;
};

#pragma once
#include "afxwin.h"


// StaffAdd �Ի���

class StaffAdd : public CDialogEx
{
	DECLARE_DYNAMIC(StaffAdd)

public:
	StaffAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~StaffAdd();

// �Ի�������
	enum { IDD = IDD_StaffAdd };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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

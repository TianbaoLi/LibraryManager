#pragma once
#include "afxwin.h"


// Login 对话框

class Login : public CDialogEx
{
	DECLARE_DYNAMIC(Login)

public:
	Login(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Login();

// 对话框数据
	enum { IDD = IDD_Login };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	CComboBox ComboBox_LoginSex;
	BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();
		ComboBox_LoginClassify.AddString(TEXT("工作人员"));
		ComboBox_LoginClassify.AddString(TEXT("管理员"));
		ComboBox_LoginClassify.SetCurSel(0);
		return true;
	}
	CEdit Edit_LoginUserName;
	CEdit Edit_LoginPassword;
	afx_msg void OnBnClickedLogin();
	CComboBox ComboBox_LoginClassify;
	afx_msg void OnBnClickedCancel();
};

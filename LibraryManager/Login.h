#pragma once
#include "afxwin.h"


// Login �Ի���

class Login : public CDialogEx
{
	DECLARE_DYNAMIC(Login)

public:
	Login(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Login();

// �Ի�������
	enum { IDD = IDD_Login };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	CComboBox ComboBox_LoginSex;
	BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();
		ComboBox_LoginClassify.AddString(TEXT("������Ա"));
		ComboBox_LoginClassify.AddString(TEXT("����Ա"));
		ComboBox_LoginClassify.SetCurSel(0);
		return true;
	}
	CEdit Edit_LoginUserName;
	CEdit Edit_LoginPassword;
	afx_msg void OnBnClickedLogin();
	CComboBox ComboBox_LoginClassify;
	afx_msg void OnBnClickedCancel();
};

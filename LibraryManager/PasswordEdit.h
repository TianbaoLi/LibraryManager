#pragma once
#include "afxwin.h"


// StaffEdit �Ի���

class PasswordEdit : public CDialogEx
{
	DECLARE_DYNAMIC(PasswordEdit)

public:
	PasswordEdit(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PasswordEdit();

// �Ի�������
	enum { IDD = IDD_PasswordEdit };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStaffedit();
	CEdit Edit_StaffEditPassword;
	CEdit Edit_StaffEditPasswordCorrect;
};

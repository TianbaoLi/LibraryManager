#pragma once
#include "afxwin.h"


// StaffEdit 对话框

class PasswordEdit : public CDialogEx
{
	DECLARE_DYNAMIC(PasswordEdit)

public:
	PasswordEdit(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PasswordEdit();

// 对话框数据
	enum { IDD = IDD_PasswordEdit };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStaffedit();
	CEdit Edit_StaffEditPassword;
	CEdit Edit_StaffEditPasswordCorrect;
};

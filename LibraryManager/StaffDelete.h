#pragma once
#include "afxwin.h"


// StaffDelete 对话框

class StaffDelete : public CDialogEx
{
	DECLARE_DYNAMIC(StaffDelete)

public:
	StaffDelete(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~StaffDelete();

// 对话框数据
	enum { IDD = IDD_StaffDelete };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStaffdelete();
	CEdit Edit_StaffDeleteName;
};

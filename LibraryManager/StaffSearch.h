#pragma once
#include "afxwin.h"


// StaffSearch 对话框

class StaffSearch : public CDialogEx
{
	DECLARE_DYNAMIC(StaffSearch)

public:
	StaffSearch(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~StaffSearch();

// 对话框数据
	enum { IDD = IDD_StaffSearch };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStaffsearch();
	CEdit Edit_StaffSearchName;
};

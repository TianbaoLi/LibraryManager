#pragma once
#include "afxwin.h"


// BookAdd 对话框

class BookAdd : public CDialogEx
{
	DECLARE_DYNAMIC(BookAdd)

public:
	BookAdd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BookAdd();

// 对话框数据
	enum { IDD = IDD_BookAdd };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit Edit_BookAddName;
	CEdit Edit_BookAddNumber;
	CEdit Edit_BookAddAmount;
	CEdit Edit_BookAddYear;
	CEdit Edit_BookAddMonth;
	CEdit Edit_BookAddDay;
	afx_msg void OnBnClickedBookadd();
};

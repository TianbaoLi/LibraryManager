#pragma once
#include "afxwin.h"


// BookLend 对话框

class BookLend : public CDialogEx
{
	DECLARE_DYNAMIC(BookLend)

public:
	BookLend(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BookLend();

// 对话框数据
	enum { IDD = IDD_BookLend };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBooklend();
	CEdit Edit_BookLendBookName;
	CEdit Edit_BookLendUserName;
};

#pragma once
#include "afxwin.h"


// BookReturn 对话框

class BookReturn : public CDialogEx
{
	DECLARE_DYNAMIC(BookReturn)

public:
	BookReturn(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BookReturn();

// 对话框数据
	enum { IDD = IDD_BookReturn };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBookreturn();
	CEdit Edit_BookReturnUserName;
	CEdit Edit_BookReturnBookName;
};

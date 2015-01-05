#pragma once
#include "afxwin.h"


// BookSearch 对话框

class BookSearch : public CDialogEx
{
	DECLARE_DYNAMIC(BookSearch)

public:
	BookSearch(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BookSearch();

// 对话框数据
	enum { IDD = IDD_BookSearch };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit Edit_BookSearchName;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedBooksearch();
};

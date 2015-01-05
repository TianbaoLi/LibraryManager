#pragma once
#include "afxwin.h"


// BookDelete 对话框

class BookDelete : public CDialogEx
{
	DECLARE_DYNAMIC(BookDelete)

public:
	BookDelete(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BookDelete();

// 对话框数据
	enum { IDD = IDD_BookDelete };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedBookdelete();
	CEdit Edit_BookDeleteBookName;
	afx_msg void OnBnClickedBookdelete();
};

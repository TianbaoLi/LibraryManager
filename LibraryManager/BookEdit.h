#pragma once
#include "afxwin.h"


// BookEdit 对话框

class BookEdit : public CDialogEx
{
	DECLARE_DYNAMIC(BookEdit)

public:
	BookEdit(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BookEdit();

// 对话框数据
	enum { IDD = IDD_Bookedit };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBookedit();
	CEdit Edit_BookEditName;
	CEdit Edit_BookEditNumber;
	CEdit Edit_BookEditAmount;
	CEdit Edit_BookEditYear;
	CEdit Edit_BookEditDay;
	CEdit Edit_BookEditMonth;
};

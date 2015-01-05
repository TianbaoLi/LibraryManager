#pragma once
#include "afxwin.h"


// StudentSearch 对话框

class StudentSearch : public CDialogEx
{
	DECLARE_DYNAMIC(StudentSearch)

public:
	StudentSearch(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~StudentSearch();

// 对话框数据
	enum { IDD = IDD_StudentSearch };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStudentsearch();
	CEdit Edit_StudentSearchName;
	CEdit Edit_StudentSearchNumber;
};

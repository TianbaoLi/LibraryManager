#pragma once
#include "afxwin.h"


// StudentDelete 对话框

class StudentDelete : public CDialogEx
{
	DECLARE_DYNAMIC(StudentDelete)

public:
	StudentDelete(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~StudentDelete();

// 对话框数据
	enum { IDD = IDD_StudentDelete };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStudentdelete();
	CEdit Edit_StudentDeleteName;
	CEdit Edit_StudentDeleteNumber;
};

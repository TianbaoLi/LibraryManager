#pragma once
#include "afxwin.h"


// StudentSort 对话框

class StudentSort : public CDialogEx
{
	DECLARE_DYNAMIC(StudentSort)

public:
	StudentSort(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~StudentSort();

// 对话框数据
	enum { IDD = IDD_StudentSort };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();
		ComboBox_StudentSortCmp.AddString(TEXT("按姓名排序"));
		ComboBox_StudentSortCmp.AddString(TEXT("按年龄排序"));
		ComboBox_StudentSortCmp.SetCurSel(0);
		return true;
	}
	afx_msg void OnBnClickedStudentsort();
	CComboBox ComboBox_StudentSortCmp;
};

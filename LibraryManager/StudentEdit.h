#pragma once
#include "afxwin.h"


// StudentEdit 对话框

class StudentEdit : public CDialogEx
{
	DECLARE_DYNAMIC(StudentEdit)

public:
	StudentEdit(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~StudentEdit();

// 对话框数据
	enum { IDD = IDD_StudentEdit };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();
		ComboBox_StudentEditSex.AddString(TEXT("m"));
		ComboBox_StudentEditSex.AddString(TEXT("f"));
		ComboBox_StudentEditSex.SetCurSel(1);
		return true;
	}
	afx_msg void OnBnClickedStudentedit();
	CEdit Edit_StudentEditName;
	CEdit Edit_StudentEditAge;
	CEdit Edit_StudentEditNumber;
	CComboBox ComboBox_StudentEditSex;
};

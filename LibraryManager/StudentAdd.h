#pragma once
#include "afxwin.h"


// StudentAdd �Ի���

class StudentAdd : public CDialogEx
{
	DECLARE_DYNAMIC(StudentAdd)

public:
	StudentAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~StudentAdd();

// �Ի�������
	enum { IDD = IDD_StudentAdd };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();
		ComboBox_StudentAddSex.AddString(TEXT("m"));
		ComboBox_StudentAddSex.AddString(TEXT("f"));
		ComboBox_StudentAddSex.SetCurSel(1);
		return true;
	}
	CEdit Edit_StudentAddName;
	CEdit Edit_StudentAddAge;
	CEdit Edit_StudentAddNumber;
	CComboBox ComboBox_StudentAddSex;
	afx_msg void OnBnClickedStudentadd();
};

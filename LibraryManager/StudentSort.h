#pragma once
#include "afxwin.h"


// StudentSort �Ի���

class StudentSort : public CDialogEx
{
	DECLARE_DYNAMIC(StudentSort)

public:
	StudentSort(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~StudentSort();

// �Ի�������
	enum { IDD = IDD_StudentSort };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();
		ComboBox_StudentSortCmp.AddString(TEXT("����������"));
		ComboBox_StudentSortCmp.AddString(TEXT("����������"));
		ComboBox_StudentSortCmp.SetCurSel(0);
		return true;
	}
	afx_msg void OnBnClickedStudentsort();
	CComboBox ComboBox_StudentSortCmp;
};

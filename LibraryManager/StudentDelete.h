#pragma once
#include "afxwin.h"


// StudentDelete �Ի���

class StudentDelete : public CDialogEx
{
	DECLARE_DYNAMIC(StudentDelete)

public:
	StudentDelete(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~StudentDelete();

// �Ի�������
	enum { IDD = IDD_StudentDelete };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStudentdelete();
	CEdit Edit_StudentDeleteName;
	CEdit Edit_StudentDeleteNumber;
};

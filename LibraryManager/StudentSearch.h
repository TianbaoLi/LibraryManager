#pragma once
#include "afxwin.h"


// StudentSearch �Ի���

class StudentSearch : public CDialogEx
{
	DECLARE_DYNAMIC(StudentSearch)

public:
	StudentSearch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~StudentSearch();

// �Ի�������
	enum { IDD = IDD_StudentSearch };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStudentsearch();
	CEdit Edit_StudentSearchName;
	CEdit Edit_StudentSearchNumber;
};

#pragma once
#include "afxwin.h"


// BookAdd �Ի���

class BookAdd : public CDialogEx
{
	DECLARE_DYNAMIC(BookAdd)

public:
	BookAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~BookAdd();

// �Ի�������
	enum { IDD = IDD_BookAdd };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit Edit_BookAddName;
	CEdit Edit_BookAddNumber;
	CEdit Edit_BookAddAmount;
	CEdit Edit_BookAddYear;
	CEdit Edit_BookAddMonth;
	CEdit Edit_BookAddDay;
	afx_msg void OnBnClickedBookadd();
};

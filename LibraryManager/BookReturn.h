#pragma once
#include "afxwin.h"


// BookReturn �Ի���

class BookReturn : public CDialogEx
{
	DECLARE_DYNAMIC(BookReturn)

public:
	BookReturn(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~BookReturn();

// �Ի�������
	enum { IDD = IDD_BookReturn };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBookreturn();
	CEdit Edit_BookReturnUserName;
	CEdit Edit_BookReturnBookName;
};

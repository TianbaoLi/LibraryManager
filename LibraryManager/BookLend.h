#pragma once
#include "afxwin.h"


// BookLend �Ի���

class BookLend : public CDialogEx
{
	DECLARE_DYNAMIC(BookLend)

public:
	BookLend(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~BookLend();

// �Ի�������
	enum { IDD = IDD_BookLend };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBooklend();
	CEdit Edit_BookLendBookName;
	CEdit Edit_BookLendUserName;
};

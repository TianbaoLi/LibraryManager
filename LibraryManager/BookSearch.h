#pragma once
#include "afxwin.h"


// BookSearch �Ի���

class BookSearch : public CDialogEx
{
	DECLARE_DYNAMIC(BookSearch)

public:
	BookSearch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~BookSearch();

// �Ի�������
	enum { IDD = IDD_BookSearch };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit Edit_BookSearchName;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedBooksearch();
};

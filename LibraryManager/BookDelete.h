#pragma once
#include "afxwin.h"


// BookDelete �Ի���

class BookDelete : public CDialogEx
{
	DECLARE_DYNAMIC(BookDelete)

public:
	BookDelete(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~BookDelete();

// �Ի�������
	enum { IDD = IDD_BookDelete };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedBookdelete();
	CEdit Edit_BookDeleteBookName;
	afx_msg void OnBnClickedBookdelete();
};

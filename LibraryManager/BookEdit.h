#pragma once
#include "afxwin.h"


// BookEdit �Ի���

class BookEdit : public CDialogEx
{
	DECLARE_DYNAMIC(BookEdit)

public:
	BookEdit(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~BookEdit();

// �Ի�������
	enum { IDD = IDD_Bookedit };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBookedit();
	CEdit Edit_BookEditName;
	CEdit Edit_BookEditNumber;
	CEdit Edit_BookEditAmount;
	CEdit Edit_BookEditYear;
	CEdit Edit_BookEditDay;
	CEdit Edit_BookEditMonth;
};

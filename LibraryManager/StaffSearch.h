#pragma once
#include "afxwin.h"


// StaffSearch �Ի���

class StaffSearch : public CDialogEx
{
	DECLARE_DYNAMIC(StaffSearch)

public:
	StaffSearch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~StaffSearch();

// �Ի�������
	enum { IDD = IDD_StaffSearch };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStaffsearch();
	CEdit Edit_StaffSearchName;
};

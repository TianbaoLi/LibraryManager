#pragma once
#include "afxwin.h"


// StaffDelete �Ի���

class StaffDelete : public CDialogEx
{
	DECLARE_DYNAMIC(StaffDelete)

public:
	StaffDelete(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~StaffDelete();

// �Ի�������
	enum { IDD = IDD_StaffDelete };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStaffdelete();
	CEdit Edit_StaffDeleteName;
};

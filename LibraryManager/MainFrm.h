
// MainFrm.h : CMainFrame 类的接口
//

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;


// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnAdminlogin();
	afx_msg void OnLibraryrule();
	afx_msg void OnExit();
	afx_msg void OnExitlogin();
	afx_msg void OnPasswordEdit();
	afx_msg void OnLend();
	afx_msg void OnReturn();
	afx_msg void OnBooksearch();
	afx_msg void OnBooksearchbyname();
	afx_msg void OnBookadd();
	afx_msg void OnBookedit();
	afx_msg void OnBookdelete();
	afx_msg void OnStudentadd();
	afx_msg void OnStudentsearch();
	afx_msg void OnStudentdelete();
	afx_msg void OnStudentshow();
	afx_msg void OnStudentedit();
	afx_msg void OnStudentsort();
	afx_msg void OnStaffadd();
	afx_msg void OnStaffsearch();
	afx_msg void OnStaffdelete();
	afx_msg void OnStaffshow();
	afx_msg void OnStaffedit();
	afx_msg void OnBackup();
	afx_msg void OnRecovery();
	afx_msg void OnGuide();
	afx_msg void OnBookshow();
};



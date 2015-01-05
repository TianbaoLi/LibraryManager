
// LibraryManagerView.h : CLibraryManagerView 类的接口
//

#pragma once


class CLibraryManagerView : public CView
{
protected: // 仅从序列化创建
	CLibraryManagerView();
	DECLARE_DYNCREATE(CLibraryManagerView)
	CBitmap *m_bitmap;

// 特性
public:
	CLibraryManagerDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CLibraryManagerView();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
	afx_msg BOOL OnEraseBkgnd(CDC *pDC);
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // LibraryManagerView.cpp 中的调试版本
inline CLibraryManagerDoc* CLibraryManagerView::GetDocument() const
   { return reinterpret_cast<CLibraryManagerDoc*>(m_pDocument); }
#endif


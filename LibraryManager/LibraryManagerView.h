
// LibraryManagerView.h : CLibraryManagerView ��Ľӿ�
//

#pragma once


class CLibraryManagerView : public CView
{
protected: // �������л�����
	CLibraryManagerView();
	DECLARE_DYNCREATE(CLibraryManagerView)
	CBitmap *m_bitmap;

// ����
public:
	CLibraryManagerDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CLibraryManagerView();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
	afx_msg BOOL OnEraseBkgnd(CDC *pDC);
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // LibraryManagerView.cpp �еĵ��԰汾
inline CLibraryManagerDoc* CLibraryManagerView::GetDocument() const
   { return reinterpret_cast<CLibraryManagerDoc*>(m_pDocument); }
#endif


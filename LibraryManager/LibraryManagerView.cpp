
// LibraryManagerView.cpp : CLibraryManagerView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "LibraryManager.h"
#endif

#include "LibraryManagerDoc.h"
#include "LibraryManagerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLibraryManagerView

IMPLEMENT_DYNCREATE(CLibraryManagerView, CView)

BEGIN_MESSAGE_MAP(CLibraryManagerView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CLibraryManagerView ����/����

CLibraryManagerView::CLibraryManagerView()
{
	// TODO: �ڴ˴���ӹ������
}

CLibraryManagerView::~CLibraryManagerView()
{
}

BOOL CLibraryManagerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CLibraryManagerView ����

void CLibraryManagerView::OnDraw(CDC* pDC)
{
	CLibraryManagerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	OnEraseBkgnd(pDC);
}

BOOL CLibraryManagerView::OnEraseBkgnd(CDC* pDC) 
{
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	BITMAP bmp;
	bitmap.GetBitmap(&bmp);
	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);
	dcCompatible.SelectObject(&bitmap);
	CRect rect;
	GetClientRect(&rect);
	pDC->SetStretchBltMode(HALFTONE);
	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&dcCompatible,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
	return TRUE;
}


// CLibraryManagerView ��ӡ

BOOL CLibraryManagerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CLibraryManagerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CLibraryManagerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CLibraryManagerView ���

#ifdef _DEBUG
void CLibraryManagerView::AssertValid() const
{
	CView::AssertValid();
}

void CLibraryManagerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLibraryManagerDoc* CLibraryManagerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLibraryManagerDoc)));
	return (CLibraryManagerDoc*)m_pDocument;
}

#endif //_DEBUG


// CLibraryManagerView ��Ϣ�������

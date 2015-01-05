
// LibraryManagerView.cpp : CLibraryManagerView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CLibraryManagerView 构造/析构

CLibraryManagerView::CLibraryManagerView()
{
	// TODO: 在此处添加构造代码
}

CLibraryManagerView::~CLibraryManagerView()
{
}

BOOL CLibraryManagerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CLibraryManagerView 绘制

void CLibraryManagerView::OnDraw(CDC* pDC)
{
	CLibraryManagerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
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


// CLibraryManagerView 打印

BOOL CLibraryManagerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CLibraryManagerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CLibraryManagerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CLibraryManagerView 诊断

#ifdef _DEBUG
void CLibraryManagerView::AssertValid() const
{
	CView::AssertValid();
}

void CLibraryManagerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLibraryManagerDoc* CLibraryManagerView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLibraryManagerDoc)));
	return (CLibraryManagerDoc*)m_pDocument;
}

#endif //_DEBUG


// CLibraryManagerView 消息处理程序

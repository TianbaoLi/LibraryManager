// BookSearch.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "BookSearch.h"
#include "afxdialogex.h"
#include "BookManager.h"

// BookSearch 对话框

IMPLEMENT_DYNAMIC(BookSearch, CDialogEx)

BookSearch::BookSearch(CWnd* pParent /*=NULL*/)
	: CDialogEx(BookSearch::IDD, pParent)
{

}

BookSearch::~BookSearch()
{
}

void BookSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BookSearch, Edit_BookSearchName);
}


BEGIN_MESSAGE_MAP(BookSearch, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &BookSearch::OnBnClickedCancel)
	ON_BN_CLICKED(ID_BookSearch, &BookSearch::OnBnClickedBooksearch)
END_MESSAGE_MAP()


// BookSearch 消息处理程序


void BookSearch::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void BookSearch::OnBnClickedBooksearch()
{
	// TODO: 在此添加控件通知处理程序代码
	CString name;
	Edit_BookSearchName.GetWindowTextW(name);
	if(name==TEXT(""))
		MessageBox(TEXT("请输入书名"),TEXT("错误"));
	else
	{
		BookManager bookmaneger;
		Book book=bookmaneger.SearchBook(name);
		if(book.getName()!="")
		{
			bookmaneger.ShowBook(book);
			BookSearch::OnCancel();
		}
		else MessageBox(TEXT("未找到图书"),TEXT("错误"));
	}
}

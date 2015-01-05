// BookLend.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "BookLend.h"
#include "afxdialogex.h"
#include "BookManager.h"
#include "StudentManager.h"

// BookLend 对话框

IMPLEMENT_DYNAMIC(BookLend, CDialogEx)

BookLend::BookLend(CWnd* pParent /*=NULL*/)
	: CDialogEx(BookLend::IDD, pParent)
{

}

BookLend::~BookLend()
{
}

void BookLend::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT6, Edit_BookLendBookName);
	DDX_Control(pDX, IDC_EDIT1, Edit_BookLendUserName);
}


BEGIN_MESSAGE_MAP(BookLend, CDialogEx)
	ON_BN_CLICKED(IDBookLend, &BookLend::OnBnClickedBooklend)
END_MESSAGE_MAP()


// BookLend 消息处理程序


void BookLend::OnBnClickedBooklend()
{
	// TODO: 在此添加控件通知处理程序代码
	CString studentname,bookname;
	Edit_BookLendUserName.GetWindowTextW(studentname);
	Edit_BookLendBookName.GetWindowTextW(bookname);
	BookManager bookmanager;
	StudentManager studentmanager;
	if(studentname==TEXT(""))
		MessageBox(TEXT("请输入学生名"),TEXT("错误"));
	else if(bookname==TEXT(""))
		MessageBox(TEXT("请输入书名"),TEXT("错误"));
	else
	{
		bookmanager.Lend(bookmanager.SearchBook(bookname),studentmanager.SearchStudent(studentname));
		MessageBox(TEXT("成功借出"),TEXT("成功"));
		bookmanager.UpdateBookList();
		BookLend::OnCancel();
	}
}

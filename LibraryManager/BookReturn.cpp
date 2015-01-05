// BookReturn.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "BookReturn.h"
#include "afxdialogex.h"
#include "BookManager.h"
#include "StudentManager.h"


// BookReturn 对话框

IMPLEMENT_DYNAMIC(BookReturn, CDialogEx)

BookReturn::BookReturn(CWnd* pParent /*=NULL*/)
	: CDialogEx(BookReturn::IDD, pParent)
{

}

BookReturn::~BookReturn()
{
}

void BookReturn::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT10, Edit_BookReturnUserName);
	DDX_Control(pDX, IDC_EDIT11, Edit_BookReturnBookName);
}


BEGIN_MESSAGE_MAP(BookReturn, CDialogEx)
	ON_BN_CLICKED(IDBookReturn, &BookReturn::OnBnClickedBookreturn)
END_MESSAGE_MAP()


// BookReturn 消息处理程序


void BookReturn::OnBnClickedBookreturn()
{
	// TODO: 在此添加控件通知处理程序代码
	CString studentname,bookname;
	Edit_BookReturnUserName.GetWindowTextW(studentname);
	Edit_BookReturnBookName.GetWindowTextW(bookname);
	BookManager bookmanager;
	StudentManager studentmanager;
	if(studentname==TEXT(""))
		MessageBox(TEXT("请输入学生名"),TEXT("错误"));
	else if(bookname==TEXT(""))
		MessageBox(TEXT("请输入书名"),TEXT("错误"));
	else
	{
		bookmanager.Return(bookmanager.SearchBook(bookname),studentmanager.SearchStudent(studentname));
		MessageBox(TEXT("成功归还"),TEXT("成功"));
		bookmanager.UpdateBookList();
		BookReturn::OnCancel();
	}
}


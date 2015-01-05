// BookDelete.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "BookDelete.h"
#include "afxdialogex.h"
#include "BookManager.h"


// BookDelete 对话框

IMPLEMENT_DYNAMIC(BookDelete, CDialogEx)

BookDelete::BookDelete(CWnd* pParent /*=NULL*/)
	: CDialogEx(BookDelete::IDD, pParent)
{

}

BookDelete::~BookDelete()
{
}

void BookDelete::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT11, Edit_BookDeleteBookName);
}


BEGIN_MESSAGE_MAP(BookDelete, CDialogEx)
	ON_BN_CLICKED(IDBookDelete, &BookDelete::OnBnClickedBookdelete)
	ON_BN_CLICKED(IDBookDelete, &BookDelete::OnBnClickedBookdelete)
END_MESSAGE_MAP()


// BookDelete 消息处理程序


void BookDelete::OnBnClickedBookdelete()
{
	// TODO: 在此添加控件通知处理程序代码
	CString bookname;
	Edit_BookDeleteBookName.GetWindowTextW(bookname);
	BookManager bookmanager;
	if(bookname==TEXT(""))
		MessageBox(TEXT("请输入书名"),TEXT("错误"));
	else
	{
		if(bookmanager.DeleteBook(bookname)==1)
		{
			MessageBox(TEXT("成功删除"),TEXT("成功"));
			bookmanager.UpdateBookList();
			BookDelete::OnCancel();
		}
		else
			MessageBox(TEXT("删除失败，未找到图书"),TEXT("失败"));
	}
}

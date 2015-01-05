// BookSearch.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "BookSearch.h"
#include "afxdialogex.h"
#include "BookManager.h"

// BookSearch �Ի���

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


// BookSearch ��Ϣ�������


void BookSearch::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void BookSearch::OnBnClickedBooksearch()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString name;
	Edit_BookSearchName.GetWindowTextW(name);
	if(name==TEXT(""))
		MessageBox(TEXT("����������"),TEXT("����"));
	else
	{
		BookManager bookmaneger;
		Book book=bookmaneger.SearchBook(name);
		if(book.getName()!="")
		{
			bookmaneger.ShowBook(book);
			BookSearch::OnCancel();
		}
		else MessageBox(TEXT("δ�ҵ�ͼ��"),TEXT("����"));
	}
}

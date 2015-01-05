// BookLend.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "BookLend.h"
#include "afxdialogex.h"
#include "BookManager.h"
#include "StudentManager.h"

// BookLend �Ի���

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


// BookLend ��Ϣ�������


void BookLend::OnBnClickedBooklend()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString studentname,bookname;
	Edit_BookLendUserName.GetWindowTextW(studentname);
	Edit_BookLendBookName.GetWindowTextW(bookname);
	BookManager bookmanager;
	StudentManager studentmanager;
	if(studentname==TEXT(""))
		MessageBox(TEXT("������ѧ����"),TEXT("����"));
	else if(bookname==TEXT(""))
		MessageBox(TEXT("����������"),TEXT("����"));
	else
	{
		bookmanager.Lend(bookmanager.SearchBook(bookname),studentmanager.SearchStudent(studentname));
		MessageBox(TEXT("�ɹ����"),TEXT("�ɹ�"));
		bookmanager.UpdateBookList();
		BookLend::OnCancel();
	}
}

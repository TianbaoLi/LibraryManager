// BookReturn.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "BookReturn.h"
#include "afxdialogex.h"
#include "BookManager.h"
#include "StudentManager.h"


// BookReturn �Ի���

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


// BookReturn ��Ϣ�������


void BookReturn::OnBnClickedBookreturn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString studentname,bookname;
	Edit_BookReturnUserName.GetWindowTextW(studentname);
	Edit_BookReturnBookName.GetWindowTextW(bookname);
	BookManager bookmanager;
	StudentManager studentmanager;
	if(studentname==TEXT(""))
		MessageBox(TEXT("������ѧ����"),TEXT("����"));
	else if(bookname==TEXT(""))
		MessageBox(TEXT("����������"),TEXT("����"));
	else
	{
		bookmanager.Return(bookmanager.SearchBook(bookname),studentmanager.SearchStudent(studentname));
		MessageBox(TEXT("�ɹ��黹"),TEXT("�ɹ�"));
		bookmanager.UpdateBookList();
		BookReturn::OnCancel();
	}
}


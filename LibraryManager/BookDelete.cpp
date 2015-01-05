// BookDelete.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "BookDelete.h"
#include "afxdialogex.h"
#include "BookManager.h"


// BookDelete �Ի���

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


// BookDelete ��Ϣ�������


void BookDelete::OnBnClickedBookdelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString bookname;
	Edit_BookDeleteBookName.GetWindowTextW(bookname);
	BookManager bookmanager;
	if(bookname==TEXT(""))
		MessageBox(TEXT("����������"),TEXT("����"));
	else
	{
		if(bookmanager.DeleteBook(bookname)==1)
		{
			MessageBox(TEXT("�ɹ�ɾ��"),TEXT("�ɹ�"));
			bookmanager.UpdateBookList();
			BookDelete::OnCancel();
		}
		else
			MessageBox(TEXT("ɾ��ʧ�ܣ�δ�ҵ�ͼ��"),TEXT("ʧ��"));
	}
}

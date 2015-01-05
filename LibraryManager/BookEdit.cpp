// BookEdit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "BookEdit.h"
#include "afxdialogex.h"
#include "BookManager.h"


// BookEdit �Ի���

IMPLEMENT_DYNAMIC(BookEdit, CDialogEx)

BookEdit::BookEdit(CWnd* pParent /*=NULL*/)
	: CDialogEx(BookEdit::IDD, pParent)
{

}

BookEdit::~BookEdit()
{
}

void BookEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, Edit_BookEditName);
	DDX_Control(pDX, IDC_EDIT3, Edit_BookEditNumber);
	DDX_Control(pDX, IDC_EDIT4, Edit_BookEditAmount);
	DDX_Control(pDX, IDC_EDIT7, Edit_BookEditYear);
	DDX_Control(pDX, IDC_EDIT9, Edit_BookEditDay);
	DDX_Control(pDX, IDC_EDIT8, Edit_BookEditMonth);
}


BEGIN_MESSAGE_MAP(BookEdit, CDialogEx)
	ON_BN_CLICKED(IDBookEdit, &BookEdit::OnBnClickedBookedit)
END_MESSAGE_MAP()


// BookEdit ��Ϣ�������


void BookEdit::OnBnClickedBookedit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString bookname,temp;
	int number,amount,year,month,day;
	Edit_BookEditName.GetWindowTextW(bookname);
	if(bookname==TEXT(""))
		MessageBox(TEXT("����������"),TEXT("����"));
	else
	{
		Edit_BookEditNumber.GetWindowTextW(temp);
		if(temp==TEXT(""))
			MessageBox(TEXT("���������"),TEXT("����"));
		else
		{
			number=StrToInt(temp);
			Edit_BookEditAmount.GetWindowTextW(temp);
			if(temp==TEXT(""))
				MessageBox(TEXT("����������"),TEXT("����"));
			else
			{
				amount=StrToInt(temp);
				Edit_BookEditYear.GetWindowTextW(temp);
				if(temp==TEXT(""))
					MessageBox(TEXT("��������"),TEXT("����"));
				else
				{
					year=StrToInt(temp);
					Edit_BookEditMonth.GetWindowTextW(temp);
					if(temp==TEXT(""))
						MessageBox(TEXT("��������"),TEXT("����"));
					else
					{
						month=StrToInt(temp);
						Edit_BookEditDay.GetWindowTextW(temp);
						if(temp==TEXT(""))
							MessageBox(TEXT("��������"),TEXT("����"));
						else
						{
							day=StrToInt(temp);
							BookManager bookmanager;
							Book book=Book(bookname,number,amount,year,month,day,0);
							if(bookmanager.EditBook(book)==1)
								MessageBox(TEXT("�ɹ��޸�"),TEXT("�ɹ�"));
							else 
								MessageBox(TEXT("�޸�ʧ�ܣ�δ�ҵ�ͼ��"),TEXT("ʧ��"));
							BookEdit::OnCancel();
						}
					}
				}
			}
		}
	}
}

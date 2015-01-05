// BookAdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "BookAdd.h"
#include "afxdialogex.h"
#include "BookManager.h"


// BookAdd �Ի���

IMPLEMENT_DYNAMIC(BookAdd, CDialogEx)

BookAdd::BookAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(BookAdd::IDD, pParent)
{

}

BookAdd::~BookAdd()
{
}

void BookAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, Edit_BookAddName);
	DDX_Control(pDX, IDC_EDIT3, Edit_BookAddNumber);
	DDX_Control(pDX, IDC_EDIT4, Edit_BookAddAmount);
	DDX_Control(pDX, IDC_EDIT7, Edit_BookAddYear);
	DDX_Control(pDX, IDC_EDIT8, Edit_BookAddMonth);
	DDX_Control(pDX, IDC_EDIT9, Edit_BookAddDay);
}


BEGIN_MESSAGE_MAP(BookAdd, CDialogEx)
	ON_BN_CLICKED(IDBookAdd, &BookAdd::OnBnClickedBookadd)
END_MESSAGE_MAP()


// BookAdd ��Ϣ�������


void BookAdd::OnBnClickedBookadd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString bookname,temp;
	int number,amount,year,month,day;
	Edit_BookAddName.GetWindowTextW(bookname);
	if(bookname==TEXT(""))
		MessageBox(TEXT("����������"),TEXT("����"));
	else
	{
		Edit_BookAddNumber.GetWindowTextW(temp);
		if(temp==TEXT(""))
			MessageBox(TEXT("���������"),TEXT("����"));
		else
		{
			number=StrToInt(temp);
			Edit_BookAddAmount.GetWindowTextW(temp);
			if(temp==TEXT(""))
				MessageBox(TEXT("����������"),TEXT("����"));
			else
			{
				amount=StrToInt(temp);
				Edit_BookAddYear.GetWindowTextW(temp);
				if(temp==TEXT(""))
					MessageBox(TEXT("��������"),TEXT("����"));
				else
				{
					year=StrToInt(temp);
					Edit_BookAddMonth.GetWindowTextW(temp);
					if(temp==TEXT(""))
						MessageBox(TEXT("��������"),TEXT("����"));
					else
					{
						month=StrToInt(temp);
						Edit_BookAddDay.GetWindowTextW(temp);
						if(temp==TEXT(""))
							MessageBox(TEXT("��������"),TEXT("����"));
						else
						{
							day=StrToInt(temp);
							BookManager bookmanager;
							Book book=Book(bookname,number,amount,year,month,day,0);
							bookmanager.AddBook(book);
							MessageBox(TEXT("�ɹ����"),TEXT("�ɹ�"));
							BookAdd::OnCancel();
						}
					}
				}
			}
		}
	}
}

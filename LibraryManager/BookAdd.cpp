// BookAdd.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "BookAdd.h"
#include "afxdialogex.h"
#include "BookManager.h"


// BookAdd 对话框

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


// BookAdd 消息处理程序


void BookAdd::OnBnClickedBookadd()
{
	// TODO: 在此添加控件通知处理程序代码
	CString bookname,temp;
	int number,amount,year,month,day;
	Edit_BookAddName.GetWindowTextW(bookname);
	if(bookname==TEXT(""))
		MessageBox(TEXT("请输入书名"),TEXT("错误"));
	else
	{
		Edit_BookAddNumber.GetWindowTextW(temp);
		if(temp==TEXT(""))
			MessageBox(TEXT("请输入书号"),TEXT("错误"));
		else
		{
			number=StrToInt(temp);
			Edit_BookAddAmount.GetWindowTextW(temp);
			if(temp==TEXT(""))
				MessageBox(TEXT("请输入数量"),TEXT("错误"));
			else
			{
				amount=StrToInt(temp);
				Edit_BookAddYear.GetWindowTextW(temp);
				if(temp==TEXT(""))
					MessageBox(TEXT("请输入年"),TEXT("错误"));
				else
				{
					year=StrToInt(temp);
					Edit_BookAddMonth.GetWindowTextW(temp);
					if(temp==TEXT(""))
						MessageBox(TEXT("请输入月"),TEXT("错误"));
					else
					{
						month=StrToInt(temp);
						Edit_BookAddDay.GetWindowTextW(temp);
						if(temp==TEXT(""))
							MessageBox(TEXT("请输入日"),TEXT("错误"));
						else
						{
							day=StrToInt(temp);
							BookManager bookmanager;
							Book book=Book(bookname,number,amount,year,month,day,0);
							bookmanager.AddBook(book);
							MessageBox(TEXT("成功添加"),TEXT("成功"));
							BookAdd::OnCancel();
						}
					}
				}
			}
		}
	}
}

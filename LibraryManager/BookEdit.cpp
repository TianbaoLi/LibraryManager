// BookEdit.cpp : 实现文件
//

#include "stdafx.h"
#include "LibraryManager.h"
#include "BookEdit.h"
#include "afxdialogex.h"
#include "BookManager.h"


// BookEdit 对话框

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


// BookEdit 消息处理程序


void BookEdit::OnBnClickedBookedit()
{
	// TODO: 在此添加控件通知处理程序代码
	CString bookname,temp;
	int number,amount,year,month,day;
	Edit_BookEditName.GetWindowTextW(bookname);
	if(bookname==TEXT(""))
		MessageBox(TEXT("请输入书名"),TEXT("错误"));
	else
	{
		Edit_BookEditNumber.GetWindowTextW(temp);
		if(temp==TEXT(""))
			MessageBox(TEXT("请输入书号"),TEXT("错误"));
		else
		{
			number=StrToInt(temp);
			Edit_BookEditAmount.GetWindowTextW(temp);
			if(temp==TEXT(""))
				MessageBox(TEXT("请输入数量"),TEXT("错误"));
			else
			{
				amount=StrToInt(temp);
				Edit_BookEditYear.GetWindowTextW(temp);
				if(temp==TEXT(""))
					MessageBox(TEXT("请输入年"),TEXT("错误"));
				else
				{
					year=StrToInt(temp);
					Edit_BookEditMonth.GetWindowTextW(temp);
					if(temp==TEXT(""))
						MessageBox(TEXT("请输入月"),TEXT("错误"));
					else
					{
						month=StrToInt(temp);
						Edit_BookEditDay.GetWindowTextW(temp);
						if(temp==TEXT(""))
							MessageBox(TEXT("请输入日"),TEXT("错误"));
						else
						{
							day=StrToInt(temp);
							BookManager bookmanager;
							Book book=Book(bookname,number,amount,year,month,day,0);
							if(bookmanager.EditBook(book)==1)
								MessageBox(TEXT("成功修改"),TEXT("成功"));
							else 
								MessageBox(TEXT("修改失败，未找到图书"),TEXT("失败"));
							BookEdit::OnCancel();
						}
					}
				}
			}
		}
	}
}

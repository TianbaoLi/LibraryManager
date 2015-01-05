#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <afx.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>
#include "locale.h"
#include "Student.h"
using namespace std;

class BookManager
{
private:
	std::vector<Book> bookList;
	Book noneBook;
public:
	BookManager()
	{
		CStdioFile File;
		File.Open(TEXT("book.txt"),CFile::modeRead);
		CString aName,temp;
		int aNumber,aAmount,aYear,aMonth,aDay,aStatus;
		char* old_locale=_strdup(setlocale(LC_CTYPE,NULL));
		setlocale( LC_CTYPE,"chs");
		while(1)
		{
			if(!File.ReadString(aName))break;
			if(!File.ReadString(temp))break;
			aNumber=StrToInt(temp);
			if(!File.ReadString(temp))break;
			aAmount=StrToInt(temp);
			if(!File.ReadString(temp))break;
			aYear=StrToInt(temp);
			if(!File.ReadString(temp))break;
			aMonth=StrToInt(temp);
			if(!File.ReadString(temp))break;
			aDay=StrToInt(temp);
			if(!File.ReadString(temp))break;
			aStatus=StrToInt(temp);
			Book b=Book(aName,aNumber,aAmount,aYear,aMonth,aDay,aStatus);
			bookList.push_back(b);
		}
		setlocale(LC_CTYPE,old_locale);
		free(old_locale);
		File.Close();
	}
	void AddBook(Book aBook)
	{
		bookList.push_back(aBook);
		CStdioFile File;
		CString temp;
		CTime inDate;
		inDate=aBook.getInDate();
		File.Open(TEXT("book.txt"),CFile::modeWrite);
		char* old_locale=_strdup(setlocale(LC_CTYPE,NULL));
		setlocale( LC_CTYPE,"chs");
		File.SeekToEnd();
		File.WriteString(aBook.getName());
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%d"),aBook.getNumber());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%d"),aBook.getAmount());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%d\n%d\n%d"),inDate.GetYear(),inDate.GetMonth(),inDate.GetDay());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%d"),aBook.getStatus());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		setlocale(LC_CTYPE,old_locale);
		free(old_locale);
		File.Close();
	}
	void ShowBook()
	{
		CString string;
		for(std::vector<Book>::iterator Iter=bookList.begin();Iter!=bookList.end();Iter++)
		{
			CString temp;
			CTime inDate=Iter->getInDate();
			string+=TEXT("Name=");
			string+=Iter->getName();
			string+=TEXT(" Number=");
			temp.Format(_T("%d"),Iter->getNumber());
			string+=temp;
			string+=TEXT(" Amount=");
			temp.Format(_T("%d"),Iter->getAmount());
			string+=temp;
			string+=TEXT(" InDate=");
			temp.Format(_T("%d %d %d"),inDate.GetYear(),inDate.GetMonth(),inDate.GetDay());
			string+=temp;
			string+=TEXT(" Status=");
			if(Iter->getStatus()==0)string+=TEXT("IN");
			else string+=TEXT("OUT");
			string+="\n";
		}
		MessageBox(NULL,string,_TEXT("书籍信息"),MB_OK);
	}
	void ShowBook(Book aBook)
	{
		CString string,temp;
		CTime inDate=aBook.getInDate();
		string+=TEXT("Name=");
		string+=aBook.getName();
		string+=TEXT(" Number=");
		temp.Format(_T("%d"),aBook.getNumber());
		string+=temp;
		string+=TEXT(" Amount=");
		temp.Format(_T("%d"),aBook.getAmount());
		string+=temp;
		string+=TEXT(" InDate=");
		temp.Format(_T("%d %d %d"),inDate.GetYear(),inDate.GetMonth(),inDate.GetDay());
		string+=temp;
		string+=TEXT(" Status=");
		if(aBook.getStatus()==0)string+=TEXT("IN");
		else string+=TEXT("OUT");
		string+="\n";
		MessageBox(NULL,string,_TEXT("书籍信息"),MB_OK);
	}
	Book SearchBook(CString aName)
	{
		for(std::vector<Book>::iterator Iter=bookList.begin();Iter!=bookList.end();Iter++)
			if(Iter->getName()==aName)
				return *Iter;
		return noneBook;
	}
	Book SearchBook(int aYear,int aMonth,int aDay)
	{
		CTime aInDate;
		for(std::vector<Book>::iterator Iter=bookList.begin();Iter!=bookList.end();Iter++)
		{
			aInDate=Iter->getInDate();
			if(aInDate.GetYear()==aYear&&aInDate.GetMonth()==aMonth&&aInDate.GetDay()==aDay)
				return *Iter;
		}
		return noneBook;
	}
	bool DeleteBook(int aNumber)
	{
		bool ret=0;
		for(std::vector<Book>::iterator Iter=bookList.begin();Iter!=bookList.end();Iter++)
			if(Iter->getNumber()==aNumber)
			{
				ret=1;
				if(Iter!=bookList.end()-1)
					Iter=bookList.erase(Iter);
				else
				{
					bookList.erase(Iter);
					break;
				}
			}
		UpdateBookList();
		return ret;
	}
	bool DeleteBook(CString aName)
	{
		bool ret=0;
		for(std::vector<Book>::iterator Iter=bookList.begin();Iter!=bookList.end();Iter++)
			if(Iter->getName()==aName)
			{
				ret=1;
				if(Iter!=bookList.end()-1)
					Iter=bookList.erase(Iter);
				else
				{
					bookList.erase(Iter);
					break;
				}
			}
		UpdateBookList();
		return ret;
	}
	bool EditBook(Book aBook)
	{
		bool ret=0;
		for(std::vector<Book>::iterator Iter=bookList.begin();Iter!=bookList.end();Iter++)
			if(Iter->getName()==aBook.getName())
			{
				Iter->setNumber(aBook.getNumber());
				Iter->setAmount(aBook.getAmount());
				Iter->setInDate(aBook.getInDate());
				Iter->setStatus(aBook.getStatus());
				ret=1;
			}
		UpdateBookList();
		return ret;
	}
	void UpdateBookList()
	{
		CStdioFile File;
		CString temp;
		File.Open(TEXT("book.txt"),CFile::modeWrite|CFile::modeCreate);
		char* old_locale=_strdup(setlocale(LC_CTYPE,NULL));
		setlocale( LC_CTYPE,"chs");
		for(std::vector<Book>::iterator Iter=bookList.begin();Iter!=bookList.end();Iter++)
		{
			CTime inDate=Iter->getInDate();
			File.WriteString(Iter->getName());
			File.WriteString(TEXT("\n"));
			temp.Format(_T("%d"),Iter->getNumber());
			File.WriteString(temp);
			File.WriteString(TEXT("\n"));
			temp.Format(_T("%d"),Iter->getAmount());
			File.WriteString(temp);
			File.WriteString(TEXT("\n"));
			temp.Format(_T("%d\n%d\n%d"),inDate.GetYear(),inDate.GetMonth(),inDate.GetDay());
			File.WriteString(temp);
			File.WriteString(TEXT("\n"));
			temp.Format(_T("%d"),Iter->getStatus());
			File.WriteString(temp);
			File.WriteString(TEXT("\n"));
			
		}
		setlocale(LC_CTYPE,old_locale);
		free(old_locale);
		File.Close();
	}
	void Lend(Book aBook,Student aStudent)
	{
		for(std::vector<Book>::iterator Iter=bookList.begin();Iter!=bookList.end();Iter++)
			if(Iter->getName()==aBook.getName())
				Iter->setStatus(1);
		aStudent.AddBook(aBook);
		UpdateBookList();
	}
	void Return(Book aBook,Student aStudent)
	{
		for(std::vector<Book>::iterator Iter=bookList.begin();Iter!=bookList.end();Iter++)
			if(Iter->getName()==aBook.getName())
				Iter->setStatus(0);
		aStudent.DeleteBook(aBook);
		UpdateBookList();
	}
};

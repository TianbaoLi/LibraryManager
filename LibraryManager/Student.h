#pragma once
#include <afx.h>
#include <vector>
#include "Book.h"
#include "Person.h"
#define _CRT_SECURE_NO_WARNINGS

class Student:public Person
{
private:
	std::vector<Book> bookList;
public:
	Student(){};
	Student(CString aName,char aSex,int aAge,int aNumber):Person(aName,aSex,aAge,aNumber)
	{
		bookList.clear();
	}
	void AddBook(Book aBook)
	{
		bookList.push_back(aBook);
	}
	void DeleteBook(Book aBook)
	{
		for(std::vector<Book>::iterator Iter=bookList.begin();Iter!=bookList.end();Iter++)
			if(Iter->getName()==aBook.getName())
				Iter=bookList.erase(Iter);
	}
	void ShowMenu(){};
	void CheckUser(){};
};

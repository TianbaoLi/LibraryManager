#pragma once
#include <afx.h>
#include "Person.h"
#include "StudentManager.h"
#include "BookManager.h"

class Staff:public Person
{
protected:
	CString userName;
    CString password;
    BookManager bookManager;
    StudentManager studentManager;
public:
	Staff(){};
    Staff(CString aName,char aSex,int aAge,int aNumber,CString aUserName,CString aPassword):Person(aName,aSex,aAge,aNumber) 
    {
    	userName=aUserName;
    	password=aPassword;
		bookManager=BookManager();
		studentManager=StudentManager();
    }
	CString getUserName()
	{
		return userName;
	}
	CString getPassword()
	{
		return password;
	}
    void setUserName(CString aUsername)
    {
    	userName=aUsername;
    }
    void setPassword(CString aPassword)
    {
    	password=aPassword;
    }
	void ShowMenu()
	{
		CMenu menu;
		menu.LoadMenu(IDR_MAINFRAME1);
		AfxGetMainWnd()->SetMenu(&menu);
		menu.Detach();
	}
};

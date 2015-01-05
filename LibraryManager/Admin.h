#pragma once
#include <afx.h>
#include "Staff.h"
#include "StaffManager.h"
class Admin:public Staff 
{
private:
	StaffManager staffmanager;
public:
	Admin(CString aName,char aSex,int aAge,int aNumber,CString aUserName,CString aPassword):Staff(aName,aSex,aAge,aNumber,aUserName,aPassword)
	{
		staffmanager=StaffManager();
	}
	void ShowMenu()
	{
		CMenu menu;
		menu.LoadMenu(IDR_MAINFRAME2);
		AfxGetMainWnd()->SetMenu(&menu);
		menu.Detach();
	}
};

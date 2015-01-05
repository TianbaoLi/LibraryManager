#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <afx.h>
#include <vector>
#include <algorithm>
#include "Admin.h"

class AdminManager
{
private:
	std::vector<Admin> adminList;
public:
	AdminManager()
	{
		CStdioFile File;
		File.Open(TEXT("admin.txt"),CFile::modeRead);
		CString aName,temp,aUserName,aPassword;
		char aSex;
		int aAge,aNumber;
		char* old_locale=_strdup(setlocale(LC_CTYPE,NULL));
		setlocale( LC_CTYPE,"chs");
		while(1)
		{
			if(!File.ReadString(aName))break;
			if(!File.ReadString(temp))break;
			aSex=(char)temp[0];
			if(!File.ReadString(temp))break;
			aAge=StrToInt(temp);
			if(!File.ReadString(temp))break;
			aNumber=StrToInt(temp);
			if(!File.ReadString(aUserName))break;
			if(!File.ReadString(aPassword))break;
			Admin a=Admin(aName,aSex,aAge,aNumber,aUserName,aPassword);
			adminList.push_back(a);
		}
		setlocale(LC_CTYPE,old_locale);
		free(old_locale);
		File.Close();
	}
	void AddAdmin(Admin aAdmin)
	{
		adminList.push_back(aAdmin);
		CStdioFile File;
		CString temp;
		File.Open(TEXT("admin.txt"),CFile::modeWrite);
		char* old_locale=_strdup(setlocale(LC_CTYPE,NULL));
		setlocale( LC_CTYPE,"chs");
		File.SeekToEnd();
		File.WriteString(aAdmin.getName());
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%c"),aAdmin.getSex());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%d"),aAdmin.getAge());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%d"),aAdmin.getNumber());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		File.WriteString(aAdmin.getUserName());
		File.WriteString(TEXT("\n"));
		File.WriteString(aAdmin.getPassword());
		File.WriteString(TEXT("\n"));
		setlocale(LC_CTYPE,old_locale);
		free(old_locale);
		File.Close();
	}
	void ShowAdmin()
	{
		CString string;
		for(std::vector<Admin>::iterator Iter=adminList.begin();Iter!=adminList.end();Iter++)
		{
			CString temp;
			string+=TEXT("Name=");
			string+=Iter->getName();
			string+=TEXT(" Sex=");
			temp.Format(_T("%c"),Iter->getSex());
			string+=temp;
			string+=TEXT(" Age=");
			temp.Format(_T("%d"),Iter->getAge());
			string+=temp;
			string+=TEXT(" Number=");
			temp.Format(_T("%d"),Iter->getNumber());
			string+=temp;
			string+="\n";
		}
		MessageBox(NULL,string,_TEXT("管理员信息"),MB_OK);
	}
	Admin SearchAdmin(int aNumber)
	{
		for(std::vector<Admin>::iterator Iter=adminList.begin();Iter!=adminList.end();Iter++)
			if(Iter->getNumber()==aNumber)
				return *Iter;
	}
	Admin SearchAdmin(CString aName)
	{
		for(std::vector<Admin>::iterator Iter=adminList.begin();Iter!=adminList.end();Iter++)
			if(Iter->getName()==aName)
				return *Iter;
	}
	Admin SearchAdmin(CString aUserName,CString aPassword)
	{
		for(std::vector<Admin>::iterator Iter=adminList.begin();Iter!=adminList.end();Iter++)
			if(Iter->getUserName()==aUserName&&Iter->getPassword()==aPassword)
				return *Iter;
	}
	void DeleteAdmin(int aNumber)
	{
		for(std::vector<Admin>::iterator Iter=adminList.begin();Iter!=adminList.end();Iter++)
			if(Iter->getNumber()==aNumber)
				Iter=adminList.erase(Iter);
		UpdateAdminList();
	}
	void DeleteAdmin(CString aName)
	{
		for(std::vector<Admin>::iterator Iter=adminList.begin();Iter!=adminList.end();Iter++)
			if(Iter->getName()==aName)
				Iter=adminList.erase(Iter);
		UpdateAdminList();
	}
	void EditAdmin(Admin aAdmin)
	{
		Admin admin=SearchAdmin(aAdmin.getName());
		admin.setName(aAdmin.getName());
		admin.setSex(aAdmin.getSex());
		admin.setAge(aAdmin.getAge());
		admin.setNumber(aAdmin.getNumber());
		admin.setUserName(aAdmin.getUserName());
		admin.setPassword(aAdmin.getPassword());
		UpdateAdminList();
	}
	void UpdateAdminList()
	{
		CStdioFile File;
		CString temp;
		File.Open(TEXT("staff.txt"),CFile::modeWrite|CFile::modeCreate);
		char* old_locale=_strdup(setlocale(LC_CTYPE,NULL));
		setlocale( LC_CTYPE,"chs");
		for(std::vector<Admin>::iterator Iter=adminList.begin();Iter!=adminList.end();Iter++)
		{
			File.WriteString(Iter->getName());
			File.WriteString(TEXT("\n"));
			temp.Format(_T("%c"),Iter->getSex());
			File.WriteString(temp);
			File.WriteString(TEXT("\n"));
			temp.Format(_T("%d"),Iter->getAge());
			File.WriteString(temp);
			File.WriteString(TEXT("\n"));
			temp.Format(_T("%d"),Iter->getNumber());
			File.WriteString(Iter->getUserName());
			File.WriteString(TEXT("\n"));
			File.WriteString(Iter->getPassword());
			File.WriteString(TEXT("\n"));
			File.WriteString(temp);
			File.WriteString(TEXT("\n"));
		}
		setlocale(LC_CTYPE,old_locale);
		free(old_locale);
		File.Close();
	}
	bool CheckAdmin(Admin aAdmin)
	{
		for(std::vector<Admin>::iterator Iter=adminList.begin();Iter!=adminList.end();Iter++)
			if(Iter->getUserName()==aAdmin.getUserName()&&Iter->getPassword()==aAdmin.getPassword())
				return true;
		return false;
	}
	void setCurrentUser(Admin aAdmin)
	{
		CStdioFile File;
		CString temp;
		File.Open(TEXT("current user.txt"),CFile::modeWrite|CFile::modeCreate);
		char* old_locale=_strdup(setlocale(LC_CTYPE,NULL));
		setlocale( LC_CTYPE,"chs");
		File.WriteString(aAdmin.getName());
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%c"),aAdmin.getSex());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%d"),aAdmin.getAge());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%d"),aAdmin.getNumber());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		File.WriteString(aAdmin.getUserName());
		File.WriteString(TEXT("\n"));
		File.WriteString(aAdmin.getPassword());
		File.WriteString(TEXT("\n"));
		setlocale(LC_CTYPE,old_locale);
		free(old_locale);
		File.Close();
	}
	Admin getCurrentUser()
	{
		CStdioFile File;
		File.Open(TEXT("current user.txt"),CFile::modeRead);
		CString aName,temp,aUserName,aPassword;
		char aSex;
		int aAge,aNumber;
		char* old_locale=_strdup(setlocale(LC_CTYPE,NULL));
		setlocale( LC_CTYPE,"chs");
		File.ReadString(aName);
		File.ReadString(temp);
		aSex=(char)temp[0];
		File.ReadString(temp);
		aAge=StrToInt(temp);
		File.ReadString(temp);
		aNumber=StrToInt(temp);
		File.ReadString(aUserName);
		File.ReadString(aPassword);
		Admin admin=Admin(aName,aSex,aAge,aNumber,aUserName,aPassword);
		setlocale(LC_CTYPE,old_locale);
		free(old_locale);
		File.Close();
		return admin;
	}
};

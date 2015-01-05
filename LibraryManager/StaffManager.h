#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <afx.h>
#include <vector>
#include <algorithm>
#include "Staff.h"
#include "locale.h"

class StaffManager
{
private:
	std::vector<Staff> staffList;
	Staff noneStaff;
public:
	StaffManager()
	{
		CStdioFile File;
		File.Open(TEXT("staff.txt"),CFile::modeRead);
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
			Staff s=Staff(aName,aSex,aAge,aNumber,aUserName,aPassword);
			staffList.push_back(s);
		}
		setlocale(LC_CTYPE,old_locale);
		free(old_locale);
		File.Close();
	}
	void AddStaff(Staff aStaff)
	{
		staffList.push_back(aStaff);
		CStdioFile File;
		CString temp;
		File.Open(TEXT("staff.txt"),CFile::modeWrite);
		char* old_locale=_strdup(setlocale(LC_CTYPE,NULL));
		setlocale( LC_CTYPE,"chs");
		File.SeekToEnd();
		File.WriteString(aStaff.getName());
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%c"),aStaff.getSex());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%d"),aStaff.getAge());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%d"),aStaff.getNumber());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		File.WriteString(aStaff.getUserName());
		File.WriteString(TEXT("\n"));
		File.WriteString(aStaff.getPassword());
		File.WriteString(TEXT("\n"));
		setlocale(LC_CTYPE,old_locale);
		free(old_locale);
		File.Close();
	}
	void ShowStaff()
	{
		CString string;
		for(std::vector<Staff>::iterator Iter=staffList.begin();Iter!=staffList.end();Iter++)
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
		MessageBox(NULL,string,_TEXT("工作人员信息"),MB_OK);
	}
	void ShowStaff(Staff aStaff)
	{
		CString string,temp;
		string+=TEXT("Name=");
		string+=aStaff.getName();
		string+=TEXT(" Sex=");
		temp.Format(_T("%c"),aStaff.getSex());
		string+=temp;
		string+=TEXT(" Age=");
		temp.Format(_T("%d"),aStaff.getAge());
		string+=temp;
		string+=TEXT(" Number=");
		temp.Format(_T("%d"),aStaff.getNumber());
		string+=temp;
		string+="\n";
		MessageBox(NULL,string,_TEXT("工作人员信息"),MB_OK);
	}
	Staff SearchStaff(CString aName)
	{
		for(std::vector<Staff>::iterator Iter=staffList.begin();Iter!=staffList.end();Iter++)
			if(Iter->getName()==aName)
				return *Iter;
		return noneStaff;
	}
	Staff SearchStaff(CString aUserName,CString aPassword)
	{
		for(std::vector<Staff>::iterator Iter=staffList.begin();Iter!=staffList.end();Iter++)
			if(Iter->getUserName()==aUserName&&Iter->getPassword()==aPassword)
				return *Iter;
		return noneStaff;
	}
	bool DeleteStaff(int aNumber)
	{
		bool ret=0;
		for(std::vector<Staff>::iterator Iter=staffList.begin();Iter!=staffList.end();Iter++)
			if(Iter->getNumber()==aNumber)
			{
				ret=1;
				if(Iter!=staffList.end()-1)
					Iter=staffList.erase(Iter);
				else
				{
					staffList.erase(Iter);
					break;
				}
			}
		UpdateStaffList();
		return ret;
	}
	bool DeleteStaff(CString aName)
	{
		bool ret=0;
		for(std::vector<Staff>::iterator Iter=staffList.begin();Iter!=staffList.end();Iter++)
			if(Iter->getName()==aName)
			{
				ret=1;
				if(Iter!=staffList.end()-1)
					Iter=staffList.erase(Iter);
				else
				{
					staffList.erase(Iter);
					break;
				}
			}
		UpdateStaffList();
		return ret;
	}
	void EditStaffPassword(Staff aStaff)
	{
		for(std::vector<Staff>::iterator Iter=staffList.begin();Iter!=staffList.end();Iter++)
			if(Iter->getName()==aStaff.getName())
				Iter->setPassword(aStaff.getPassword());
		UpdateStaffList();
	}
	bool EditStaff(Staff aStaff)
	{
		bool ret=0;
		for(std::vector<Staff>::iterator Iter=staffList.begin();Iter!=staffList.end();Iter++)
			if(Iter->getName()==aStaff.getName())
			{
				Iter->setNumber(aStaff.getNumber());
				Iter->setSex(aStaff.getSex());
				Iter->setAge(aStaff.getAge());
				Iter->setNumber(aStaff.getNumber());
				Iter->setUserName(aStaff.getUserName());
				Iter->setPassword(aStaff.getPassword());
				ret=1;
			}
		UpdateStaffList();
		return ret;
	}
	void UpdateStaffList()
	{
		CStdioFile File;
		CString temp;
		File.Open(TEXT("staff.txt"),CFile::modeWrite|CFile::modeCreate);
		char* old_locale=_strdup(setlocale(LC_CTYPE,NULL));
		setlocale( LC_CTYPE,"chs");
		for(std::vector<Staff>::iterator Iter=staffList.begin();Iter!=staffList.end();Iter++)
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
			File.WriteString(temp);
			File.WriteString(TEXT("\n"));
			File.WriteString(Iter->getUserName());
			File.WriteString(TEXT("\n"));
			File.WriteString(Iter->getPassword());
			File.WriteString(TEXT("\n"));
		}
		setlocale(LC_CTYPE,old_locale);
		free(old_locale);
		File.Close();
	}
	bool CheckStaff(Staff aStaff)
	{
		for(std::vector<Staff>::iterator Iter=staffList.begin();Iter!=staffList.end();Iter++)
			if(Iter->getUserName()==aStaff.getUserName()&&Iter->getPassword()==aStaff.getPassword())
				return true;
		return false;
	}
	void setCurrentUser(Staff aStaff)
	{
		CStdioFile File;
		CString temp;
		File.Open(TEXT("current user.txt"),CFile::modeWrite|CFile::modeCreate);
		char* old_locale=_strdup(setlocale(LC_CTYPE,NULL));
		setlocale( LC_CTYPE,"chs");
		File.WriteString(aStaff.getName());
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%c"),aStaff.getSex());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%d"),aStaff.getAge());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%d"),aStaff.getNumber());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		File.WriteString(aStaff.getUserName());
		File.WriteString(TEXT("\n"));
		File.WriteString(aStaff.getPassword());
		File.WriteString(TEXT("\n"));
		setlocale(LC_CTYPE,old_locale);
		free(old_locale);
		File.Close();
	}
	Staff getCurrentUser()
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
		Staff staff=Staff(aName,aSex,aAge,aNumber,aUserName,aPassword);
		setlocale(LC_CTYPE,old_locale);
		free(old_locale);
		File.Close();
		return staff;
	}
};


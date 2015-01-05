#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <afx.h>
#include <vector>
#include <algorithm>
#include "Student.h"
#include <fstream>
#include "locale.h"
using namespace std;

class StudentManager
{
private:
	std::vector<Student> studentList;
	Student noneStudent;
public:
	static bool CompName(Student aStudent,Student bStudent)
	{
		return aStudent.getName()<bStudent.getName();
	}
	static bool CompAge(Student aStudent,Student bStudent)
	{
		return aStudent.getNumber()<bStudent.getNumber();
	}
	StudentManager()
	{
		CStdioFile File;
		File.Open(TEXT("student.txt"),CFile::modeRead);
		CString aName,temp;
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
			Student s=Student(aName,aSex,aAge,aNumber);
			studentList.push_back(s);
		}
		setlocale(LC_CTYPE,old_locale);
		free(old_locale);
		File.Close();
	}
	void AddStudent(Student aStudent)
	{
		studentList.push_back(aStudent);
		CStdioFile File;
		CString temp;
		File.Open(TEXT("student.txt"),CFile::modeWrite);
		char* old_locale=_strdup(setlocale(LC_CTYPE,NULL));
		setlocale( LC_CTYPE,"chs");
		File.SeekToEnd();
		File.WriteString(aStudent.getName());
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%c"),aStudent.getSex());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%d"),aStudent.getAge());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		temp.Format(_T("%d"),aStudent.getNumber());
		File.WriteString(temp);
		File.WriteString(TEXT("\n"));
		setlocale(LC_CTYPE,old_locale);
		free(old_locale);
		File.Close();
	}
	void SortStudentByName()
	{
		sort(studentList.begin(),studentList.end(),CompName);
		UpdateStudentList();
	}
	void SortStudentByAge()
	{
		sort(studentList.begin(),studentList.end(),CompAge);
		UpdateStudentList();
	}
	void ShowStudent()
	{
		CString string;
		for(std::vector<Student>::iterator Iter=studentList.begin();Iter!=studentList.end();Iter++)
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
		MessageBox(NULL,string,_TEXT("学生信息"),MB_OK);
	}
	void ShowStudent(Student aStudent)
	{
		CString string,temp;
		string+=TEXT("Name=");
		string+=aStudent.getName();
		string+=TEXT(" Sex=");
		temp.Format(_T("%c"),aStudent.getSex());
		string+=temp;
		string+=TEXT(" Age=");
		temp.Format(_T("%d"),aStudent.getAge());
		string+=temp;
		string+=TEXT(" Number=");
		temp.Format(_T("%d"),aStudent.getNumber());
		string+=temp;
		string+="\n";
		MessageBox(NULL,string,_TEXT("学生信息"),MB_OK);
	}
	Student SearchStudent(int aNumber)
	{
		for(std::vector<Student>::iterator Iter=studentList.begin();Iter!=studentList.end();Iter++)
			if(Iter->getNumber()==aNumber)
				return *Iter;
		return noneStudent;
	}
	Student SearchStudent(CString aName)
	{
		for(std::vector<Student>::iterator Iter=studentList.begin();Iter!=studentList.end();Iter++)
			if(Iter->getName()==aName)
				return *Iter;
		return noneStudent;
	}
	bool DeleteStudent(int aNumber)
	{
		bool ret=0;
		for(std::vector<Student>::iterator Iter=studentList.begin();Iter!=studentList.end();Iter++)
			if(Iter->getNumber()==aNumber)
			{
				ret=1;
				if(Iter!=studentList.end()-1)
					Iter=studentList.erase(Iter);
				else
				{
					studentList.erase(Iter);
					break;
				}
			}
		UpdateStudentList();
		return ret;
	}
	bool DeleteStudent(CString aName)
	{
		bool ret=0;
		for(std::vector<Student>::iterator Iter=studentList.begin();Iter!=studentList.end();Iter++)
			if(Iter->getName()==aName)
			{
				ret=1;
				if(Iter!=studentList.end()-1)
					Iter=studentList.erase(Iter);
				else
				{
					studentList.erase(Iter);
					break;
				}
			}
		UpdateStudentList();
		return ret;
	}
	bool EditStudent(Student aStudent)
	{
		bool ret=0;
		for(std::vector<Student>::iterator Iter=studentList.begin();Iter!=studentList.end();Iter++)
			if(Iter->getName()==aStudent.getName())
			{
				Iter->setNumber(aStudent.getNumber());
				Iter->setSex(aStudent.getSex());
				Iter->setAge(aStudent.getAge());
				Iter->setNumber(aStudent.getNumber());
				ret=1;
			}
		UpdateStudentList();
		return ret;
	}
	void UpdateStudentList()
	{
		CStdioFile File;
		CString temp;
		File.Open(TEXT("student.txt"),CFile::modeWrite|CFile::modeCreate);
		char* old_locale=_strdup(setlocale(LC_CTYPE,NULL));
		setlocale( LC_CTYPE,"chs");
		for(std::vector<Student>::iterator Iter=studentList.begin();Iter!=studentList.end();Iter++)
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
		}
		setlocale(LC_CTYPE,old_locale);
		free(old_locale);
		File.Close();
	}
};

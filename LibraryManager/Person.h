#pragma once
#include <afx.h>
class Person
{
protected:
	CString name;
	char sex;
	int age;
	int number;
public:
	Person(){};
	Person(CString aName,char aSex,int aAge,int aNumber)
	{
		name=aName;
		sex=aSex;
		age=aAge;
		number=aNumber;
	}
	virtual void ShowMenu()=0;
	CString getName()
	{
		return name;
	}
	char getSex()
	{
		return sex;
	}
	int getAge()
	{
		return age;
	}
	int getNumber()
	{
		return number;
	}
	void setName(CString aName)
	{
		name=aName;
	}
	void setSex(char aSex)
	{
		sex=aSex;
	}
	void setAge(int aAge)
	{
		age=aAge;
	}
	void setNumber(int aNumber)
	{
		number=aNumber;
	}
};

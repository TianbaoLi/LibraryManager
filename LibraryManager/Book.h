#pragma once
#include <afx.h>
class Book
{
private:
	CString name;
	int number;
	int amount;
	CTime inDate;
	int status;
	CString rentBy;
public:
	Book(){};
	Book(CString aName,int aNumber,int aAmount,int aYear,int aMonth,int aDay,int aStatus)
	{
		name=aName;
		number=aNumber;
		amount=aAmount;
		inDate=CTime(aYear,aMonth,aDay,0,0,0);
		status=aStatus;
		rentBy="";
	}
	CString getName()
	{
		return name;
	}
	int getNumber()
	{
		return number;
	}
	int getAmount()
	{
		return amount;
	}
	CTime getInDate()
	{
		return inDate;
	}
	int getStatus()
	{
		return status;
	}
	CString RentBy()
	{
		return rentBy;
	}
	void setName(CString aName)
	{
		name=aName;
	}
	void setNumber(int aNumber)
	{
		number=aNumber;
	}
	void setAmount(int aAmount)
	{
		amount=aAmount;
	}
	void setInDate(CTime aInDate)
	{
		inDate=aInDate;
	}
	void setStatus(int aStatus)
	{
		status=aStatus;
	}
	void  setRentBy(CString aRentBy)
	{
		rentBy=aRentBy;
	}
};

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "date.h"
#include "Date.h"
enum MONTH
{
	jan = 1, feb, march, april, may, june, july, agu, september, oct, nov, dec
};

Date::Date() //default ctor
{
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	day = timeinfo->tm_mday;
	month = timeinfo->tm_mon + 1;
	year = timeinfo->tm_year + 1900;
}

Date::Date(int Day, int Month, int Year)
{
	day = Day;
	month = Month;
	year = Year;
}
Date::~Date()
{
	/*cout << "dector!!" << endl << "deleting day!" << endl << "deleting mount" << endl << "deleting year" << endl;*/
}

int Date::getday()
{
	return day;
}
int Date::getmonth()
{
	return month;
}

int Date::getyear()
{
	return year;
}

void Date::setday(int day1)
{
	day = day1;

}
void Date::setmonth(int month1)
{
	month = month1;
}

void Date::setyear(int year1)
{
	year = year1;
}

void Date::printdate()
{
	cout << day << "/" << month << "/" << year << endl;
}

void Date::printdatelatter()
{

	if (month == 1)
	{
		cout << "month you entered is : " << "januar" << endl;
	}
	if (month == 2)
	{
		cout << "month you entered is : " << "feb" << endl;
	}
	if (month == 3)
	{
		cout << "month you entered is : " << "march" << endl;
	}
	if (month == 4)
	{
		cout << "month you entered is : " << "april" << endl;
	}
	if (month == 5)
	{
		cout << "month you entered is : " << "may" << endl;
	}
	if (month == 6)
	{
		cout << "month you entered is : " << "june" << endl;
	}
	if (month == 7)
	{
		cout << "month you entered is : " << "july" << endl;
	}
	if (month == 8)
	{
		cout << "month you entered is : " << "agu" << endl;
	}
	if (month == 9)
	{
		cout << "month you entered is : " << "september" << endl;
	}
	if (month == 10)
	{
		cout << "month you entered is : " << "oct" << endl;

	}
	if (month == 11)
	{
		cout << "month you entered is : " << "nov" << endl;
	}
	if (month == 12)
	{
		cout << "month you entered is : " << "dec" << endl;
	}
}
int Date::dayonmonth()
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		return 31;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		return 30;
	}
	if (month == 2)
	{
		if (year % 400 == 0)
		{
			return 29;
		}
		return 28;
	}
}
bool Date::meobert()
{
	if (year % 400 == 0)
		return true;
	return false;

}
void Date::dayafter()
{
	if (meobert() == 1)
	{
		day += 1;
		if (day = 29)
		{
			month += 1;
			day = 1;
		}

	}
	else
	{
		day += 1;
		if (dayonmonth() == 31)
		{
			if (day > 31)
			{
				day = 1;
				month += 1;
			}
		}
		if (dayonmonth() == 30)
		{
			if (day > 30)
			{
				day = 1;
				month += 1;
			}
		}
		if (dayonmonth() == 28)
		{
			if (day > 28)
			{
				day = 1;
				month += 1;
			}
		}
	}
}
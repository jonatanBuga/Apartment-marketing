#pragma once

#include <iostream>
#include <time.h>
#include <string.h>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int, int, int);
	~Date();

	int getday();
	int getmonth();
	int getyear();
	void setday(int);
	void setmonth(int);
	void setyear(int);
	void printdate();
	void printdatelatter();
	int dayonmonth();
	bool meobert();
	void dayafter();


};

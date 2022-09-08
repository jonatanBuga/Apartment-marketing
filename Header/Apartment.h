#pragma once
#include <iostream>
#include <string>
using namespace std;

class Apartment
{
	int num_of_apartment;
	int floor;
	int area_of_apartment;
	bool sold;
public:
	Apartment(int, int);
	Apartment() {};
	void setsold(bool value1) { sold = value1; }
	bool getsold() { return sold; }
	void setarea(int area) { area_of_apartment = area; }
	virtual ~Apartment() {};
	virtual int getprice()=0{};
	virtual void print();
	virtual int getfloor() { return floor; }
	virtual int getarea() { return area_of_apartment; }
};


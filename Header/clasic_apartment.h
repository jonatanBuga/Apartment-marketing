#pragma once
#include <iostream>
#include <string>
#include "Apartment.h"
using namespace std;
class clasic_apartment:public Apartment
{
	int num_of_balconies;
	int* sizes_of_balconies;
public:
	clasic_apartment(int, int*,int,int,int);
	~clasic_apartment() 
	{
		
		delete[]sizes_of_balconies;

	}
	int getprice();
	void print();
	int getnum_balconies() { return num_of_balconies; }
};


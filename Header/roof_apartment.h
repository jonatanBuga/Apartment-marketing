#pragma once
#include "Apartment.h"
#include <iostream>
#include <string>
using namespace std;
class roof_apartment:public Apartment
{
	int size_of_balconie;
public:
	roof_apartment(int,int,int,int);
	~roof_apartment() {};
	void print();
	int getprice();

};


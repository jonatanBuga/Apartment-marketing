#pragma once
#include "Apartment.h"
#include <string>
#include "Apartment.h"
using namespace std;
class garden_apartment:public Apartment
{
	int area_of_garden;
	bool pool;
public:
	garden_apartment(int,bool,int,int);
	~garden_apartment(){}
	void print();
	int getprice();
	int getarea() { return area_of_garden; }

};


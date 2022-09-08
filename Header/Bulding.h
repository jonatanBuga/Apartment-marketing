#pragma once
#include <typeinfo>
#include "Apartment.h"
#include "clasic_apartment.h"
#include "garden_apartment.h"
#include "roof_apartment.h"
#include <iostream>
#include <string>
using namespace std;
class Bulding
{
	string address;
	int num_of_floors;
	Apartment** pApartments;
public:
	Bulding(string, int,Apartment**);
	virtual ~Bulding() 
	{
		for (int i = 0; i < getNapart(); i++)
			delete pApartments[i];
		delete[]pApartments;
	};
	void print_apartments();
	int numofapart(int);
	string getaddres() { return address; }
	int getNapart()
	{ 
		int x=numofapart(num_of_floors);
		return x;
		
	}
	Apartment* returnapart_by_num(int index) { return pApartments[index]; }
	int getnum_of_floor() { return num_of_floors; }
	Bulding& operator[](int);
	Apartment** getapart() { return pApartments; }

};


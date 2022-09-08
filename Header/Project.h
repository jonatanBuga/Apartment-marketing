#pragma once
#include "Bulding.h"
using namespace std;

class Project
{
	string name_of_project;
	int numbers_of_buldings;
	Bulding** pbulding;
public:
	Project(Bulding**,string, int);
	virtual ~Project() 
	{
		for (int i = 0; i < numbers_of_buldings; i++)
			delete pbulding[i];
		delete[]pbulding;
	};
	void print_buldings();
	Project& operator+(Bulding*);
	int num_of_apartment_buld(string);
	string getproject_name() { return name_of_project; }
	int getnum_of_bulding() { return numbers_of_buldings; }
	bool operator[](string);
	Project& operator()(int,int);
	Bulding* returnbuld(int);
};


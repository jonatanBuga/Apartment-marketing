#pragma once
#include <typeinfo>
#include "Person.h"
#include "Apartment.h"
#include "clasic_apartment.h"
#include "garden_apartment.h"
#include "roof_apartment.h"
#include "date.h"
using namespace std;
class client:public Person
{
	static int sum_of_client;
	int index_of_client;
	int budgt;
	Apartment** pApartments;
	Date** days_of_buy =NULL;
	int numApartment_buy;
	int* arnona_for_all;

public:
	client(string, string, int);
	~client()
	{
		for (int i = 0; i < numApartment_buy; i++)
		{
			delete pApartments[i];
			delete days_of_buy[i];
		}
		delete[]pApartments;
		delete[]days_of_buy;
	}
	int* arnona_for_apartment();
	void print();
	client& operator +(Apartment*);//update apartment has buy
	int get_index() { return index_of_client; }
	int get_budgt() { return budgt; }
	void help_update_apart();
	void update_days(int, int, int);
	int getnumapart_buy() { return numApartment_buy; }
	int getnumclasic(int);// exspect month
	int getnumgarden(int); //exspect month
	int getnumroof(int);//exspect month
	int getnum_of_clasic();
	int getnum_of_garden();
	int getnum_of_roof();

};


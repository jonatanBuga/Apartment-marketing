#include "client.h"

using namespace std;
int client::sum_of_client = 0;
client::client(string first, string last, int takziv) :Person(first, last), budgt(takziv), pApartments(nullptr),arnona_for_all(NULL)
{
	sum_of_client++;
	index_of_client = sum_of_client-1;

}
void client::print()
{
	cout << "--------client---------" << endl;
	Person::print();
	if (numApartment_buy > 0)
	{
		for (int i = 0; i < numApartment_buy; i++)
		{
			
			pApartments[i]->print();
			cout << endl;
			days_of_buy[i]->printdate();
		}
	}
	else
	{
		cout << "client didnt have  apartments yet" << endl;
	}
}
int* client::arnona_for_apartment()
{
	int x = 0;
	int y = 0;
	int arnona_temp = 0;
	for (int i = 0; i < numApartment_buy; i++)
	{
		clasic_apartment* temp = dynamic_cast<clasic_apartment*>(pApartments[i]);
		if (temp!=NULL)
		{
			if (temp->getnum_balconies() == 2)
			{
				x = 0;
				y = 1;
			}
			else
			{
				x = 0;
				y = 0;
			}
		}
		garden_apartment* temp1 = dynamic_cast<garden_apartment*>(pApartments[i]);
		if (temp1!=NULL)
		{
			x = 2;
			y = 0;
		}
		roof_apartment* temp2 = dynamic_cast<roof_apartment*>(pApartments[i]);
		if (temp2!=NULL)
		{
			x = 1;
			y = 0;
		}
		if (numApartment_buy <= 1)
		{
			arnona_for_all = new int[numApartment_buy];
		}
		arnona_temp = (x * 120) + (y * 300) + pApartments[i]->getarea() * 25;
		arnona_for_all[i] = arnona_temp;
		arnona_temp = 0;
	}
	return arnona_for_all;
}

int client::getnumclasic(int month)
{
	int x = 0;
	for (int i = 0; i < numApartment_buy; i++)
	{
		if (month == days_of_buy[i]->getmonth())
		{
			clasic_apartment* temp = dynamic_cast<clasic_apartment*>(pApartments[i]);
			if (!temp)
				x++;
		}
	}
	return x;
}
int client::getnumgarden(int month)
{
	int x = 0;
	for (int i = 0; i < numApartment_buy; i++)
	{
		if (month == days_of_buy[i]->getmonth())
		{
			garden_apartment* temp = dynamic_cast<garden_apartment*>(pApartments[i]);
			if (!temp)
				x++;
		}
	}
	return x;
}
int client::getnumroof(int month)
{
	int x = 0;
	for (int i = 0; i < numApartment_buy; i++)
	{
		if (month == days_of_buy[i]->getmonth())
		{
			roof_apartment* temp = dynamic_cast<roof_apartment*>(pApartments[i]);
			if (!temp)
				x++;
		}
	}
	return x;

}

int client::getnum_of_clasic()
{
	int x = 0;
	for (int i = 0; i < numApartment_buy; i++)
	{
		clasic_apartment* help = dynamic_cast<clasic_apartment*>(pApartments[i]);
		if (!help)
			x++;
	}
	return x;
}
int client::getnum_of_garden()
{
	int x = 0;
	for (int i = 0; i < numApartment_buy; i++)
	{
		garden_apartment* help = dynamic_cast<garden_apartment*>(pApartments[i]);
		if (!help)
			x++;
	}
	return x;
}
int client::getnum_of_roof()
{
	int x = 0;
	for (int i = 0; i < numApartment_buy; i++)
	{
		roof_apartment* help = dynamic_cast<roof_apartment*>(pApartments[i]);
		if (!help)
			x++;
	}
	return x;
}

client& client:: operator +(Apartment* papart)
{
	
	Apartment** temp_apart = new Apartment * [++numApartment_buy];
	for (int i = 0; i < numApartment_buy-1; i++)
	{
		temp_apart[i] = pApartments[i];
	}
	temp_apart[numApartment_buy - 1] = papart;
	delete[]pApartments;
	pApartments = temp_apart;
	
	
	return *this;
}
void client::help_update_apart()
{

	/*pApartments = new Apartment * [++numApartment_buy];
	days_of_buy = new Date * [++numApartment_buy];*/
}
void client::update_days(int d, int m, int y)
{
	if (numApartment_buy <= 0)
	{
		days_of_buy = new Date * [numApartment_buy];
		days_of_buy[0] = new Date(d, m, y);
	}
	else
	{

		Date** temp_date = new Date * [numApartment_buy];
		for (int i = 0; i < numApartment_buy - 1; i++)
		{
			temp_date[i] = days_of_buy[i];
		}
		temp_date[numApartment_buy - 1] = new Date(d, m, y);
		delete[]days_of_buy;
		days_of_buy = temp_date;
	}
	

}
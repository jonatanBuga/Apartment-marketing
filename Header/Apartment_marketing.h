#pragma once
#include "Person.h"
#include"Apartment.h"
#include "Project.h"
#include "seller_man.h"
#include "client.h"
class Apartment_marketing
{
	Person** pPersons;
	Apartment** all_apartments;
	Project** projects;
	int num_of_persons;
	int num_of_allApartments;
	int num_of_projects;
	void Deinitapartments();
	void Deinitperson();
	void Deinitproject();
	void ShowMenu();
	Bulding* Help_init_bulding();
	int numofapart(int);
	void helo_init_apartment(Apartment**,int);
public:
	Apartment_marketing();
	~Apartment_marketing()
	{
		for (int i = 0; i < num_of_projects; i++)
		{
			delete projects[i];
		}
		delete[]projects;
	}
	Apartment_marketing& Menu();
	
		

};


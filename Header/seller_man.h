#pragma once
#include <typeinfo>
#include "Person.h"
#include "Project.h"
#include "client.h"
#include "Bulding.h"

using namespace std;

class seller_man :public Person
{
	Project* pPRO;
	client** pClient;
	int num_of_client;
	
public:
	seller_man(string, string, Project*);
	~seller_man()//
	{
		for (int i = 0; i < num_of_client; i++)
			delete pClient[i];
		delete[]pClient;
	}
	int salary_of_seler(int);
	void print();
	int cout_of_apartsale(int);
	void update_client();
	seller_man& operator+(client*);
	Project* returnproject() { return pPRO; }

};


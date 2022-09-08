#include "seller_man.h"
using namespace std;

seller_man::seller_man(string first, string last, Project* Ppro):Person(first,last),pPRO(Ppro),pClient(NULL)
{
}
 
int seller_man::salary_of_seler(int month)
{
	int x=0, y=0, z=0;
	for (int i = 0; i < num_of_client; i++)
	{
		x += pClient[i]->getnumclasic(month);
		y += pClient[i]->getnumroof(month);
		z += pClient[i]->getnumgarden(month);
	}
	return (x * 1000) + (y * 1500) + (z * 2000);
	
	
}

void seller_man::print()
{
	cout << "information of seller man:" << endl;
	Person::print();
	int standart=0, roof=0, garden=0;
	for (int i = 0; i < num_of_client; i++)
	{
		standart += pClient[i]->getnum_of_clasic();
		roof += pClient[i]->getnum_of_roof();
		garden += pClient[i]->getnum_of_garden();
	}
	cout << "number of standart apartment type is:" << standart << endl;
	cout << "number of garden apartment type is:" << garden << endl;
	cout << "number of roof apartment type is:" << roof << endl;
}

int seller_man::cout_of_apartsale(int month1)
{
	int counter = 0;
	for (int i = 0; i < num_of_client; i++)
	{
		counter += (pClient[i]->getnumclasic(month1)) + (pClient[i]->getnumgarden(month1)) + (pClient[i]->getnumroof(month1));
	}
	return counter;
}

seller_man& seller_man:: operator+(client* pC)
{
	if (num_of_client < 1)
	{
		update_client();
	}
	else
	{
		num_of_client++;
	}
	pClient[num_of_client - 1] = pC;
	
	return *this;
}
void seller_man::update_client()
{
	pClient = new client * [++num_of_client];
}
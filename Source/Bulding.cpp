#include "Bulding.h"
using namespace std;

Bulding::Bulding(string Ad, int num, Apartment** pdata) :address(Ad), num_of_floors(num),pApartments(pdata)
{
	int apart = numofapart(num);
}

void Bulding::print_apartments()
{
	int temp = 0;
	temp = numofapart(this->num_of_floors);
	cout << "addres of bulding is :" << address<<endl;
	cout << "all apartmrnt at bulding:" << endl;
	for (int i = 0; i < temp; i++)
	{
		
		garden_apartment* temp2 = dynamic_cast<garden_apartment*>(pApartments[i]);
		if (temp2 != NULL)
		{
			
			pApartments[i]->print();
			cout << endl;
		}
	}
	for (int i = 0; i < temp; i++)
	{
		clasic_apartment* temp1 = dynamic_cast<clasic_apartment*>(pApartments[i]);
		if (temp1 != NULL)
		{
			
			pApartments[i]->print();
			cout << endl;
		}
	}
	for (int i = 0; i < temp; i++)
	{
		roof_apartment* temp3 = dynamic_cast<roof_apartment*>(pApartments[i]);
		if (temp3 != NULL)
		{
			
			pApartments[i]->print();
			cout << endl;
		}
	}

	
	

}

Bulding& Bulding:: operator[](int index)
{
	int temp_num = numofapart(num_of_floors);
	for (int i = 0; i < temp_num; i++)
	{
		if (i == index)
		{
			pApartments[i]->print();
		}
	}
	return *this;
}

int Bulding::numofapart(int num1)
{
	int x= 0;
	int num_apart = 0;
	x = num1 - 2;
	num_apart = (x * 2) + 2;
	
	return num_apart;
}
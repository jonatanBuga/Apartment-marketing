#include "roof_apartment.h"
using namespace std;

roof_apartment::roof_apartment(int Size,int index,int floo,int AREA):Apartment(index,floo) ,size_of_balconie(Size)
{
	setarea(AREA);
}

void roof_apartment::print()
{
	cout << "data for roof apartment :" << endl;
	Apartment::print();
	cout << "price for roof apartment is:" << getprice();
}

int roof_apartment::getprice()
{
	return 700000 + getarea() * 600 + size_of_balconie * 200;
}
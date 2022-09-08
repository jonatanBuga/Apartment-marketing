#include "garden_apartment.h"
using namespace std;

garden_apartment::garden_apartment(int area, bool P,int floo,int num):Apartment(num,floo), area_of_garden(area),pool(P)
{
	setarea(area_of_garden);
}
int garden_apartment::getprice()
{
	return 600000 + area_of_garden * 600 + (int)pool * 100000;
}

void garden_apartment::print()
{
	cout << "data of garden apartment:" << endl;
	Apartment::print();
	cout << "price of garden apartment is:" << getprice();
}
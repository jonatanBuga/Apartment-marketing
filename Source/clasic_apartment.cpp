#include "clasic_apartment.h"
#include "Apartment.h"
using namespace std;

clasic_apartment::clasic_apartment(int num, int* array1,int floo,int index,int AREA):Apartment(index,floo), num_of_balconies(num),sizes_of_balconies(array1)
{
	setarea(AREA);
}
void clasic_apartment::print()
{
	cout << "data of clasic apartment:" << endl;
	Apartment::print();
	cout << "price for this clasic apartment is:";
	cout << getprice();
}

int clasic_apartment::getprice()
{
	
	return 300000 + num_of_balconies * 12000 + getfloor() * 300 + getarea() * 500;
}
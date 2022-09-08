#include "Apartment.h"
using namespace std;
Apartment::Apartment(int num, int Floor):num_of_apartment(num),floor(Floor)
{	
}


void Apartment::print()
{
	cout << "number of apartment is:" << num_of_apartment<<endl;
	cout << "apartment at:" << floor << "floor." << endl;//give space
	cout << "area of apartment is :" << area_of_apartment << endl;

}
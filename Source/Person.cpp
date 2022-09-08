#include "Person.h"
using namespace std;

Person::Person(string first, string last) :first_name(first), last_name(last)
{
}
void Person::print()
{
	cout << "name of person is :" << endl;
	cout << "first name :" << first_name << "  ";
	cout << "last name:" << last_name << endl;
}

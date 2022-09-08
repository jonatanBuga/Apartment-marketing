#pragma once
#include <iostream>
#include <string>
using namespace std;
class Person
{
	string first_name;
	string last_name;
public:
	Person(string, string);
	virtual ~Person() = 0{}
	virtual void print();
	string getfirst() { return first_name; }
	string getlast() { return last_name; }

};


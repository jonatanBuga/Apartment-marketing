#include "Project.h"
using namespace std;


Project::Project(Bulding** pdata,string name, int builds):name_of_project(name),numbers_of_buldings(builds),pbulding(pdata)
{
	
}

void Project::print_buldings()
{
	for (int i = 0; i < numbers_of_buldings; i++)
	{
		cout << "informtion of bulding  " << i + 1 << "is:" << endl;
		pbulding[i]->print_apartments();
	}
}
Project& Project:: operator+(Bulding* pbuild)
{
	cout << numbers_of_buldings;
	Bulding** temp = new Bulding * [++numbers_of_buldings];
	for (int i = 0; i < numbers_of_buldings-1; i++)
	{
		temp[i] = pbulding[i];
	}
	temp[numbers_of_buldings-1] = pbuild;
	delete[]pbulding;
	pbulding = temp;
	return *this;
}

int Project::num_of_apartment_buld(string name1)
{
	int flag = 0;
	
	for (int i = 0; i < numbers_of_buldings; i++)
	{
		if (pbulding[i]->getaddres() == name1)
		{
			cout << "numbers of apartment at this bulding is:" << pbulding[i]->getNapart();
			flag = 1;
		}
		if (flag == 1)
			break;
		else
			flag = 0;
	}
	if (flag == 0)
	{
		cout << "there isnt name bulding that named" << endl;
		return -1;
	}
}

bool Project:: operator[](string add)
{
	int flag = 0;
	for (int i = 0; i < numbers_of_buldings; i++)
	{
		if (pbulding[i]->getaddres() == add)
		{
			flag = 1;
			break;
		}
		else
		{
			flag = 0;
		}
	}
	if (flag == 1)
		return true;
	return false;
}
Project& Project::operator()(int INDEX,int num)
{
	for (int i = 1; i < numbers_of_buldings+1; i++)
	{
		if (i == num)
		{
			
			this->pbulding[i-1]->operator[](INDEX);
		}
	}
	return *this;
}
Bulding* Project::returnbuld(int num)
{
	return pbulding[num];
}
#include "Apartment_marketing.h"
using namespace std;

Apartment_marketing::Apartment_marketing():num_of_allApartments(4),num_of_persons(1),num_of_projects(1)
{
	Deinitapartments();
	Deinitproject();
	Deinitperson();
}
void Apartment_marketing::Deinitapartments()
{
	all_apartments = new Apartment * [num_of_allApartments];
	int* temp = new int[2];
	temp[0] = 18;
	temp[1] = 15;
	int* temp2 = new int[1];
	temp2[0] = 23;
	all_apartments[0] = new garden_apartment(170, true,0,1);
	all_apartments[1] = new clasic_apartment(2,temp,1,2,120);
	all_apartments[2] = new clasic_apartment(1, temp2,1,3,125);
	all_apartments[3] = new roof_apartment(35,4,3,130);
}
void Apartment_marketing::Deinitproject()
{
	
	projects = new Project * [num_of_projects];
	Bulding** help = new Bulding * [1];
	help[0] = new	Bulding("rotshild", 3, all_apartments);
	projects[0] = new Project(help, "avisror", 1);

}

void Apartment_marketing::Deinitperson()
{
	pPersons = new Person * [num_of_persons];
	pPersons[0] = new seller_man("moti", "afenjar", projects[0]);
}
int Apartment_marketing::numofapart(int num1)
{
	int x = 0;
	int num_apart = 0;
	x = num1 - 2;
	num_apart = (x * 2) + 2;

	return num_apart;
}
void Apartment_marketing::helo_init_apartment(Apartment** help_apart,int num)
{
	int j = 0;
	for (int i = num; i < num_of_allApartments; i++)
	{
		all_apartments[i] = help_apart[j];
		j++;
	}
}
Bulding* Apartment_marketing::Help_init_bulding()
{
	
	Apartment** temp_apart;
	string addr;
	int numfloor,num_of_apart;
	cout << "enter Address of bulding" << endl;
	cin >> addr;
	cout << "enter number floors of bulding" << endl;
	cin >> numfloor;
	cout << "---Init apartment of bulding" << endl;
	num_of_apart = numofapart(numfloor);
	int chooies = 0;
	temp_apart = new Apartment * [num_of_apart];
	int garden_area;
	string cheak;
	bool pool;
	cout << "for start init garden apartment" << endl;
	cout << "enter garden area:" << endl;
	cin >> garden_area;
	cout << "there is a pool at this apartment? rigth T/R" << endl;
	cin >> cheak;
	if (cheak == "T")
	{
		pool = true;
	}
	else
	{
		pool = false;
	}
	temp_apart[0] = new garden_apartment(garden_area, pool,0,1);
	cout << "--init roof apartment--" << endl;
	int size_of_balc,area_roof;
	cout << "enter area of apartment" << endl;
	cin >> area_roof;
	cout << "enter size of balconie:" << endl;
	cin >> size_of_balc;
	temp_apart[num_of_apart-1] = new roof_apartment(size_of_balc,num_of_apart,numfloor,area_roof);
	int k = 1;
	for (int i = 1; i < num_of_apart-1; i++)//init clasic apartment
	{
		int balconies,area1;
		cout << "init clasic apartment" << i + 1 << ":" << endl;
		cout << "enter area of apartment:" << endl;
		cin >> area1;
		cout << "enter how many balconies at clasic apartment:" << i+1<<endl;
		int flag = 0;
		cin >> balconies;
		while (flag != 1)
		{

			if (balconies > 2)
			{
				flag = 0;
				cout << "cant type number of balconies biger then 2"<<endl;
				cin >> balconies;
			}
			else
			{
				flag = 1;
			}
		}
		
		int* sizes_of_balc = new int[balconies];
		for (int j = 0; j < balconies; j++)
		{
			cout << "enter area of balconies" << j + 1 << ":" << endl;
			cin >> sizes_of_balc[j];
		}
		if (i % 2 == 0)
			k++;
		temp_apart[i] = new clasic_apartment(balconies, sizes_of_balc,k,i,area1);

	}
	Bulding* temp_buld = new Bulding(addr, numfloor, temp_apart);
	
	this->num_of_allApartments += num_of_apart;
	helo_init_apartment(temp_apart, num_of_allApartments - num_of_apart);
	
	return temp_buld;
}
Apartment_marketing& Apartment_marketing::Menu()
{
	cout << "wellcome to our company of apartment marketing" << endl;
	cout << "enter one of 13 option:" << endl;
	int number1=0;
	while (number1 != 13)
	{
		
		ShowMenu();
		cout << "choose option" << endl;
		cin >> number1;
		if (!(number1 >= 1 && number1 <= 13))
		{
			cout << "enter number again" << endl;
		}
		
		switch(number1)
		{
		case 1:
		{
			int x=0;
			for (int i = 0; i < num_of_persons; i++)
			{
				clasic_apartment* temp = dynamic_cast<clasic_apartment*>(pPersons[i]);
				if (temp!=NULL)
				{
					cout << "client " << i + 1 << "has bought clasic apartment :" << endl;
					pPersons[i]->print();
					x++;
				}
				
			}
			if (x == 0)
				cout << "Nowone bought clasic Apartment" << endl;
			break;
		}
		case 2:
		{
			string project_name;
			cout << "choose project to join. enter his name:" << endl;
			cin >> project_name;
			int flag = 0;
			for (int i = 0; i < num_of_projects; i++)
			{
				if (project_name == projects[i]->getproject_name())
				{
					projects[i]->operator+(Help_init_bulding());
					
					flag = 1;
					break;
				}
				else
				{
					flag = 0;
				}
			}
			if (flag != 1)
			{
				cout << "NO match for project name has search.." << endl;
				break;
			}
			break;
		}
		case 3:
		{
			cout << "---Adding new project---" << endl;
			string name_project;
			int num_bulding;
			cout << "name of project?" << endl;
			cin >> name_project;
			cout << "how many numbers of buldings?" << endl;
			cin >> num_bulding;
			
			Bulding** temp1 = new Bulding * [num_bulding];
			for (int i = 0; i < num_bulding; i++)
			{
				temp1[i] = Help_init_bulding();
			}
		
			Project** temp_pro = new Project * [++num_of_projects];
			for (int i = 0; i < num_of_projects-1; i++)
			{
				temp_pro[i] = projects[i];
			}
			temp_pro[num_of_projects - 1] = new Project(temp1, name_project, num_bulding);
			delete[]projects;
			projects = temp_pro;
			

			projects[num_of_projects - 1]->print_buldings();
			break;
		}
		case 4://init seller man
		{
			string first, last ,project_name_check;
			cout << "enter first name of seller man" << endl;
			cin >> first;
			cout << "enter last name " << endl;
			cin >> last;
			cout << "enter name of project to join:" << endl;
			cin >> project_name_check;
			int flag = 0;
			for (int i = 0; i < num_of_projects; i++)
			{
				if (projects[i]->getproject_name() == project_name_check )
				{
					if (!((pPersons[i]->getfirst() == first) && (pPersons[i]->getlast() == last)))
					{
						pPersons[num_of_persons] = new seller_man(first, last, projects[i]);
						flag = 1;
						pPersons[i+1]->print();
						break;
					}
					
				}
			}
			if (flag == 0)
			{
				cout << "data has typing is incorect" << endl;
				break;
			}
		}
		case 5:
		{
			string First, last;
			int takziv, number_to_buy,flag=0;
			cout << "enter first name of client" << endl;
			cin >> First;
			cout << "enter last name of client" << endl;
			cin >> last;
			cout << "enter bouget for client" << endl;
			cin >> takziv;
			
 			for (int i = 0; i < num_of_persons; i++)
			{
				if (pPersons[i]->getfirst() == First && pPersons[i]->getlast() == last)
				{
					flag = 1;
					break;
				}
				flag = 0;
			}
			if (flag != 1)
			{
				++num_of_persons;
				pPersons[num_of_persons - 1] = new client(First, last, takziv);
				break;
			}
			else
			{
				cout << "first and last name has type is exsist" << endl;
				break;
			}
			
		}
		case 6://print apartment by bulding address fron user 
		{
			string add;
			int index_apart;
			cout << "enter address bulding" << endl;
			cin >> add;
			cout << "enter index of apartment to find" << endl;
			cin >> index_apart;
			int flag = 0;
			for (int i = 0; i < num_of_projects; i++)
			{
				if (projects[i]->operator[](add) == 1)
				{
				
					projects[i]->operator()(index_apart,projects[i]->getnum_of_bulding());
					flag = 1;
					break;
				}
				else
				{
					
					flag = 0;
					
				}
			}
			if(flag==0)
				cout << "your data has type doesnt exsist at projects" << endl;
			break;
		}
		case 7:
		{
			int x = 0;
			for (int i = 0; i < num_of_allApartments; i++)
			{
				
				clasic_apartment* temp_apart = dynamic_cast<clasic_apartment*>(all_apartments[i]);
				if (temp_apart != NULL)
				{
					if (temp_apart->getsold() == 0 && temp_apart->getnum_balconies() == 2)
					{
					
						cout << "clasic apartment : " << i + 1 << "has found is" << endl;
						temp_apart->print();
						cout << "---------" << endl;
						cout << endl;
						x++;
						
					}
					
				}
				
			}
			if (x==0)
				cout << "didnt found match bettwen data has typing" << endl;
		}
		case 8:
		{
			string fname, lname;
			int Month,flag=0;
			cout << "enter first name of seller man" << endl;
			cin >> fname;
			cout << "enter last name of seller man" << endl;
			cin >> lname;
			cout << "enter month to claculait salary of seller man" << endl;
			cin >> Month;
			for (int i = 0; i < num_of_persons; i++)
			{
				seller_man* temp_seller = dynamic_cast<seller_man*>(pPersons[i]);
				if (temp_seller != NULL)
				{
					if (temp_seller->getfirst() == fname && temp_seller->getlast() == lname)
					{
						cout<<"salary for month :"<<Month<<"is:"<< temp_seller->salary_of_seler(Month);
						flag = 1;
						break;
					}
				}
				flag = 0;
			}
			if (flag == 0)
				cout << "no match name of seller man that tpye" << endl;
			break;
		}
		case 9:
		{
			int index_for_client;
			cout << "enter index of client to check" << endl;
			cin >> index_for_client;
			for (int i = 0; i < num_of_persons; i++)
			{
				client* temp_client = dynamic_cast<client*>(pPersons[i]);
				if(temp_client!=NULL) 
				{
					if (temp_client->get_index() == index_for_client)
					{
						for (int j = 0; j < num_of_allApartments; j++)
						{
							if (all_apartments[j]->getsold() == 0)
							{
								if (all_apartments[j]->getprice() <= temp_client->get_budgt())
								{
									cout << "apartment for sale at your budgt: " << endl;
									all_apartments[j]->print();
									
								}
							}
						}
					}
					
				}
			}
			break;
		}
		case 10://
		{
			string name_proj;
			cout << "enter project name to find" << endl;
			cin >> name_proj;
			int x = 0;
			for (int i = 0; i < num_of_projects; i++)
			{
				
				if (projects[i]->getproject_name() == name_proj)
				{
					for (int j = 0; j < projects[i]->getnum_of_bulding(); j++)
					{
						Bulding* temp = projects[i]->returnbuld(j);
						
						Apartment** help_apart = new Apartment * [temp->getNapart()];
						help_apart = temp->getapart();
						roof_apartment* temp_roof = dynamic_cast<roof_apartment*>(help_apart[temp->getNapart()-1]);
						if (temp_roof != NULL)
						{
								temp_roof->print();
								cout << endl;
								x++;
						}
						
					}
				}
			}
			if (x == 0)
			{
				cout << "no found match of project name has type" << endl;
				break;
			}
			break;
		}
		case 11:
		{
			string projectName, address, firstS, lastS;
			int numApart, numClient;
			cout << "start enter name of project" << endl;
			cin >> projectName;
			cout << "enter first name of seller man" << endl;
			cin >> firstS;
			cout << "enter last name" << endl;
			cin >> lastS;
			int flag = 0;
			for (int i = 0; i < num_of_projects; i++)
			{
				if (projects[i]->getproject_name() == projectName)
				{
					for (int j = 0; j < num_of_persons; j++)
					{
						seller_man* check_seller = dynamic_cast<seller_man*>(pPersons[j]);
						if (check_seller != NULL)
						{
							if (check_seller->getfirst() == firstS && check_seller->getlast() == lastS)
							{
								if (typeid(*check_seller->returnproject()) == typeid(*projects[i]))
								{
									cout << "enter address of bulding" << endl;
									cin >> address;
									cout << "enter num of apartment at this bulding" << endl;
									cin >> numApart;
									for (int k = 0; projects[i]->getnum_of_bulding(); k++)
									{
										Bulding* temp_buld = projects[i]->returnbuld(k);
										if (temp_buld != NULL)
										{
											if (temp_buld->getaddres() == address)
											{
												cout << "enter number of client has going to buy this apartment:" << endl;
												cin >> numClient;
												for (int t = 0; t < num_of_persons; t++)
												{
													int day, month, year;

													client* temp_client = dynamic_cast<client*>(pPersons[t]);
													if (temp_client != NULL)
													{
														if (temp_client->get_index() == numClient)
														{
															if (!((temp_buld->returnapart_by_num(numApart)->getsold() == 0) || (temp_buld->returnapart_by_num(numApart)->getprice() < temp_client->get_budgt())))
															{
																flag = 0;
																break;
															}
															else
															{
																cout << "enter day month and year of sale typy enter bettwen" << endl;
																cin >> day >> month >> year;
																temp_buld->returnapart_by_num(numApart)->setsold(true);
																temp_client->operator+(temp_buld->returnapart_by_num(numApart));
																temp_client->update_days(day, month, year);
																check_seller->operator+(temp_client);
																flag = 1;
																
															
																break;
															}
														}
													}
												}
											}
											else
											{
												flag = 0;
												cout << "there isnt address like you type at this project" << endl;
												break;
											}
										}
										if (flag == 1)
											break;
									}
								}
							}
							else
							{
								cout << "this seller man dosent work at name project you gave" << endl;
								break;
							}
						}
						if (flag == 1)
							break;
						cout << "some of your data has typing wornge" << endl;
						break;
					}
					
				}
				if (flag == 1)
					break;
				cout << "some of your data has typing wornge" << endl;
				break;
			}
			if (flag == 0)
			{
				cout << "some of your data has typing wornge" << endl;
				break;
			}
			break;
		}
		case 12:
		{
			int flag = 0;
			int* index_of_per = new int[num_of_persons];
			int arnona_min = 10000;
			for (int i = 0; i < num_of_persons; i++)
			{
				client* help = dynamic_cast<client*>(pPersons[i]);
				if (help != NULL)
				{
					if (help->getnumapart_buy() == 1)
					{
						if (help->arnona_for_apartment()[i] < arnona_min)
							arnona_min = help->arnona_for_apartment()[0];
					}
				}
			}
			for (int i = 0; i < num_of_persons; i++)
			{
				client*help = dynamic_cast<client*>(pPersons[i]);
				if (help != NULL)
				{
					if (help->getnumapart_buy() == 1)
					{
						if (help->arnona_for_apartment()[0] == arnona_min)
							help->print();
					}
				}
			}
			
			break;
		}
		case 13:
		{
			break;
		}
		default:
			break;
		}
	}

	return *this;
}


void Apartment_marketing::ShowMenu()
{
	cout << "1.Print all client have bought clasic Apartment" << endl;
	cout << "2.Add bulding" << endl;
	cout << "3.Add Project" << endl;
	cout << "4.Add seller man" << endl;
	cout << "5.Add client" << endl;
	cout << "6.Print Apartment by apartment number and addres" << endl;
	cout << "7.Print clasic Apartment with 2 belconies that doesnt sale" << endl;
	cout << "8.Print Salary of seller man by first and last name" << endl;
	cout << "9.Print data of Apartment that have right demand of client" << endl;
	cout << "10.Print Price of all roof Apartment" << endl;
	cout << "11.Price of Apartment" << endl;
	cout << "12.Print all client with lowest arnona" << endl;
	cout << "13.exit" << endl;
}
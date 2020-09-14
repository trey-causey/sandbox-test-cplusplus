/*********************************************************
Author: Trey Causey
Date: 7/2/08
Purpose: This program will sort a list of people by age.
**********************************************************/

#include<iostream>
#include<string>
#include"orderedArrayListType.h"
#include"person.h"

using namespace std;

int main()
{
	orderedArrayListType<personType> personList;
	personType person;
	string first, last;
	int age;
	bool done = false;
	char cont;

	cout<<"The program will accept a list of up to 100 names and ages of people."<<endl;
	cout<<"After the infomation has been inputed, the list will be sorted according to age."<<endl;
	do
	{
		cout<<"Enter a first name: ";
		cin>>first;
		cout<<endl;
		cout<<"Enter a last name: ";
		cin>>last;
		cout<<endl;
		cout<<"Enter an age: ";
		cin>>age;
		cout<<endl;
		system("pause");
		person.setName(first, last);
		person.setAge(age);
		personList.insert(person);
		cout<<"Would you like to continue entering into list? \n"
			<<"Press \"y\" if so or \"n\" if not:";
		cin>>cont;
		if(cont == 'y')
			continue;
		else if(cont == 'n')
			done = true;
		
	}// end do while
	while (done == false);

	personList.quickSort();
	personList.print();
	system("pause");

	return 0;

}
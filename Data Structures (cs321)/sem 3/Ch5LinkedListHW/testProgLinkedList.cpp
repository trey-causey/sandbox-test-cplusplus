/******************************************************
Author: Trey Causey
Date: 5/29/08
Purpose: This program satifies all requirements of programing
	exercises 2, 3, 4, 5, and all a and b components.
*****************************************************/
		
//This program tests various operation of a linked list

#include <iostream>
#include "linkedList.h"

using namespace std;

int main()
{
	linkedListType<int> list1, list2, list3;
	int num;

	cout<<"Enter numbers to form a list. End your list with -999."<<endl;
	cin>>num;

	while(num != -999)
	{
		list1.insertLast(num);
		cin>>num;
	}

	
	cout<<"Your list is: "<<list1<<endl;
	system("pause");
	cout<<"Enter the number you would like to delete: "<<endl;
	cin>>num;
	cout<<"You are about to delete: "<<num<<endl;
	system("pause");
	list1.deleteNode(num);
	cout<<"Your new list is: "<<list1<<endl;

	int choice;
	cout<<"Enter 1 if you want to delete the smallest number on the list, \n"
		<<"Enter 2 if you want to terminate the program."<<endl;
	cin>>choice;
	if(choice == 1)
	{
		list1.deleteSmallest();
		cout<<"Your new list is: "<<list1<<endl;
	}
	else
		return 0;

	cout<<"Enter the number you would like to delete all occurences of: "<<endl;
	cin>>num;
	list1.deleteAll(num);
	cout<<"The new list is: "<<list1<<endl;

	int position;
	cout<<"Enter the position of the element you would like to see: "<<endl;
	cin>>position;
	cout<<"The element in that postion is: "<<list1.getElement(position)<< "."<<endl;

	cout<<"Enter a position of an element that you would like to delete: "<<endl;
	cin>>position;
	list1.deleteElement(position);
	cout<<"The new list is: "<<list1<<endl;
	cout<<"Press 1 to split this list almost in half: "<<endl;
	cin>>choice;
	if(choice == 1)
	{
		list1.splitMid(list2);
		cout<<"Your new first list is: "<<list1<<endl;
		cout<<"Your new second list is: "<<list2<<endl;
	}
	else
		return 0;

	cout<<"To split your first list again at a given point, press 1 "<<endl;
	cin>>choice;
	if(choice == 1)
		cout<<"After which num would you like to split the list: "<<endl;
	cin>>num;
	list1.splitAt(list3, num);
	cout<<"Your new lists are: "<<endl;
	cout<<"List1: "<<list1<<endl;
	cout<<"List3: "<<list3<<endl;

	system("pause");
}
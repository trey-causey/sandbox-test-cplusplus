/*****************************************************
Author: Trey Causey
Date: 6/25/08
Purpose: This program will perform a binary search on a 
	list using a recursive version of the function.
******************************************************/
#include "orderedArrayListType.h"
#include <iostream>

int main()
{
	cout<<"This program is designed to find an item in a list"<<endl;

	cout<<"Enter the number of items you would like in the list"<<endl;

	int noOfItems; //number of elements in the list
	cin>>noOfItems;
	orderedArrayListType<int> myList(noOfItems);
	cout<<"Enter the numbers you would like in the list"<<endl;

	for(int i = 0; i < noOfItems; i++)
	{
		int num; //items in the list
		cin>>num;
		myList.insertOrd(num); //inserting the items
	}

	cout<<"Type in a number to seach the list: "<<endl;
	int searchNum;  //item to be searched for
	cin>>searchNum;
	int pos; //pos of item to be searched for
	pos = myList.recursiveBinSearch(searchNum, 0, noOfItems -1);
	cout<<searchNum<<" is in the list and is element number "<<pos + 1<<"."<<endl;
	system("pause");
	return 0;
}
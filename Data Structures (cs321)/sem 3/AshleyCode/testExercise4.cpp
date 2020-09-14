//This program tests various operation of a linked list

#include <iostream>
#include "linkedList.h"

using namespace std;

int main()
{
	linkedListType<int> list1, list2;
	int num;

	cout << "Enter integers ending with -999" << endl;
	cin >> num;


	while(num != -999)
	{
		list1.insertLast(num);
		cin >> num;
	}//end while

	cout << endl;

	cout << "List 1: " << list1 << endl<< endl;
	
	list1.splitMid(list2);

	cout << "After splitting list 1 down the middle: " << endl;
	cout << "List 1: " << list1 << endl;
	cout << "List 2: " << list2 << endl;

	system("pause");

	return 0;
}
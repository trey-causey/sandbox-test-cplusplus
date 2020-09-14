
#include <iostream>

#include "orderedArrayListType.h"

using namespace std;

void printListInfo(orderedArrayListType<int>& listInfo);

int main()
{
	orderedArrayListType<int> intList; 

	int num;

	cout<<"Enter numbers ending with -999"<<endl;
	cin>>num;

	while(num != -999)
	{
		intList.insert(num);
		cin>>num;
	}

	cout<<"The list you entered is: "<<endl;
	printListInfo(intList);

	intList.quickSort();

	cout<<"The list after sorting: "<<endl;
	printListInfo(intList);

	return 0;
}

void printListInfo(orderedArrayListType<int>& listInfo)
{
	cout<<"List: ";
	listInfo.print();

	cout<<"List Size: "<<listInfo.listSize()<<endl;
	cout<<"Max List Size: "<<listInfo.maxListSize()<<endl;

}
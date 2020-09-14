#ifndef H_OrderedListType
#define H_OrderedListType

#include <iostream>
#include "arrayListType.h"

using namespace std;

template<class elemType>
class orderedArrayListType: public arrayListType<elemType>
{
public:
	void insertOrd(const elemType&);
	
	int binarySearch(const elemType& item);

	int recursiveBinSearch(const elemType& item, int first, int last);

	orderedArrayListType(int size = 100);
};

template<class elemType>
void orderedArrayListType<elemType>::insertOrd(const elemType& item)
{
	int first = 0;
	int last = length - 1;
	int mid;

	bool found = false;

	if(length == 0)   //list is empty
    {
        list[0] = item;
        length++;
    }
	else
		if(length == maxSize)
			cerr<<"Cannot insert into a full list."<<endl;
		else
		{
			while(first <= last && !found)
			{
				mid = (first + last) / 2;

				if(list[mid] == item)
					found = true;
				else
					if(list[mid] > item)
						last = mid - 1;
					else
						first = mid + 1;
			}//end while

			if(found)
	   			cerr<<"The insert item is already in the list. "
					<<"Duplicates are not allowed.";
			else
			{
				if(list[mid] < item)
					mid++;

				insertAt(mid, item);
			}
		}
}//end insertOrd

template<class elemType> 
int orderedArrayListType<elemType>::binarySearch(const elemType& item)
{
	int first = 0;
	int last = length - 1;
	int mid;

	bool found = false;

	while(first <= last && !found)
	{
		mid = (first + last) / 2;

		if(list[mid] == item)
		   found = true;
		else
		   if(list[mid] > item)
			last = mid - 1;
		   else
			first = mid + 1;
	}

	if(found) 
   	   return mid;
	else
		return -1;
}//end binarySearch

template<class elemType>
int orderedArrayListType<elemType>::recursiveBinSearch(const elemType &item, int first, int last)
{

	int mid = (first + last) / 2;
	if(first >= last)
		return 0; 
	if(list[mid] == item)
		   return mid;
		else
		   if(list[mid] > item)
		   {
			    last = mid - 1;
				return recursiveBinSearch(item, first, last);
		   }
		   else
		   {	
			    first = mid + 1; 
				return recursiveBinSearch(item, first, last);
		   }	
} //end recursiveBinSearch

template<class elemType>
orderedArrayListType<elemType>::orderedArrayListType(int size)
   : arrayListType<elemType>(size)
{
}

#endif
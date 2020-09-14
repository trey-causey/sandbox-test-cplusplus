#ifndef H_OrderedListType
#define H_OrderedListType

#include <iostream>
#include "arrayListType.h"

using namespace std;

template<class elemType>
class orderedArrayListType: public arrayListType<elemType>
{
public:  
	void selectionSort();
	void quickSort();
	int binarySearch(const elemType& item);

	orderedArrayListType(int size = 100);

private:
	void recQuickSort(int first, int last);
	int partition(int first, int last);
	void swap(int first, int second);
	int minLocation(int first, int last);
};

template<class elemType>
void orderedArrayListType<elemType>::selectionSort()
{
	int loc, minIndex;

	for(loc = 0; loc < length; loc++)
	{
		minIndex = minLocation(loc, length - 1);
		swap(loc, minIndex);
	}
}


template<class elemType>
void orderedArrayListType<elemType>::quickSort()
{
	recQuickSort(0, length -1);
}



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
}// end binarySearch


template<class elemType>
void orderedArrayListType<elemType>::recQuickSort(int first, int last)
{
	int pivotLocation;

	if(first < last)
	{
		pivotLocation = partition(first, last);
		recQuickSort(first, pivotLocation - 1);
		recQuickSort(pivotLocation + 1, last);
	}
}


template<class elemType>
int orderedArrayListType<elemType>::partition(int first, int last)
{
	elemType pivot;

	int index, smallIndex;

	swap(first, (first + last) / 2);

	pivot = list[first];
	smallIndex = first;

	for(index = first + 1; index <= last; index++)
		if(list[index] < pivot)
		{			
			smallIndex++;
			swap(smallIndex, index);
		}

	swap(first, smallIndex);

	return smallIndex;
}


template<class elemType>
void orderedArrayListType<elemType>::swap(int first, int second)
{
	elemType temp;

	temp = list[first];
	list[first] = list[second];
	list[second] = temp;
}

template<class elemType>
orderedArrayListType<elemType>::orderedArrayListType(int size)
   : arrayListType<elemType>(size)
{
}


#endif
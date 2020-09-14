#ifndef H_OrderedListType
#define H_OrderedListType

#include <iostream>
#include "arrayListType.h"

using namespace std;

template<class elemType>
class orderedArrayListType: public arrayListType<elemType>
{
public:
	void insertionSort();
	void selectionSort();
	void heapSort();

	int binarySearch(const elemType& item);

	orderedArrayListType(int size = 100);

private:
	void heapify(int low, int high);
	void buildHeap();
	void swap(int first, int second);
	int minLocation(int first, int last);
};

template<class elemType>
void orderedArrayListType<elemType>::heapify(int low, int high)
{
   int largeIndex;

   elemType temp = list[low]; //copy the root node of the subtree

   largeIndex = 2 * low + 1;  //index of the left child

   while(largeIndex <= high)
   {
       if(largeIndex < high)
          if(list[largeIndex] < list[largeIndex + 1])
             largeIndex = largeIndex + 1; //index of the 
                                         //largest child

       if(temp > list[largeIndex]) //subtree is already in a heap
          break;
       else 
       {
          list[low] = list[largeIndex]; //move the larger child
                                        //to the root
          low = largeIndex;	//go to the subtree to 
                              //restore the heap
          largeIndex = 2 * low + 1; 
       }
   }//end while
	
   list[low] = temp; //insert temp into the tree, that is, list

} //end heapify

template<class elemType>
void orderedArrayListType<elemType>::buildHeap()
{
   int index;

   for(index = length / 2 - 1; index >= 0; index--)
  	heapify(index, length - 1);
}

template<class elemType>
void orderedArrayListType<elemType>::heapSort()
{
    int lastOutOfOrder;
    elemType temp;
	
    buildHeap();

	for(lastOutOfOrder = length - 1; lastOutOfOrder >= 0;
		                             lastOutOfOrder--)
    {
        temp = list[lastOutOfOrder];
        list[lastOutOfOrder] = list[0];
        list[0] = temp;
		heapify(0, lastOutOfOrder - 1);
    }//end for
}//end heapSort


template<class elemType>
void orderedArrayListType<elemType>::insertionSort()
{
	int unsortedIndex, location;
	elemType temp;


	for(unsortedIndex = 1; unsortedIndex < length; unsortedIndex++)
		if(list[unsortedIndex] < list[unsortedIndex - 1])
		{
			temp = list[unsortedIndex];
			location = unsortedIndex;

			do
			{
				list[location] = list[location - 1];
				location--;
			}while(location > 0 && list[location - 1] > temp);

			list[location] = temp;
		}
}

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
void orderedArrayListType<elemType>::swap(int first, int second)
{
	elemType temp;

	temp = list[first];
	list[first] = list[second];
	list[second] = temp;
}

template<class elemType>
int orderedArrayListType<elemType>::minLocation(int first, int last)
{
	int loc, minIndex;

	minIndex = first;

	for(loc = first + 1; loc <= last; loc++)
		if(list[loc] < list[minIndex])
			minIndex = loc;

	return minIndex;
}

template<class elemType>
orderedArrayListType<elemType>::orderedArrayListType(int size)
   : arrayListType<elemType>(size)
{
}


#endif
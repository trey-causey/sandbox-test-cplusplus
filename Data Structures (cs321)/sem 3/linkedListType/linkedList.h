#ifndef H_LinkedListType
#define H_LinkedListType

#include <iostream>
#include <cassert>
using namespace std;

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template<class Type>
class linkedListType
{
	friend ostream& operator<<<Type>(ostream&, const linkedListType<Type>&);

public:
    const linkedListType<Type>& operator=
          			      (const linkedListType<Type>&); 
		//Overload the assignment operator.
    void initializeList(); 
 		//Initializes the list to an empty state.
	    //Postcondition: first = NULL, last = NULL,
		//                count = 0
    bool isEmptyList();
 		//Function to determine whether the list is empty. 
		//Postcondition: Returns true if the list is empty;
		//               otherwise, returns false.

	int length();
		//Function to return the number of nodes in the 
		//list.
		//Postcondition: The value of count is returned.
    void destroyList();
 		//Function to delete all the nodes from the list.
  		//Postcondition: first = NULL, last = NULL, 
		//               count = 0
    Type front(); 
 		//Function to return the first element of the list.
 		//Precondition: The list must exist and must not be
		//empty.
  		//Postcondition: If the list is empty, then the 
 		//               program terminates; otherwise, 
	    //               the first element of the list is 
		//               returned.
    Type back(); 
       //Function to return the last element of the
       //list.
		//Precondition: The list must exist and must not
		//be empty.
		//Postcondition: If the list is empty, then the 
		//               program terminates; otherwise,
		//               the last element of the list is 
		//               returned.

	Type getElement(int elemNum);
		//Function to return the kth element of a list.
		//Precondition: The list must exist and must not be empty.
		//Postcondition: If the list is empty OR the element does 
		//				not exist, then the 
		//				program terminates; otherwise,
		//				the kth element of the list is
		//				returned.
	
	void deleteElement(int elemNum);
		//Function to delete the element in the position specified
		//				by the parameter elementPosition.
		//Precondition: The list must exists and not be empty
		//Postcondition: If the list is empty OR the position does
		//				not exist, the program terminates; otherwise,
		//				the element is deleted.
	
	void deleteSmallest();
		//Function to delete the smallest element of the 
		//list.
		//Postcondition: If the list is empty, then the 
		//				program terminates; otherwise,
		//				the smallest element of the list is 
		//				found and deleted.

	void deleteAll(const Type& deleteItem);
		//Function to delete all instances of deleteItem.
		//Postcondition: If the list is empty, then the 
		//				the program terminates; otherwise
		//				the list is searched until all instances
		//				are removed.

	bool search(const Type& searchItem);
		//Function to determine whether searchItem is in 
		//the list.
		//Postcondition: Returns true if searchItem is found
		//               in the list; otherwise, it returns
		//               false.

    void insertFirst(const Type& newItem);
		//Function to insert newItem in the list.
		//Postcondition: first points to the new list 
		//                and newItem is inserted at the
		//                beginning of the list.

    void insertLast(const Type& newItem);
		//Function to return newItem at the end of the
		//list.
	    //Postcondition: first points to the new list, 
		//                newItem is inserted at the end
		//                of the list, and last points to
		//                the last node in the list.

    void deleteNode(const Type& deleteItem);
  		//Function to delete deleteItem from the list.
 		//Postcondition: If found, the node containing 
   		//               deleteItem is deleted from the 
		//                list, first points to the first
		//                node, and last points to the last 
		//                node of the updated list. 

    void splitMid(linkedListType<Type> &sublist);
		//This operation splits the given list into two sublists of
		//almost equal size.
		//Precondition: The list must exists.
		//Postcondition: first points to the first node,
		//	and last points to the first node of the first
		//  sublist. sublist.first points to the first node,
		//  and sublist.last points to the last node of the
		//  second sublist.
	
	linkedListType(); 
   		//default constructor
 		//Initializes the list to an empty state.
 		//Postcondition: first = NULL, last = NULL, 
		//               count = 0 

    linkedListType(const linkedListType<Type>& otherList); 
         //copy constructor

    ~linkedListType();   
    	//destructor
   		//Deletes all the nodes from the list.
    	//Postcondition: The list object is destroyed. 

protected:
    int count;		//variable to store the number of 
 					//elements in the list
    nodeType<Type> *first; //pointer to the first node of 
                           //the list
    nodeType<Type> *last;  //pointer to the last node of 
                           //the list 
private:
    void copyList(const linkedListType<Type>& otherList); 
		//Function to make a copy of otherList.
		//Postcondition: A copy of otherList is created 
		//               and assigned to this list.
};

template<class Type>
bool linkedListType<Type>::isEmptyList()
{
	return(first == NULL);
}

template<class Type>
linkedListType<Type>::linkedListType() // default constructor
{
	first = NULL;
	last = NULL;
	count = 0;
}

template<class Type>
void linkedListType<Type>::destroyList()
{
	nodeType<Type> *temp;   //pointer to deallocate the memory 
							//occupied by the node
	while(first != NULL)    //while there are nodes in the list
	{
	   temp = first;        //set temp to the current node
	   first = first->link; //advance first to the next node
	   delete temp;         //deallocate memory occupied by temp
	}

	last = NULL;	//initialize last to NULL; first has already
                   //been set to NULL by the while loop
 	count = 0;
}

	
template<class Type>
void linkedListType<Type>::initializeList()
{
	destroyList(); //if the list has any nodes, delete them
}

template<class Type>
int linkedListType<Type>::length()
{
 	return count;
}  // end length

template<class Type>
Type linkedListType<Type>::front()
{   
    assert(first != NULL);
   	return first->info; //return the info of the first node	
}//end front


template<class Type>
Type linkedListType<Type>::back()
{   
	 assert(last != NULL);
   	 return last->info; //return the info of the first node	
}//end back

template<class Type>
void linkedListType<Type>::deleteElement(int elemNum)
{
	nodeType<Type> *current;
	nodeType<Type> *trailCurrent;
	int i = 0;

	if(first == NULL)
		cerr<<"The list is empty."<<endl;
	else if(elemNum > count)
		cerr<<"There are not enough elements in the list"<<endl;

	current = first;

	if(elemNum == 1)
	{	
		first = first->link;
		delete current;
	}

	while((i < count - 1) && (i < elemNum - 1))
	{
		trailCurrent = current;
		current = current->link;
		i++;
	}

	trailCurrent->link = current->link;

	delete current;

}

template<class Type>
Type linkedListType<Type>::getElement(int elemNum)
{
	nodeType<Type> *current; //pointer to traverse the list
	int i;

	current = first;
	if(first == NULL)    //Case 1; list is empty. 
		cerr<<"Can not delete from an empty list.\n";
	else
	{
		for(i = 0; i < elemNum -1; i++)
		{
			current = current->link;
		}

		return current->info;
	}
	
}

template<class Type>
void linkedListType<Type>::deleteSmallest()
{
	Type smallest;
	nodeType<Type> *current; //pointer to hold position so that compareToCurrent can compare
	nodeType<Type> *compareToCurrent; //pointer to traverse the list and compare to current

	current = first; //set current to point to the 
                     //first node in the list

	compareToCurrent = current->link; //set compareToCurrent to the
									//node ahead of current
	
	smallest = current->info;
	while(compareToCurrent != NULL)
	{
		if(current->info < compareToCurrent->info) //compare value of current to value of compareToCurrent
		{
			smallest = current->info;  //assign value of info from current to smallest
			compareToCurrent = compareToCurrent->link; //advance compareToCurrent
		}
		else 
		{
			smallest = compareToCurrent->info; //assign value of compareToCurrent to smallest
			current = compareToCurrent; //advance current
			compareToCurrent = current->link; //advance compareToCurrent
		}
			
	}
	

	deleteNode(smallest);  //pass smallest as an actual parameter to function deleteNode
}  //end deleteSmallest

template<class Type>
void linkedListType<Type>::deleteAll(const Type &deleteItem)
{
	while(search(deleteItem))  //while item exists in list
	{
		deleteNode(deleteItem);  //pass deleteItem as actual parameter to deleteNode
	}
	
}

template<class Type>
bool linkedListType<Type>::search(const Type& searchItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    bool found;

    current = first; //set current to point to the 
                     //first node in the list
    found = false;   //set found to false

    while(current != NULL && !found)		//search the list
        if(current->info == searchItem)     //the item is found
           found = true;
        else
           current = current->link; //make current point 
                                    //to the next node
     
     return found;
}//end search

template<class Type>
void linkedListType<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type> *newNode; //pointer to create the new node

	newNode = new nodeType<Type>; //create the new node

	assert(newNode != NULL);	//If unable to allocate memory, 
 								//terminate the program

	newNode->info = newItem; 	   //store the new item in the node
	newNode->link = first;        //insert newNode before first
	first = newNode;              //make first point to the 
                                 //actual first node
	count++; 			   //increment count

	if(last == NULL)   //if the list was empty, newNode is also 
                      //the last node in the list
		last = newNode;
}

template<class Type>
void linkedListType<Type>::insertLast(const Type& newItem)
{
	nodeType<Type> *newNode; //pointer to create the new node

	newNode = new nodeType<Type>; //create the new node

	assert(newNode != NULL);	//If unable to allocate memory, 
 							    //terminate the program

	newNode->info = newItem;      //store the new item in the node
	newNode->link = NULL;         //set the link field of newNode
         						//to NULL

	if(first == NULL)	//if the list is empty, newNode is 
     					//both the first and last node
	{
		first = newNode;
		last = newNode;
		count++;		//increment count
	}
	else			//the list is not empty, insert newNode after last
	{
		last->link = newNode; //insert newNode after last
		last = newNode;   //make last point to the actual last node
		count++;		//increment count
	}
}//end insertLast

template<class Type>
void linkedListType<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent; //pointer just before current
	bool found;

	if(first == NULL)    //Case 1; list is empty. 
		cerr<<"Can not delete from an empty list.\n";
	else
	{
		if(first->info == deleteItem) //Case 2 
		{
			current = first;
			first = first->link;
			count--;
			if(first == NULL)    //list has only one node
				last = NULL;
			delete current;
		}
		else  //search the list for the node with the given info
		{
			found = false;
			trailCurrent = first;   //set trailCurrent to point to
                                 //the first node
			current = first->link;  //set current to point to the 
    			   //second node
	
			while(current != NULL && !found)
			{
  				if(current->info != deleteItem) 
				{
					trailCurrent = current;
					current = current->link;
				}
				else
					found = true;
			} // end while

			if(found) //Case 3; if found, delete the node
			{
				trailCurrent->link = current->link;
				count--;

				if(last == current)      //node to be deleted was 
                                     //the last node
					last = trailCurrent;  //update the value of last

				delete current;  //delete the node from the list
			}
			else
				cout<<"Item to be deleted is not in the list."<<endl;
		} //end else
	} //end else
} //end deleteNode

template<class Type>
void linkedListType<Type>::splitMid(linkedListType<Type> &sublist)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *currentSub; //pointer to traverse the sublist
	nodeType<Type> *trailCurrentSub; //pointer to trail currentSub
	int sublistSize = (count/2);
	int i = 0;

	current = first;
	
	if(first == NULL)
		cerr<<"Empty list cannot be split.";
	else
	{
		for(i = 0; i < sublistSize; i++)
		{
			current = current->link;
		}
		
		currentSub = current->link;
		last = current;
		last->link = NULL;

		current = currentSub;
		sublist.insertLast(current->info);
		sublist.first = current;
		current = current->link

		while(currentSub != NULL)
		{
			sublist.insertLast(current->info);
			currentSub = currentSub->link;
			count--;
		}
		sublist.last = current;
		sublist.last->link = NULL;
		
			
	}
}
	//Overloading the stream insertion operator
template<class Type>
ostream& operator<<(ostream& osObject, const linkedListType<Type>& list)
{
	nodeType<Type> *current; //pointer to traverse the list

	current = list.first;   //set current so that it points to 
					   //the first node
	while(current != NULL) //while more data to print
	{
	   osObject<<current->info<<" ";
	   current = current->link;
	}

	return osObject;
}

template<class Type>
linkedListType<Type>::~linkedListType() // destructor
{
	destroyList(); 
}//end destructor


template<class Type>
void linkedListType<Type>::copyList
            	      (const linkedListType<Type>& otherList) 
{
   nodeType<Type> *newNode; //pointer to create a node
   nodeType<Type> *current; //pointer to traverse the list

   if(first != NULL)	//if the list is nonempty, make it empty
	  destroyList();

   if(otherList.first == NULL) //otherList is empty
   {
		first = NULL;
		last = NULL;
 		count = 0;
   }
   else
   {
		current = otherList.first;  //current points to the 
									//list to be copied
		count = otherList.count;

			//copy the first node
		first = new nodeType<Type>;  //create the node

 		assert(first != NULL);

		first->info = current->info; //copy the info
		first->link = NULL;  	     //set the link field of 
									 //the node to NULL
		last = first;    		     //make last point to the 
            						 //first node
		current = current->link;     //make current point to  
           							 //the next node

			//copy the remaining list
		while(current != NULL)
		{
			newNode = new nodeType<Type>;  //create a node

			assert(newNode!= NULL);

			newNode->info = current->info;	//copy the info
			newNode->link = NULL;   	    //set the link of 
                                        //newNode to NULL
			last->link = newNode; 		//attach newNode after last
			last = newNode;   			//make last point to
										//the actual last node
			current = current->link;	//make current point to
       									//the next node
		}//end while
	}//end else
}//end copyList


	//copy constructor
template<class Type>
linkedListType<Type>::linkedListType
            	      (const linkedListType<Type>& otherList) 
{
	first = NULL;

	copyList(otherList);
	
}//end copy constructor

	//overload the assignment operator
template<class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
   	 	 		(const linkedListType<Type>& otherList)
{ 
	if(this != &otherList) //avoid self-copy
		copyList(otherList);

	return *this; 
}

#endif

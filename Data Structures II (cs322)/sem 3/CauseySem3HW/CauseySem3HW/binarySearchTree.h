//Header File Binary Search Tree

#ifndef H_binarySearchTree
#define H_binarySearchTree
#include <iostream>
#include <cassert>
#include "binaryTree.h"

using namespace std;

template<class elemType>
class bSearchTreeType: public binaryTreeType<elemType>
{
public:
    bool search(const elemType& searchItem);
      //Function to determine if searchItem is in the binary 
      //search tree.
      //Postcondition: Returns true if searchItem is found in the 
      //             binary search tree; otherwise, returns false.

    void insert(const elemType& insertItem);
      //Function to insert insertItem in the binary search tree.
      //Postcondition: If no node in the binary search tree has 
      //           the same info as insertItem, a node with the 
      //           info insertItem is created and inserted in the
      //binary search tree.

    void deleteNode(const elemType& deleteItem);
      //Function to delete deleteItem from the binary search tree 
      //Postcondition: If a node with the same info as deleteItem 
      //               is found, it is deleted from the binary 
      //               search tree.

	void swapSubtrees(const elemType& parent);
	  //Function to swap the subtrees of a given node.
	  //Postcondition: The original left node becomes the right node
	  //			and the original right node becomes the left node

private:
    void deleteFromTree(nodeType<elemType>* &p);
      //Function to delete the node, to which p points, from the 
      //binary search tree.
      //Postcondition: The node to which p points is deleted
      //               from the binary search tree.
};


template<class elemType>
bool bSearchTreeType<elemType>::search(const elemType& searchItem)
{
    nodeType<elemType> *current;
    bool found = false;

    if(root == NULL)
       cerr<<"Cannot search the empty tree."<<endl;
    else
    { 
       current = root;

       while(current != NULL && !found)
       {
             if(current->info == searchItem)
                found = true;
              else
                  if(current->info > searchItem)
                     current = current->llink;
                  else
                     current = current->rlink;
       }//end while
    }//end else

    return found;
}//end search

template<class elemType>
void bSearchTreeType<elemType>::insert(const elemType& insertItem)
{
    nodeType<elemType> *current;  //pointer to traverse the tree
    nodeType<elemType> *trailCurrent; //pointer behind current
    nodeType<elemType> *newNode;  //pointer to create the node

    newNode = new nodeType<elemType>;
    assert(newNode != NULL);
    newNode->info = insertItem;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    if(root == NULL)
       root = newNode;
    else
    {
       current = root;
 
       while(current != NULL)
       {
           trailCurrent = current;

           if(current->info == insertItem)
           {
              cerr<<"The insert item is already in the list -- ";
              cerr<<"duplicates are not allowed."<<endl;
              return;
           }
           else
              if(current->info > insertItem)
                 current = current->llink;
              else
                 current = current->rlink;
       }//end while

       if(trailCurrent->info > insertItem)
          trailCurrent->llink = newNode;
       else
          trailCurrent->rlink = newNode;
   }
}//end insert



template<class elemType>
void bSearchTreeType<elemType>::deleteNode(const elemType& deleteItem)
{
	nodeType<elemType> *current;  //pointer to traverse the tree
	nodeType<elemType> *trailCurrent; //pointer behind current
	bool found = false;

	if(root == NULL)
		cerr<<"Cannot delete from the empty tree."<<endl;
	else
	{
		current = root;
		trailCurrent = root;

		while(current != NULL && !found)
		{
			if(current->info == deleteItem)
				found = true;
			else
			{
				trailCurrent = current;

				if(current->info > deleteItem)
					current = current->llink;
				else
					current = current->rlink;
			}
		}//end while

		if(current == NULL)
			cout<<"The delete item is not in the tree."<<endl;
		else
			if(found)
			{
				if(current == root)
					deleteFromTree(root);
				else
					if(trailCurrent->info > deleteItem)
						deleteFromTree(trailCurrent->llink);
					else
						deleteFromTree(trailCurrent->rlink);
			}//end if
	}
}//end deleteNode

template<class elemType>
void bSearchTreeType<elemType>::deleteFromTree
                                 (nodeType<elemType>* &p)
{
     nodeType<elemType> *current;    //pointer to traverse 
                                     //the tree
     nodeType<elemType> *trailCurrent;   //pointer behind current
     nodeType<elemType> *temp;        //pointer to delete the node

     if(p == NULL)
        cerr<<"Error: The node to be deleted is NULL."
            <<endl;
     else if(p->llink == NULL && p->rlink == NULL)
          {
             temp = p;
             p = NULL;
             delete temp;
          }
     else if(p->llink == NULL)
          {
             temp = p;
             p = temp->rlink;
             delete temp;
          }
     else if(p->rlink == NULL)
          {
             temp = p;
             p = temp->llink;
             delete temp;
          }
     else
     {
        current = p->llink;
        trailCurrent = NULL;

        while(current->rlink != NULL)
        {
            trailCurrent = current;
            current = current->rlink;
        }//end while

        p->info = current->info;

        if(trailCurrent == NULL) //current did not move; 
                                 //current == p->llink; adjust p
           p->llink = current->llink;
        else
           trailCurrent->rlink = current->llink;
 
        delete current;
     }//end else
}//end deleteFromTree

//This is the swapSubtree function
template<class elemType>
void bSearchTreeType<elemType>::swapSubtrees(const elemType& parent)
{
	nodeType<elemType> *current;
	nodeType<elemType> *temp;
	bool found = false;

	if(root == NULL)
		cerr << "Cannot swap subtrees of an empty tree!" << endl;
	else
	{
		current = root;

		while(current != NULL && !found)
		{
			if(current->info == parent)
				found = true;
			else
				if(current->info > parent)
					current = current->llink;
				else
					current = current->rlink;
		}//end while
	}//end else

	if(!found)
		cerr << parent << " is not an item in the tree." << endl;
	else
	{
		temp = current->llink;
		current->llink = current->rlink;
		current->rlink = temp;
	}//end else
}//end swapSubtrees



#endif
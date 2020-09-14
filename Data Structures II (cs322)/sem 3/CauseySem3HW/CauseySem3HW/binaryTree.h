//Header File Binary Search Tree
#ifndef H_binaryTree
#define H_binaryTree

#include <iostream>
#include "myStack.h"

using namespace std;

     //Definition of the node
template<class elemType>
struct nodeType
{
   elemType	           info;
   nodeType<elemType>  *llink;
   nodeType<elemType>  *rlink;
};

    //Definition of the class
template <class elemType>
class binaryTreeType
{
public:
    const binaryTreeType<elemType>& operator=
                 (const binaryTreeType<elemType>&); 
      //Overload the assignment operator.
    bool isEmpty();
      //Function to determine if the binary tree is empty.
      //Postcondition: Returns true if the binary tree is empty;
      //               otherwise, returns false.
    void inorderTraversal();
      //Function to do an inorder traversal of the binary tree.
      //Postcondition: The nodes of the binary tree are output
      //               in the inorder sequence.
    void preorderTraversal();
      //Function to do a preorder traversal of the binary tree.
      //Postcondition: The nodes of the binary tree are output
      //               in the preorder sequence.
    void postorderTraversal();
      //Function to do a postorder traversal of the binary tree.
      //Postcondition: The nodes of the binary tree are output
      //               in the postorder sequence.

    int treeHeight();
      //Function to deteremine the height of the binary tree.
      //Postcondition: The height of the binary tree is returned.
    int treeNodeCount();
      //Function to determine the number of nodes in the 
      //binary tree.
      //Postcondition: The number of nodes in the binary tree
      //               is returned.
    int treeLeavesCount();
      //Function to determine the number of leaves in the 
      //binary tree.
      //Postcondition: The number of leaves in the binary tree
      //               is returned.
    void destroyTree();
      //Deallocates the memory space occupied by the binary tree.
      //Postcondition: root = NULL;

	void nonRecursiveInTraversal();
	  //Function to do an inorder nonRecursive traversal of the binary tree.
      //Postcondition: The nodes of the binary tree are output
      //               in the inorder sequence.
	void nonRecursivePreTraversal();
	  //Function to do an preorder nonRecursive traversal of the binary tree.
      //Postcondition: The nodes of the binary tree are output
      //               in the preorder sequence.
	void nonRecursivePostTraversal();
      //Function to do an postorder nonRecursive traversal of the binary tree.
      //Postcondition: The nodes of the binary tree are output
      //               in the postorder sequence.
    binaryTreeType(const binaryTreeType<elemType>& otherTree); 
      //copy constructor

    binaryTreeType();   
      //default constructor

    ~binaryTreeType();   
      //destructor

protected:
    nodeType<elemType> *root;

private:
    void copyTree(nodeType<elemType>* &copiedTreeRoot,
                  nodeType<elemType>* otherTreeRoot);
      //Function to make a copy of the binary tree to 
      //which otherTreeRoot points. 
      //Postcondition: The pointer copiedTreeRoot points to
      //               the root of the copied binary tree.

    void destroy(nodeType<elemType>* &p);
      //Function to destroy the binary tree to which p points. 
      //Postcondition: The nodes of the binary tree to which
      //               p points are deallocated.
      //               p = NULL.

    void inorder(nodeType<elemType> *p);
      //Function to do an inorder traversal of the binary
      //tree to which p points.  
      //Postcondition: The nodes of the binary tree to which p
      //               points are output in the inorder sequence.
    void preorder(nodeType<elemType> *p);
      //Function to do a preorder traversal of the binary
      //tree to which p points.  
      //Postcondition: The nodes of the binary tree to which p
      //               points are output in the preorder sequence.
    void postorder(nodeType<elemType> *p);
      //Function to do a postorder traversal of the binary
      //tree to which p points.  
      //Postcondition: The nodes of the binary tree to which p
      //               points are output in the postorder sequence.

    int height(nodeType<elemType> *p);
      //Function to determine the height of the binary tree
      //to which p points. 
      //Postcondition: The height of the binary tree to which p
      //               points is returned.

    int max(int x, int y);
      //Function to determine the larger of x and y.
      //Postcondition: The larger of x and y is returned.

    int nodeCount(nodeType<elemType> *p);
      //Function to determine the number of nodes in the binary 
      //tree to which p points. 
      //Postcondition: The number of nodes in the binary tree
      //               to which p points is returned.

    int leavesCount(nodeType<elemType> *p);
      //Function to determine the number of leaves in the binary 
      //tree to which p points.
      //Postcondition: The number of nodes in the binary tree
      //               to which p points is returned.
};


	//Definition of member functions

template<class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
	root = NULL;
}

template<class elemType>
bool binaryTreeType<elemType>::isEmpty()
{
	return (root == NULL);
}

template<class elemType>
void binaryTreeType<elemType>::inorderTraversal()
{
	inorder(root);
}

template<class elemType>
void binaryTreeType<elemType>::preorderTraversal()
{
	preorder(root);
}

template<class elemType>
void binaryTreeType<elemType>::postorderTraversal()
{
	postorder(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeHeight()
{
	return height(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeNodeCount()
{
	return nodeCount(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeLeavesCount()
{
	return leavesCount(root);
}

template <class elemType>
void  binaryTreeType<elemType>::copyTree
                      (nodeType<elemType>* &copiedTreeRoot,
		               nodeType<elemType>* otherTreeRoot)
{
	if(otherTreeRoot == NULL)
		copiedTreeRoot = NULL;
	else
	{
		copiedTreeRoot = new nodeType<elemType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
		copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
	}
} //end copyTree

template<class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType> *p)
{
	if(p != NULL)
	{
		
			
			inorder(p->llink);
			cout<<p->info<<" ";
			inorder(p->rlink);
		
	}
}

template<class elemType>
void binaryTreeType<elemType>::preorder(nodeType<elemType> *p)
{
	if(p != NULL)
	{
		cout<<p->info<<" ";
		preorder(p->llink);
		preorder(p->rlink);
	}
}

template<class elemType>
void binaryTreeType<elemType>::postorder(nodeType<elemType> *p)
{
	if(p != NULL)
	{
		postorder(p->llink);
		postorder(p->rlink);
		cout<<p->info<<" ";
	}		
}

   //Overload the assignment operator
template<class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::
           operator=(const binaryTreeType<elemType>& otherTree)
{ 
     
	if(this != &otherTree) //avoid self-copy
	{
		if(root != NULL)  //if the binary tree is not empty, 
			              //destroy the binary tree
			destroy(root);

		if(otherTree.root == NULL) //otherTree is empty
			root = NULL;
		else
			copyTree(root, otherTree.root);
	}//end else

   return *this; 
}

template <class elemType>
void  binaryTreeType<elemType>::destroy(nodeType<elemType>* &p)
{
	if(p != NULL)
	{
		destroy(p->llink);
		destroy(p->rlink);
		delete p;
		p = NULL;
	}
}

template <class elemType>
void  binaryTreeType<elemType>::destroyTree()
{
	destroy(root);
}

	//copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType
              (const binaryTreeType<elemType>& otherTree)
{
	if(otherTree.root == NULL) //otherTree is empty
		root = NULL;
	else
		copyTree(root, otherTree.root);
}

template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
	destroy(root);
}

template<class elemType>
int binaryTreeType<elemType>::height(nodeType<elemType> *p)
{
	if(p == NULL)
		return 0;
	else
		return 1 + max(height(p->llink), height(p->rlink));
}

template<class elemType>
int binaryTreeType<elemType>::max(int x, int y)
{
	if(x >= y)
		return x;
	else
		return y;
}

template<class elemType>
int binaryTreeType<elemType>::nodeCount(nodeType<elemType> *p)
{
	cout<<"Write the definition of the function nodeCount"
		<<endl;

	return 0;
}

//This is the leavesCount function
template<class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType> *p)
{
	/*cout<<"Write the definition of the function leavesCount"
		<<endl;

	return 0; */

	int noOfLeaves = 0;
	if(p->llink == NULL && p->rlink == NULL)
		//noOfLeaves += 1;
		return 1;
	else
	{
		if(p->llink != NULL)
		noOfLeaves += leavesCount(p->llink);
	    if(p->rlink != NULL)
		noOfLeaves += leavesCount(p->rlink);
	}
	return noOfLeaves;

}

//NonRecursive Traversal algorithms

template <class elemType>
void binaryTreeType<elemType>::nonRecursiveInTraversal()
{
	stackType<nodeType<elemType>* > stack;
	nodeType<elemType> *current;
	current = root;

	while((current != NULL) || (!stack.isEmptyStack()))
   		if (current != NULL)
 		{
			stack.push(current);
			current = current->llink;
		}
		else
  		{
			current = stack.top();
			stack.pop();
			cout<<current->info<<" ";
			current = current->rlink;
		}

	cout<<endl;
}

template <class elemType>
void binaryTreeType<elemType>::nonRecursivePreTraversal()
{

	stackType<nodeType<elemType>*> stack;
	nodeType<elemType> *current;

	current = root;

	while((current != NULL) || (!stack.isEmptyStack()))
		if(current != NULL)
		{
			cout<<current->info<<" ";
			stack.push(current);
			current = current->llink;
		}
		else
		{
			current = stack.top();
			stack.pop();
			current = current->rlink;
		}

	cout<<endl;
}

//This function still needs work, I folowed the book algorithm pretty well
//and through multiple changes, it never worked right
template <class elemType>
void binaryTreeType<elemType>::nonRecursivePostTraversal()
{
	
	stackType<nodeType<elemType>*> stack;
	nodeType<elemType> *current;
	stackType<int> v;
	v.push(0);

	current = root;
	//v = 0;

	if(current == NULL)
		cerr<<"Cannot traverse an empty tree";
	if(current !=NULL)
	{
		stack.push(current);
		v.push(1);
		current = current->llink;
		
		while(!stack.isEmptyStack())
		{
			if(current != NULL && v.top() == 0)
			{
				stack.push(current);
				v.push(1);
				current = current->llink;
			} //end if
			else
			{
				current = stack.top();
				stack.pop();
				v.pop();
				if(v.top() == 1)
				{
					stack.push(current);
					v.push(2);
					current = current->rlink;
					//v.push(0);

				} //end if
				else
					cout<<current->info<<" ";
			} //end else
			
		} //end while
	} //end else
} //end nonRecursivePostTraversal

#endif
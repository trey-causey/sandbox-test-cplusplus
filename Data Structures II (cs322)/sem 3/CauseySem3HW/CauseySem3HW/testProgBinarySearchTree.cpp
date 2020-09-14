/******************************************************
Author: Trey Causey
Date: 7/9/08
Purpose: This program creates and traverses a binary tree
	It performs a leaf count and also can swap subtress
	It also is set up to do a nonrecursive postorder traversel
*********************************************************/
#include <iostream>
#include "binarySearchTree.h"
#include <cmath>

using namespace std;

int main()
{
	int nodesYouWant;
	int noOfLeaves;
	int num;
	int value;
	bSearchTreeType<int> binNodeList;

	cout<<"Enter the number of nodes you want:"<<endl;
	cin>>nodesYouWant;
	for(int i = 0; i<nodesYouWant; i++)
	{
		num = rand();
		binNodeList.insert(num);
		cout << num<<endl;;
		
	}
	cout<<"The node list using the recursive post-order traversal is: "<<endl;
	binNodeList.postorderTraversal();
	noOfLeaves = binNodeList.treeLeavesCount();
	cout<<endl;
	cout<<"The number of leaves in this tree are " <<noOfLeaves;
	cout<<endl;
	cout<<"The node list using the nonrecursive post-order traversal is: "<<endl;
	binNodeList.nonRecursivePostTraversal();
	cout<<"Enter a value which node you would like the subtrees swapped at: "<<endl;
	cin>>value;
	binNodeList.swapSubtrees(value);
	cout<<"The post-order traversel after the subtree swap is: "<<endl;
	binNodeList.postorderTraversal();
	system("pause");
	return 0;
}
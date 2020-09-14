 /**************************************************************
 Author: Trey Causey
 Date: 7/30/08
 Purpose: This program is designed to find the minimal spanning tree 
	using Kruskal's Algorithm. It works, yeah!!!!!!!!!!!!!!!!!
*****************************************************************/

#include <iostream>
#include "minimalSpanTreeType.h"

using namespace std;

int main()
{
	msTreeType<int, 50> spanTree;

	cout<<"******* Using Kruskal's Algorithm *********"<<endl;
	
	spanTree.createSpanningGraph(); //using provided Spanning Graph Creation Function
	//spanTree.prim2(0);
	//spanTree.printTreeAndWeight();
	spanTree.kruskal1();  //call to my Kruskal Function
	system("pause");
	
	return 0;
}
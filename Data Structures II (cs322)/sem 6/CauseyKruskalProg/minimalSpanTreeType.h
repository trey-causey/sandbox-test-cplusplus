#ifndef H_msTree
#define H_msTree

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "graphType.h"
#include "edgeContainer.h"
#include "setofsets.h"

using namespace std;

template<class vType, int size>
class msTreeType: public graphType<vType, size>
{
public:
    void createSpanningGraph();
      //Function to create the graph and the weight matrix.
    void minimalSpanning(vType sVertex);
      //Function to create the edges of the minimal
      //spanning tree. The weight of the edges is also
      //saved in the array edgeWeights.
    void printTreeAndWeight();
      //Function to output the edges and the weight of the 
      //minimal spanning tree.

    void prim2(vType sVertex);
	  //This function creates the edges of the minimal
	  //spanning tree. The weight of the edges is also
	  //saved in the array edgeWeights

	void kruskal1();
	  //This function creates the edges of the minimal spanning
	  //tree. 

protected:
    vType source;
    double weights[size][size];
    int edges[size];
    double edgeWeights[size];
	edgeContainer eList[625]; //array of edgeContainer objects
};

template <class vType, int size>
void msTreeType<vType, size>::createSpanningGraph()
{
	ifstream infile;
	char fileName[50];

	int index;
	vType vertex;
	vType adjacentVertex;

	cout<<"Enter input file name: ";
	cin>>fileName;
	cout<<endl;

	infile.open(fileName);

	if(!infile)
	{
		cout<<"Cannot open input file"<<endl;
		return;
	}

	infile>>gSize;

	for(index = 0; index < gSize; index++)
	{
		infile>>vertex;
		infile>>adjacentVertex;
		while(adjacentVertex != -999)
		{
			graph[vertex].insertLast(adjacentVertex);
			infile>>adjacentVertex;
		} //end while
	} //end for

	for(int i = 0; i < gSize; i++)
		for(int j = 0; j < gSize; j++)
			weights[i][j] = infinity;

	double weight;

	infile>>vertex;
	while(infile)
	{
		infile>>adjacentVertex;
		while(adjacentVertex != -999)
		{
			infile>>weight;
			weights[vertex][adjacentVertex] = weight;
			infile>>adjacentVertex;
		}
		infile>>vertex;
	}

	infile.close();
} //createWeightedGraph

template<class vType, int size>
void msTreeType<vType, size>::minimalSpanning(vType sVertex)
{
    int i,j,k;
    vType startVertex, endVertex;
    double minWeight;

    source = sVertex;

    bool mstv[size];

    for(j = 0; j < gSize; j++)
    {
        mstv[j] = false;
        edges[j] = source;
        edgeWeights[j] = weights[source][j];
    }

    mstv[source] = true;
    edgeWeights[source] = 0;

    for(i = 0; i < gSize - 1; i++)
    {
        minWeight = infinity;

        for(j = 0; j < gSize; j++)
            if(mstv[j])
               for(k = 0; k < gSize; k++)
                   if(!mstv[k] && weights[j][k] < minWeight)
                   {
                      endVertex = k;
                      startVertex = j;
                      minWeight = weights[j][k];
                   }
        mstv[endVertex] = true;
        edges[endVertex] = startVertex;
        edgeWeights[endVertex] = minWeight;
    } //end for
} //end minimalSpanning

template<class vType, int size>
void msTreeType<vType, size>::printTreeAndWeight()
{
    double treeWeight = 0;

    cout<<fixed<<showpoint<<setprecision(2);

    cout<<"Source Vertex: "<<source<<endl;
    cout<<"Edges    Weight"<<endl;

    for(int j = 0; j < gSize; j++)
    {
        if(edges[j] != j)
        {
           treeWeight = treeWeight + edgeWeights[j];
           cout<<"("<<edges[j]<<", "<<j<<")    "
               <<edgeWeights[j]<<endl;
        }
    }

    cout<<endl;
    cout<<"Tree Weight: "<<treeWeight<<endl;
} //end printTreeAndWeight


template <class vType, int size>
void msTreeType<vType, size>::prim2(vType sVertex)
{
	int i,j,k;

	double minWeight;

	source = sVertex;

	bool visited[size];

	for(j = 0; j < gSize; j++)
	{
		visited[j] = false;
		edges[j] = source;
		edgeWeights[j] = weights[source][j];
	}

	visited[source] = true;
	edgeWeights[source] = 0;

	for(i = 0; i < gSize; i++)
	{
		minWeight = infinity;
		
		k = -1;
		for(j = 0; j < gSize; j++)
			if(!visited[j] &&  edgeWeights[j] < minWeight)
			{
				k = j;
				minWeight = edgeWeights[j];
			}
		
		if(k != source && k != -1)
		{
			visited[k] = true;	
	
			for(j = 0; j < gSize; j++)
				if(!visited[j])
					if(weights[k][j] < edgeWeights[j])
					{
						edges[j] = k;
						edgeWeights[j] = weights[k][j];
					}
		}
	} //end for
} //end prim2

template <class vType, int size>
void msTreeType<vType, size>::kruskal1()
{
	int ind = 0;
	int acceptedIndex = 0; //index for accepted edges

	for(int vertex = 0; vertex < gSize; vertex++)
	{
		for(int adjacentVertex = 0; adjacentVertex < gSize; adjacentVertex++)
		{
			if(weights[vertex][adjacentVertex] != infinity)
			{
			eList[ind].setData(vertex, adjacentVertex, weights[vertex] [adjacentVertex]);
			ind++;
			} //end if
		}//end for
	}//end for
	
	cout<<"Unsorted List: "<<endl;
	for(int i = 0; i < ind; i++)
		eList[i].print();
	sort(eList, eList + ind);
	cout<<"Sorted List: "<<endl;
	for(int j = 0; j < ind; j++)
		eList[j].print();

	setofsets set(gSize); //object to hold sets

	cout<<"Accepted Edges For Kruskal's Algorithm: "<<endl;

	while(acceptedIndex < ind)
	{
		if(set.find(eList[acceptedIndex].getX()) != set.find(eList[acceptedIndex].getY()))
		{
			set.Union(eList[acceptedIndex].getX(), eList[acceptedIndex].getY());

			eList[acceptedIndex].print();
		
		}//end if

		acceptedIndex++;
	}//end while
}//end Kruskal1


#endif
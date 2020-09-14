#ifndef H_setofsets
#define H_setofsets

#include <iostream>
#include <cassert>
using namespace std;


class setofsets
{

public:
    setofsets::setofsets(int n);
    setofsets::~setofsets();
    void setofsets::Union(int x, int y);
    int setofsets::find(int x);
    int setofsets::num_sets();

private:
    int nsets;
    int *parents;
};

int setofsets::num_sets()
{
	return nsets;
}

setofsets::setofsets(int n)
{
	nsets = n;
	parents = new int[n];
	for( int i = 0 ; i<n ; i++ )
		parents[i] = i;
}

setofsets::~setofsets()
{
	delete parents;
}

int setofsets::find(int x)
{
	int y;

	y = x;
	while (parents[y] != y)
		y = parents[y];

	parents[x] = y;

	return y;
}

void setofsets::Union(int x, int y)
{
	int xx, yy;

	xx = find(x);
	yy = find(y);
	if (xx != yy) {
		parents[yy] = xx;
		nsets--;
	}
}

#endif

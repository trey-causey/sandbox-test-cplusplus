#include <cstdlib>
#include <iostream>

using namespace std;
class edgeContainer
{
public:

	bool operator<(const edgeContainer&);
	bool operator>(const edgeContainer&);
	bool operator==(const edgeContainer&);
    
	void print() const;
		
    void setData(int inptx, int inpty, double inptweight);
		
    int getX();
		
	int getY();

	double getWeight();

    edgeContainer(int inptx = 0, int inpty = 0, double inptweight = 0.0);
		
 private:
    int x; 
    int y;  
	double weight;
};

bool edgeContainer::operator<(const edgeContainer& otherObject)
{
	if (weight < otherObject.weight)
		return true;
	else
		return false;
}

bool edgeContainer::operator>(const edgeContainer& otherObject)
{
	if (weight >otherObject.weight)
		return true;
	else
		return false;
}

bool edgeContainer::operator==(const edgeContainer& otherObject)
{
	if (weight == otherObject.weight)
		return true;
	else
		return false;
}

void edgeContainer::print() const
{
	cout<<"("<<x<<","<<y<<")\t"<<weight<<endl;
}

void edgeContainer::setData(int inptx, int inpty, double inptweight)
{
	x = inptx;
	y = inpty;
	weight = inptweight;
}

int edgeContainer::getX()
{
	return x;
}

int edgeContainer::getY()
{
	return y;
}

double edgeContainer::getWeight()
{
	return weight;
}

//constructor 
edgeContainer::edgeContainer(int inptx, int inpty, double inptweight)
{ 
	x = inptx;
	y = inpty;
	weight = inptweight;
}



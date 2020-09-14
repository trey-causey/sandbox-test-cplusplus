/*********************************************************
Author: Trey Causey
Date: 5/22/08
Purpose: ***This will multiply polinomials also***
**********************************************************/
//Test program: Polynomial Operations

#include <iostream>

#include "polynomialType.h"

using namespace std;

int main()
{
	polynomialType p(2);			//Line 1
	polynomialType q(3);			//Line 2
	polynomialType t;				//Line 3
	polynomialType multi;
	cin>>p;							//Line 4
	cout<<endl<<"Line 5: p(x): "<<p
	   <<endl;						//Line 5

	cout<<"Line 6: p(5): "<<p(5)
	   <<endl<<endl;				//Line 6
	
	cin>>q;							//Line 7
	cout<<endl<<"Line 8: q(x): "<<q
	   <<endl<<endl;				//Line 8

	t = p + q;						//Line 9

	cout<<"Line 10: p(x) + q(x): "
	   <<t<<endl;					//Line 10
	
	cout<<"Line 11: p(x) - q(x): "
	   <<p - q<<endl;				//Line 11

	multi = p * q;
	cout<<"Line x: p(x) * q(x): "
		<<multi<<endl;

	system("pause");
	return 0;
}

/*************************************************************
Author: Trey Causey
Date: 6/2/08
Purpose: This program will determine the square root
	of a positive real number using the Newton Method.
	The information will include: "x" = a positive real number;
					& "epsilon" = the tolerance of the solution;
***************************************************************/
#include<cmath>
#include<iostream>

using namespace std;

long double getSquare(long double x, long double epsilon, long double approximation);

int main()
{
	long double realNumber;
	long double precision;
	long double approximation;
	
	cout<<"This is a program designed to determine the square "
		<<"root of a real number."<<endl;
	cout<<"Please enter a positive real number and press enter: ";
	cin>>realNumber;
	while(realNumber < 0)
	{
		cout<<"That number is negative and unacceptable for input. "
			<<"Please re-enter a positive real number and press enter: "<<endl;
	}
	approximation = realNumber;
	cout<<"Please enter in a tolerance that you would like \n"
		<<"the square root to be accurate to: "<<endl;
	cin>>precision;
	while(precision < 0)
	{
		cout<<"This number must be positive, please re-enter: "<<endl;
	}

	cout<<"The square root of "<<realNumber<<" to the tolerance of "
		<<precision<<" is "<<getSquare(realNumber, precision, approximation)<<endl;
	system("pause");
	return 0;

}

long double getSquare(long double x, long double epsilon, long double a)
{
	if(abs(a * a - x) <= epsilon)
		return a;
	else
	{
		
		a = abs((a * a + x)/(2 * a));
		return getSquare(x, epsilon, a);
	}
}
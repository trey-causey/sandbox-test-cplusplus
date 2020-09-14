#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int sum;
int solution;
int result;
	
int main()
{
	char romanNum[100];	
	
	cout << "Please enter a Roman Numeral" << endl;
	
	cin >> romanNum;	
	
	int length = strlen(romanNum);	
	int number = 0;	
	int counter = 0;	
	
		for (counter = length; counter >= 0; counter--)	
		{		
			if (romanNum[counter] == 'M')			
				number = 1000;		
			else if (romanNum[counter] == 'D')			
				number = 500;		
			else if (romanNum[counter] == 'C')			
				number = 100;		
			else if (romanNum[counter] == 'L')			
				number = 50;		
			else if (romanNum[counter] == 'X')			
				number = 10;		
			else if (romanNum[counter] == 'V')			
				number = 5;		
			else if (romanNum[counter] == 'I')			
				number = 1;		
			else			
				number = 0;		
			
			sum = sum + number;
		}	
		
		
		cout << "The answer is: " << sum << endl;
		system("pause");
		return 0;
}

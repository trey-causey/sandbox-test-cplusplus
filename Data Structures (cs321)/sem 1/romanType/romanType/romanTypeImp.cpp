/*************************************************
File: romanTypeImp.cpp; C++ implimentation file for Roman Numeral Conversion Program
Author: Trey Causey
Date: 5/17/08
Purpose: Contains  of the class romanType
*************************************************/

#include <iostream>
#include "romanType.h"

using namespace std;

int romanType::convertToDecimal(char numeral, char decimal) {

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
}
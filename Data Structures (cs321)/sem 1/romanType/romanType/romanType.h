/*************************************************
File: romanType.h; C++ header file for Roman Numeral Conversion Program
Author: Trey Causey
Date: 5/17/08
Purpose: Contains members of the class romanType
*************************************************/

class romanType {
public:
	int convertToDecimal(char numeral, char decimal);
	//function to convert roman numeral to decimal and return it
	//post-condition: The function checks to see if the roman numeral input 
	//	is valid and returns the decimal if so
	void storeNumeral(char numeral);
	//function to store the numeral
	void storeDecimal(char decimal);
	//function to store the decimal
private:
	char numeral;
	char decimal;
};
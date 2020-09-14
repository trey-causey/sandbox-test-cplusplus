
#include <string>
using namespace std;

class personType
{
public:
    void print() const;
		//Function to output the first name and last name and age
		//in the form firstName lastName ageName;
  
    void setName(string first, string last);
		//Function to set firstName and lastName according to 
 		//the parameters
		//Postcondition: firstName = first; lastName = last

    void getName(string& first, string& last);
		//Function to return firstName and lastName via the 
		//parameters
		//Postcondition: first = firstName; last = lastName

	void setAge(int age);
		//Function to set ageNumber according to the parameters
		//Postcondition: ageNumber = age;

	void getAge(int& age);
		//Function to return ageNumber via the parameters
		//Postcondition: age = ageNumber;

    personType(string first = "", string last = "", int age = 0);
		//Constructor
		//Set firstName and lastName according to the parameters
 		//The default values of the parameters are empty strings
 		//Postcondition: firstName = first; lastName = last; ageNumber = age;

		//overload the relational operators
	bool operator==(const personType& right) const;
	bool operator!=(const personType& right) const;
	bool operator<=(const personType& right) const;
	bool operator<(const personType& right) const;
	bool operator>=(const personType& right) const;
	bool operator>(const personType& right) const;

 private:
    string firstName; //stores the first name
    string lastName;  //stores the last name
	int ageNumber; //stores the age 
};

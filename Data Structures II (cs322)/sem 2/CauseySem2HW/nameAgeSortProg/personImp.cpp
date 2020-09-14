#include <iostream>
#include "person.h"

using namespace std;


void personType::print() const
{
	cout<<firstName<<" "<<lastName<<" "<<ageNumber;
}

void personType::setName(string first, string last)
{
	firstName = first;
	lastName = last;
}

void personType::getName(string& first, string& last)
{
	first = firstName;
	last = lastName;
}

void personType::setAge(int age)
{
	ageNumber = age;
}

void personType::getAge(int &age)
{
	age = ageNumber;
}

//constructor 
personType::personType(string first, string last, int age) 

{ 
	firstName = first;
	lastName = last;
	ageNumber = age;
}

bool personType::operator ==(const personType &right) const
{
	return(ageNumber == right.ageNumber);
}

bool personType::operator !=(const personType &right) const
{
	return(ageNumber != right.ageNumber);
}

bool personType::operator <=(const personType &right) const
{
	return(ageNumber <= right.ageNumber);
}

bool personType::operator <(const personType &right) const
{
	return(ageNumber < right.ageNumber);
}

bool personType::operator >=(const personType &right) const
{
	return(ageNumber >= right.ageNumber);
}

bool personType::operator >(const personType &right) const
{
	return(ageNumber > right.ageNumber);
}
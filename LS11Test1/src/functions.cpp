//
// Created by TJC on 9/12/2020.
//
#include <string>

int add(int x, int y)
{
  return x + y;
} //end add()

int multiply(int d1, int d2)
{
  return d1 * d2;
} //end multiply()

bool is_ten(int number)
{
  return (number == 10);
} //end is_ten()

bool is_leap_year(int year)
{
  return (year%4 == 0);
} //end is_leap_year()

std::string testFunction(const std::string& s)
{
  return s;
}
#include <iostream>
#include <cmath>

bool isNumPalindrome(int);
using namespace std;

int main()
{
 //Number to be entered by user
 int Number;
 //Character for continuing program
 char MoreNumbers = 'y';
 //Boolean for outputing to user
 bool TrueFalse;

 //Loop for getting numbers from user
 //allowing for both lowercase and uppercase Y
 while ((MoreNumbers == 'y') || (MoreNumbers == 'Y'))
 {
  //Get input from user
  cout << "Enter the number you want evaluated" << endl;
  cin >> Number;
  TrueFalse = isNumPalindrome(Number);
  if (TrueFalse)
   cout << Number << " is a palindrome" << endl;
  else
   cout << Number << " is not a palindrome" << endl;
  cout << "Do you have more numbers to test" << endl;
  cout << "(Y/N)";
  cin >> MoreNumbers;
 } //End While

 return(0);
}

bool isNumPalindrome(int num)
{
 int pwr = 0;
 
 if (num < 10)
  return true;
 else
 {
  while (num / static_cast<int>(pow(10.0,pwr)) >= 10)
   pwr++;
  while (num >= 10)
  {
   if ((num / static_cast<int>(pow(10.0, pwr))) != (num % 10))
    return false;
   else
   {
    num = num % static_cast<int>(pow(10.0, pwr));
    num = num / 10;
    pwr = pwr - 2;
   }
  }//end while

  return true;
 }//end else
}

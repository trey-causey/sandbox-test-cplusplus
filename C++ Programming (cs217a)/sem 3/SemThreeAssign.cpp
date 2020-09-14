// This program checks a number to see if it is a palindrome
#include <iostream>
#include <math.h>

using namespace std;

const int SENTENAL = -999; // program exit

bool isNumPalindrome(int num); //loop control
int num;

int main() //main function
{
    cout << "Enter a non-negative number to find out if it is a Palindrome" << endl;
    cout << "Enter -999 to exit" << endl;
    cin >> num;
    
    while(num != -999)
    {
              if(isNumPalindrome(num)==true)
              {
                 cout << num << "is a palindrome" << endl;
                 cout << "Enter another number or -999 to exit" << endl;
                 cin >> num;                 
              }
              else
              {   
                 cout << num << "is not a palindrome" << endl;
                 cout << "Enter another number or -999 to exit" << endl;
                 cin >> num;
              }
               
    }
    return 0;
}

bool isNumPalindrome(int num) //palindrome function
{
     int pwr = 0;
     
     if(num < 10)
        return true;
     else
     {
         
         while(num / static_cast<int>(pow(10, pwr)) >= 10)
            pwr++;
            while(num >= 10)
            {
                      int tenTopwr = static_cast<int>(pow(10, pwr));
                      
                      if((num / tenTopwr) != (num % 10))
                         return false;
                      else
                      {
                          num = num % tenTopwr;
                          num = num / 10;
                          pwr = pwr - 2;
                      }
            }
            return true;
     }
}// end of code
     
                          
    
                 
                 

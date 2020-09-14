//Palindrome Programming Exercise

#include<iostream>
#include<math.h>

using namespace std;

const int SENTINEL = -999;

bool isNumPalindrome(int num);

int main()
{
    int num;
        
    cout << "This program determines whether a number"
         << " is a Palindrome number." << endl;
    cout << "Please enter an integer or enter"
         << " -999 to terminate the program." << endl;
    cin >> num;
    
    while (num != SENTINEL)
    {    
        if (isNumPalindrome(num) == true)
        {   
           cout << num << " is a Palindrome number." << endl
                 << "Please enter another integer or enter -999 to "
                 << "terminate the program." << endl;
           cin >>num;
           }
        else
        {
            cout << num << "is not a Palindrome number." << endl
                 << "Please enter another integer or enter -999 to "
                 << "terminate the program." << endl;
            cin >> num;
        }   
    }
    return 0;
}

bool isNumPalindrome(int num)
{
     int pwr = 0;
     int tenTopwr;
     
     if (num < 10)
        return true;
     else
     {
        while (num / static_cast<int>(pow(10, pwr)) >= 10)
           {
           pwr++;
           }
           while (num >= 10)
           {
                 tenTopwr = static_cast<int>(pow(10, pwr));
           
                 if ((num / tenTopwr) != (num % 10))
                    return false;
                 else
                 {
                     num = num % tenTopwr;
                     num = num / 10;
                     pwr = pwr - 2;
                 }
           }//end while
     return true;
    }//end else
}

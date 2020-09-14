// Program to calculate charges for minutes used
#include <iostream>
#include <iomanip>

using namespace std;

const double CONNECT_FEE = 1.99;
const double FIRST_THREE_MINUTES = 2.00;
const double EACH_ADD_MINUTE = 0.45;

int main()
{
int minutes;
double amountDue;

cout << fixed << showpoint << setprecision(2);
cout << "Enter the number of minutes call lasted: ";
cin >> minutes;
cout << endl;

if (minutes > 3)
amountDue = CONNECT_FEE + FIRST_THREE_MINUTES  // over three minutes
+ (minutes - 3) * EACH_ADD_MINUTE;
else if (minutes > 0 && minutes <= 3)  // between zero and three minutes
amountDue = CONNECT_FEE + FIRST_THREE_MINUTES;
else 
cout << "No charge\n";  // zero or less minutes

cout << "Length of call: " << minutes << " " << "Minutes";
cout << endl;
cout << "Amount Due: $" << amountDue;
cout << endl;
system("pause");

return 0;
}// end program     

//Chapter 4 Programming Exercise 4

#include <iostream>
#include <iomanip>

using namespace std;

const double connectionCharge = 1.99;
const double chargeFirstThreeMinutes = 2.00;
const double perMinuteCharges = 0.45;

int main()
{
 int noOfMinutes;
 double amountDue;

 cout << fixed << showpoint << setprecision(2);

 cout << "Enter number of minutes service used: ";
 cin >> noOfMinutes;
 cout << endl;

 if (noOfMinutes <= 3)
  amountDue = connectionCharge + chargeFirstThreeMinutes;
 else
  amountDue = connectionCharge + chargeFirstThreeMinutes +
     (noOfMinutes - 3) * perMinuteCharges;

 cout << "No of minutes call lasted: " << noOfMinutes << endl;
 cout << "Amount Due = $" << amountDue << endl;
system("pause");
 return 0;
}

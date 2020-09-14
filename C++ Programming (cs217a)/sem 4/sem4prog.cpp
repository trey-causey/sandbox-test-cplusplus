#include<iostream>
#include<iomanip>

using namespace std;

const double SINGLEEXEM = 4000;
const double MARRIEDEXEM = 7000;

double taxableAmount = 0;
double taxIncome = 0;
double statusExem = 0;
double personExem = 1500;
double penAmount = 0;
double grossSalary = 0;
int people = 0;

void getData();
void taxAmount();

int main()
{
    
    char answer;
    
    cout << fixed << showpoint << setprecision(2);
    cout << "This program will calculate the amount owed for Federal Taxes." << endl;
    cout << "Would you like to continue?  Enter Y or y if so...else enter any"
         << " other key:";
    cin >> answer;
    
    while(answer == 'Y' || answer == 'y')
    {
               getData();
               taxAmount();
               cout << "You owe $" << taxableAmount << " in taxes." << endl;
               cout << "Thank you" << endl;
               cout << "Would you like to calculate another amount?\n  Enter Y"
                    << " or y if so... else enter any other key:";
               cin >> answer;
    }
    
}
               
void getData()
{
     char mStatus;
     int children;
     
     cout << "Please enter marital status: S or s (single), M or m (married)";
     cin >> mStatus;
     switch(mStatus)
     {
                    case'M':
                    case'm':
                            cout << "Please enter the number of children"
                                 << " living with you:";
                            cin >> children;
                            statusExem = MARRIEDEXEM;
                            cout << "Enter combined gross salary of both"
                                 << " spouses in household:";
                            cin >> grossSalary;
                            people = children + 2;
                            personExem *= people;
                            break;
                    case'S':
                    case's':
                            statusExem = SINGLEEXEM;
                            cout << "Enter your gross salary: ";
                            cin >> grossSalary;
                            people = children + 1;
                            personExem *= people;
                            break;
     }
     cout << "Please enter the percentage between 0 and 6.0 in decimal form"
          << " that is contributed towards a pension fund: ";
          cin >> penAmount;
          if(penAmount > 0 && penAmount <= 6.0)
          {
                       penAmount *= .01;
                       penAmount *= grossSalary;
                       return;
          }
          else
              penAmount = 0;
                       
          
}

void taxAmount()
{
     taxIncome = grossSalary - statusExem - personExem - penAmount;
     if (taxIncome <= 15000)
     {
                   taxableAmount = .15;
                   taxableAmount *= taxIncome;
     }
     else if (taxIncome > 15000 && taxIncome <= 40000)
     {
          taxableAmount = .25;
          taxableAmount *= taxIncome;
          taxableAmount += 2250;
     }
     else if (taxIncome > 40000)
     {
          taxableAmount = .35;
          taxableAmount *= taxIncome;
          taxableAmount += 8460;
     }
} 

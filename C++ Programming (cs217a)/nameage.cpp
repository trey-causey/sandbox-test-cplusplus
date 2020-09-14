#include <iostream>

using namespace std;

    string firstName;
    string lastName;
    int age;
    double weight;
    
    int main()
{
    cout << "Enter your first name, last name, age, and weight, separated by spaces." << endl;
    cin >> firstName >> lastName >> age >> weight;
    cin.ignore();
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Age: " << age << endl;
    cout << "Weight: " << weight << endl;
    cin.get();
    
    return 0;
    
}

    

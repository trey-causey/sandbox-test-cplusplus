#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {

    using std::string;

    string firstWord;
    string secondWord;

    cout << "Hello, enter one word " << endl;
    cin >> firstWord;
    cout << "Enter your second word " << endl;
    cin >> secondWord;

    if(firstWord.length() > secondWord.length()) {
        cout << "word " + firstWord + " is longer than " + secondWord;
    } else if (secondWord.length() > firstWord.length()) {
        cout << "word " + secondWord + " is longer than " + firstWord;
    } else if (secondWord.length() == firstWord.length()) {
        cout << firstWord + " is the same length as " + secondWord;
    }
    return 0;
}

//Chapter 9: Programming Exercise 3

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void readData(ifstream& inputFile, int list[], int size);
void print(int list[], int size);

int main()
{
 int scores[8] = {0};

 ifstream infile;

 infile.open("e:\\junk\\scores.txt");

 if (!infile)
 {
  cout << "Cannot open the input file. Program terminates!" 
    << endl;
    system("pause");
  return 1;
  
 }

 readData(infile, scores, 8);
 print(scores, 8);
 cout << endl;

 infile.close();
 
 system("pause");
 return 0;
 
}

void readData(ifstream& inputFile, int list[], int size)
{
 int score;
 int index;

 inputFile >> score;

 while (inputFile)
 {
  index = score / 25;
  if (index == size)
   index--;
  if (index < size)
   list[index]++;
  inputFile >> score;
 }
}

void print(int list[], int size)
{
 int range;
 int lowRange = 0;
 int upperRange = 24;

 cout << "   Range       # of Students" << endl;

 for (range = 0; range < size; range++)
 {
  cout << setw(3) << lowRange << " - " << setw(3)
    << upperRange << setw(15)
    << list[range] << endl;
  lowRange = upperRange + 1;
  upperRange = upperRange + 25;
  if (range == size - 2)
   upperRange++;
 }
 cout << endl;
 
}


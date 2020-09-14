#include <iostream>
#include <array>
#include <iomanip>
#include "headers/functions.h"
#include "headers/gearCalc.h"

#define LOG(x) std::cout << x << std::endl

int main()
{
  int d3=8,year=2015,d1=1996,d2=2100;
  int arr[5]= {12, 34, 13, 14, 16};
  auto* pInt = (double*)&d3;
  char c = 'a';
  char* pChar = &c;
  char d = *pChar;
  int crankSetGearCount = 3;
  int cassetteSetGearCount = 8;
  double tripleCrankset4828[3] = {48,38,28};
  double tripleCrankset4222[3] = {42,32,22};
  double doubleCrankset5034[2] = {50,34};
  double cassette8speed1132[8] = {11,13,14,18,21,24,28,32};

  std::cout << "\nthe value of \'d1\' is: " << d1;
  std::cout << "\tthe value of \'d2\' is: " << d2;
  int result = multiply(d1, d2);
  std::cout << "\nthe result of \'d1\' * \'d2\' is: " << result;
  bool answer = is_leap_year(year);
  std::cout << "\nresult: " << answer;
  std::cout << "\nis_ten with 10: " << is_ten(10);
  std::cout << "\nis_ten with 9: " << is_ten(9);
  std::cout << "\nd1 is: \t" << d1;
  std::cout << "\npointer pInt is: " << pInt;
  std::cout << "\nThe value of the deref pointer is: " << *pChar;
  std::cout << "\nGear ratio of 28 teeth crank on 28 teeth drive is: " << defineRatio(28, 28);
  std::cout << "\nGear ratio of 28 teeth crank on 24 teeth drive is: " << defineRatio(28, 24);
  std::cout << "\nGear ratio of 28 teeth crank on 21 teeth drive is: " << defineRatio(28, 21);
  std::cout << "\n";
  std::cout << "The size of this array is: " << std::size(tripleCrankset4828) << "\n";
  for(int drive = 0;drive < std::size(tripleCrankset4828); drive++)
  {
    for(int cassette = 0; cassette < std::size(cassette8speed1132); cassette++)
    {
      std::cout << tripleCrankset4828[drive] << ':' << cassette8speed1132[cassette] <<'=';
      std::cout << std::setprecision(3) << defineRatio(tripleCrankset4828[drive],cassette8speed1132[cassette]) << "\t";
    }
    std::cout << "\n";
  }

  std::cout << "The size of this array is: " << std::size(doubleCrankset5034) << "\n";
  for(int drive = 0;drive < std::size(doubleCrankset5034); drive++)
  {
    for(int cassette = 0; cassette < std::size(cassette8speed1132); cassette++)
    {
      std::cout << doubleCrankset5034[drive] << ':' << cassette8speed1132[cassette] <<'=';
      std::cout << std::setprecision(3) << defineRatio(doubleCrankset5034[drive],cassette8speed1132[cassette]) << "\t";
    }
    std::cout << "\n";
  }
  std::cout << "The size of this array is: " << std::size(tripleCrankset4222) << "\n";
  for(int drive = 0;drive < std::size(tripleCrankset4222); drive++)
  {
    for(int cassette = 0; cassette < std::size(cassette8speed1132); cassette++)
    {
      std::cout << tripleCrankset4222[drive] << ':' << cassette8speed1132[cassette] <<'=';
      std::cout << std::setprecision(3) << defineRatio(tripleCrankset4222[drive],cassette8speed1132[cassette]) << "\t";
    }
    std::cout << "\n";
  }

  return 0;

}//end main()




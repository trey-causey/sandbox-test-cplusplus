#include <iostream>
#include <array>
#include <iomanip>
#include "headers/functions.h"
#include "headers/gearCalc.h"
#include <string>
#define LOG(x) std::cout << x << std::endl

int main()
{
  std::string s = "temp";
  const auto& len = s.length();
  auto x = len;
  //int tempArr[x];
  int* tempArray = new int[x];
  int d3=8,year=2015,d1=1996,d2=2100;
  auto* pInt = (double*)&d3;
  char c = 'a';
  char* pChar = &c;
  char d = *pChar;
  double tripleCrankset4828[3] = {48,38,28};
  double tripleCrankset4222[3] = {42,32,22};
  double tripleCrankset4224[3] = {42,34,24};
  double doubleCrankset5034[2] = {50,34};
  double cassette8speed1132[8] = {11,13,15,18,21,24,28,32};
  double cassette8speed1128[8] = {11,13,15,17,19,21,24,28};
  double cassette7speed1428[7] = {14,16,18,20,22,24,28};

  std::cout << "\nx is: " << x;

  std::cout << "\n";

for(double drive: doubleCrankset5034) {
  for(double cassette: cassette8speed1132) {
    std::cout << drive << ':' << cassette << '=';
    std::cout << std::setprecision(3) << defineRatio(drive,cassette) << "  /-";

  }
  std::cout << "\n";
}
std::cout << "\t_________________________________________________________________\n";
for(double drive : tripleCrankset4828) {
    for (double cassette : cassette8speed1132) {
      std::cout << drive << ':' << cassette << '=';
      std::cout << std::setprecision(3) << defineRatio(drive, cassette) << "  /-";
    }
    std::cout << "\n";
  }
std::cout << "\t_________________________________________________________________\n";
for(double drive : tripleCrankset4828)   {
    for(double cassette : cassette8speed1128)
    {
      std::cout << drive << ':' << cassette <<'=';
      std::cout << std::setprecision(3) << defineRatio(drive,cassette) << "  /-";
    }
    std::cout << "\n";
  }

  std::cout << "\nthe value of \'d1\' is: " << d1;
  std::cout << "\tthe value of \'d2\' is: " << d2;
  int result = multiply(d1, d2);
  std::cout << "\nthe result of \'d1\' * \'d2\' is: " << result;
  bool answer = is_leap_year(year);
  std::cout << "\nresult: " << answer;
  std::cout << "\nd1 is: \t" << d1;
  std::cout << "\npointer pInt is: " << pInt;
  std::cout << "\nThe value of the deref pointer is: " << *pChar;

  return 0;

}//end main()




#include <iostream>
#include <string>
#include <iterator>
#include <map>
#include <cassert>
#include "header/test.h"
#include "header/ClockType.h"
#include "header/Solution.h"
#include <cfloat>

int main() {
  std::cout << "Max Digits\n" << FLT_MAX << std::endl;
std::map<char, int> mapObject
        {
                {'A', 1},
                {'B',2},
                {'C',3},
                {'D',4}
        };
std::vector<int> nums =  {1,2,3,4};
Solution solutionObj;

std::vector<int> finalAns = solutionObj.runningSum(nums);
for(int item:finalAns) {
  std::cout<<item<<"\n";
}
ClockType myClock;
ClockType yourClock, hisClock;
yourClock.setTime(2, 34, 12);
//ClockType theirClock = new ClockType(2,34,12);
hisClock.setTime(2,34,12);
myClock = yourClock;
//myClock.getTime();
if(myClock.equalTime(yourClock))
{
  std::cout << "They are equal";
} else {
  std::cout << "not equal";
}
if(hisClock.equalTime(yourClock))
  {
    std::cout << "They are equal";
  } else {
    std::cout << "not equal";
  }
std::cout << inchesToCentimeters(24);

std::cout << mapObject.at('A');
int& rInt = mapObject.at('A');
  auto it = mapObject.find('A');
  it->second++;
rInt++;
  return 0;
}

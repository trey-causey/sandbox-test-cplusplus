//
// Created by TJC on 9/24/2020.
//

#include "../header/Solution.h"

vector<int> Solution::runningSum(vector<int> &nums) {
  vector<int> ans;
  int traillingSums = 0;
  for(int num:nums) {
    ans.push_back(traillingSums += num);
  }
  //return vector<int>();
  return ans;
}

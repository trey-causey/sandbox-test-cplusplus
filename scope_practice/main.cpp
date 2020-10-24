#include <iostream>
#include "header/Scope.h"

int main() {

  int ans1 = nsa::Scope::fAdd(4, 9);
  std::cout << "\n" << ans1 << std::endl;
  nsa::Scope scopeObj;
  int ans2 = scopeObj.fMultiply(12, 23);
  std::cout << "\n" << ans2 << std::endl;

  return 0;
}

#include <iostream>
#include <vector>

//this test file is meant to practice and learn namespaces and classes
int main() {
  std::cout << "Hello, World!" << std::endl;

  return 0;
}

class MyMath
{
private:
    const double PI = 3.14159265359;
    double circumference = 1;
public:
    MyMath();
    double findCircumference(double diameter)
    {
      return circumference = (diameter * PI);
    }
};

MyMath::MyMath() {

}

std::vector<std::string> Account::Report()
{
  vector<string> report;
  report.push_back("Balance is " + to_string(balance));
  report.push_back("Transactions: ");

  for (auto t:log)
  {
    report.push_back(t.report());
  }
}



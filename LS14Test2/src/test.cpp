//
// Created by TJC on 9/23/2020.
//
#include "../header/test.h"
#include <iostream>
#include <cassert>
double inchesToCentimeters(double inches)
{
  if (inches < 0)
  {
    std::cerr<<"The measure should be non-negative"<<std::endl;
    return -1.0;
  } else
  {
    return inches * 2.54;
  }
}
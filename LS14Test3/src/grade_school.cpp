// Created by TJC on 9/29/2020.
#include "../header/grade_school.h"
#include<iostream>

namespace grade_school {
    std::map<int, std::vector<std::string>> grade_school::school::roster() const {
      return std::map<int, std::vector<std::string>>() = {};
    }

    void school::add(std::vector<std::string> &s, int &i) {

    }

    void school::add(const char *string, int i) {

    }

    void school::underscoreTest() {
      grade_school::school school_{};
      if(school_.roster().empty())
      {
        std::cout << "It's correct";
      } else {
        std::cout << "Failed! Needs work!";
      } //end if/else
    } //end underscoreTest()

    void school::nounderscoreTest() {
      grade_school::school school_;
      school_.add("Aimee", 2);
      if(school_.roster().empty())
      {
        std::cout << "It's correct";
      } else {
        std::cout << "Failed! Needs work!";
      } //end if/else
    }

    //end nounderscoreTest()


}


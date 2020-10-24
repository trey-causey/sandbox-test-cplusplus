// Created by TJC on 9/29/2020.
#ifndef LS14TEST3_GRADE_SCHOOL_H
#define LS14TEST3_GRADE_SCHOOL_H
#include <xstring>
#include <vector>
#include <map>

namespace grade_school {
    class school
    {
    private:
        int grade;
      std::vector<std::string> studentNames;
    public:
        std::map<int, std::vector<std::string>> roster() const;
        void add(const char string[6], int i);
        void add(std::vector<std::string> &s, int &i);
        void underscoreTest();
        void nounderscoreTest();
    };//end class school
}//end namespace grade_school



#endif //LS14TEST3_GRADE_SCHOOL_H

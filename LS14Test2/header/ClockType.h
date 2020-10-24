//
// Created by TJC on 9/23/2020.
//
#ifndef LS14TEST2_CLOCKTYPE_H
#define LS14TEST2_CLOCKTYPE_H

class ClockType
{
public:
    ClockType();
    ClockType(int hours, int minutes, int seconds);
    void setTime(int hours, int minutes, int seconds);
    void getTime(int& hours, int& minutes, int& seconds);
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const ClockType& otherClock ) const;
private:
    int sec = 0;
    int min = 30;
    int hr;
};

#endif //LS14TEST2_CLOCKTYPE_H

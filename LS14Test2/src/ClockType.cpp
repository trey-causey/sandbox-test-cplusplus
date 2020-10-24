//
// Created by TJC on 9/23/2020.
//

#include "../header/ClockType.h"


void ClockType::setTime(int hours, int minutes, int seconds) {
hr = hours;
min = minutes;
sec = seconds;
}

void ClockType::getTime(int& hours, int& minutes, int& seconds) {
hours = hr;
minutes = min;
seconds = sec;
}

void ClockType::printTime() const {

}

void ClockType::incrementSeconds() {
sec++;
}

void ClockType::incrementMinutes() {
min++;
}

void ClockType::incrementHours() {
hr++;
}

bool ClockType::equalTime(const ClockType &otherClock) const {
  return (hr == otherClock.hr &&
  min == otherClock.min &&
  sec == otherClock.sec);
}

ClockType::ClockType() {
min = 0;
hr = 0;
sec = 0;
}

ClockType::ClockType(int hours, int minutes, int seconds) {
  hr = hours;
  min = minutes;
  sec = seconds;
}

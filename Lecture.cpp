#include "Lecture.h"
Lecture::Lecture(int duration, int startHour, const string &type, const string &weekday,const string &UcCode) {
    this->duration = duration;
    this->weekday = weekday;
    this->type = type;
    this-> startHour = startHour;
    UC_Code = UcCode;
}

int Lecture::getDuration() const {
    return duration;
}

void Lecture::setDuration(int duration) {
    Lecture::duration = duration;
}

int Lecture::getStartHour() const {
    return startHour;
}

void Lecture::setStartHour(int startHour) {
    Lecture::startHour = startHour;
}

const string &Lecture::getType() const {
    return type;
}

void Lecture::setType(const string &type) {
    Lecture::type = type;
}

const string &Lecture::getWeekday() const {
    return weekday;
}

void Lecture::setWeekday(const string &weekday) {
    Lecture::weekday = weekday;
}

const string &Lecture::getUcCode() const{
    return UC_Code;
}
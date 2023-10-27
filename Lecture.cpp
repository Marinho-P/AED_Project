#include "Lecture.h"
Lecture::Lecture(const string &duration,const string &startHour, const string &type, const string &weekday,const string &UcCode) {
    this->duration = duration;
    this->weekday = weekday;
    this->type = type;
    this-> startHour = startHour;
    UC_Code = UcCode;
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

bool Lecture::operator<(const Lecture& other) const{
    return startHour < other.startHour;
}
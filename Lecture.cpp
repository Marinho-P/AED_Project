#include "Lecture.h"
Lecture::Lecture(const float &duration,const float &startHour, const string &type, const string &weekday,const string &UcCode) {
    this->duration = duration; //float
    this->weekday = weekday;
    this->type = type;
    this-> startHour = startHour; // float
    UC_Code = UcCode;
}

void Lecture::setDuration(float duration) {
    Lecture::duration = duration;
}

void Lecture::setStartHour(float startHour) {
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

bool Lecture::operator<(const Lecture& other) const{
    return startHour < other.startHour;
}
const float &Lecture::getDuration() const{
    return duration;
}

const float &Lecture::getStartHour() const {
    return startHour;
}

#include "Schedule.h"

Schedule::Schedule(const string &classCode) {
    this->classCode = classCode;
}

const vector<Lecture> &Schedule::getSchedule() const {
    return lectures;
}

const string &Schedule::getClassCode() const {
    return classCode;
}

void Schedule::addLecture(Lecture lecture)  {
    lectures.push_back(lecture);
}

bool Schedule::operator<(const Schedule &other) const {
    return classCode < other.classCode;
}

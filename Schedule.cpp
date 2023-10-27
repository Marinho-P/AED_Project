#include <iostream>
#include <iomanip>
#include <string>
#include "Schedule.h"



static const int n = 12;


void Schedule::printSchedule() {
    string time = "8:00";
    //vector<string daysoftheweek = {};
    cout << "+------------+------------+------------+------------+------------+------------+\n" <<
         "|            |   Segunda  |   Terça    |   Quarta   |   Quinta   |    Sexta   |\n" <<
         "+------------+------------+------------+------------+------------+------------+\n";
    for (size_t i = 0; i < 24; i++) {

        cout << "|" << time << "|";

    }

}
Schedule::Schedule(const std::string &classCode) {
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

#include <string>
#include "Student.h"

Student::Student(const string &name, const string &id,Schedule &schedule_) : name(name),id(id), schedule(schedule_) {}

const string &Student::getName() const {
    return name;
}

const string &Student::getId() const {
    return id;
}

void Student::setName(const string &name) {
    Student::name = name;
}

void Student::setId(const string &id) {
    Student::id = id;
}

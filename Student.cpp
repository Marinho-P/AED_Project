#include "Student.h"

Student::Student(const string &name, const string &id,const set<Class_UC> &classesUcs) : name(name),id(id),classesUcs(classesUcs) {}

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


bool Student::operator<(const Student &other) const{
    return id < other.id;
}

bool Student::operator==(const Student &other) const {
    return id == other.id;
}

void Student::addClassUc(const Class_UC &classUc){
    classesUcs.insert(classUc);
}

const set<Class_UC> &Student::getClassesUcs() const {
    return classesUcs;
}

string Student::getYear() const {
    return id.substr(0,4);
}
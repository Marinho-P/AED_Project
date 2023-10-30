#ifndef AED_PROJECT_ESTUDANTE_H
#define AED_PROJECT_ESTUDANTE_H
#include <string>
#include "Schedule.h"
#include "Class_UC.h"
using namespace std;

class Student {
private:
    string name;
    string id;
    set<Class_UC> classesUcs;
    string ucId;
    string classId;
public:
    Student(const string &name = "", const string &id = "",const set<Class_UC> &classesUcs = set<Class_UC>());
    const string &getName() const;
    const string &getId() const;
    const set<Class_UC> &getClassesUcs() const;
    void setName(const string &name);
    void setId(const string &id);
    bool operator<(const Student &other) const;
    bool operator==(const Student &other) const;
    void addClassUc(const Class_UC &classUc);
    string getYear() const;
    string getUcId() const;
    string getClassId() const;
};

#endif
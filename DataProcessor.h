#ifndef AED_PROJECT_DATAPROCESSOR_H
#define AED_PROJECT_DATAPROCESSOR_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include "Student.h"
#include "Class_UC.h"
#include "Lecture.h"
using namespace std;

class DataProcessor{
    private:
        set<Student> students;
        set<Class_UC> existingClassesUc;
        set<Schedule> schedules;
    public:
        DataProcessor();
        void classes_per_uc();
        void classes();
        void students_classes();
        const set<Student> &getStudents() const;
        const set<Class_UC> &getClassUc() const;
        const set<Schedule> &getSchedules() const;
        void studentsInUc(int n);
        void studentsInClass(const string& classCode);
        void studentsInCourse(string course);
        void studentsInYear(const string &year);
        void ucGreatestNumberStudents();
        void scheduleOfClass(const string &classCode);
        void scheduleOfStudent(const Student &student);
};


#endif //AED_PROJECT_DATAPROCESSOR_H

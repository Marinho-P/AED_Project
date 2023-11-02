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
/**
 * @brief Class that stores and processes useful data from the csv files
 */

class DataProcessor{
private:
    set<Student> students;
    /** @brief A set where all students are stored in */
    set<Class_UC> existingClassesUc;
    set<Schedule> schedules;
    /** @brief A set where all schedules of classes are stored in */
public:
    DataProcessor();
    void classes_per_uc();
    void classes();
    void students_classes();
    const set<Student> &getStudents() const;
    const set<Class_UC> &getClassUc() const;
    const set<Schedule> &getSchedules() const;
    void studentsInUc(int n);
    void studentsInClass(const string& classCode,const string& sortOption);
    void studentsInCourse(string course,const string& sortOption);
    void studentsInYear(const string &year,const string& sortOption);
    void ucGreatestNumberStudents();
    void scheduleOfClass(const string &classCode) const;
    void scheduleOfStudent(const string &Id) const;
};


#endif //AED_PROJECT_DATAPROCESSOR_H
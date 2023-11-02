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
#include <map>
#include <climits>
#include "Request.h"

using namespace std;
/**
 * @brief Class that stores and processes useful data from the csv files
 */

class DataProcessor{
    private:
        /** @brief A set where all students are stored in */
        set<Student> students;
        set<Class_UC> existingClassesUc;
        /** @brief A set where all schedules of classes are stored in */
        set<Schedule> schedules;
        /** @brief A vector where all pending requests are stored in */
        vector<Request> PendingRequests;
    public:
        DataProcessor();
        void classes_per_uc();
        void classes();
        void students_classes();
        const set<Class_UC> &getClassUc() const;
        const set<Schedule> &getSchedules() const;
        void studentsInAtLeastNUCs(int n);
        void studentsInUc(const string& ucCode,const string& sortOption);
        void studentsInClass(const string& classCode,const string& sortOption);
        void studentsInCourse(const string course,const string& sortOption);
        void studentsInYear(const string &year,const string& sortOption);
        void ucGreatestNumberStudents();
        void scheduleOfClass(const string &classCode);
        void scheduleOfStudent(const Student &student);
        Schedule createStudentSchedule(const Student &student);
        void processRequest(int RequestID);
        void ChangeFileSwitch(Student &student, const string &UcCodeToChange, const string &newClassCode);
        void ChangeFileRemove(Student &student, const string &UcCodeToRemove);
        void ChangeFileAdd(Student &student, const string &NewClassCode, const string &NewUcCode);
        bool checkScheduleCollisions(vector<Lecture> lectures);
        void undoRequest(int RequestID);
        void saveRequest(const Student &student, const string &type, const string &UcCode, const string &startCode,const string &endCode);
        void lookupAllRequests();
        void SwitchRequest(Student &student, const string &oldClassCode, const string &newClassCode, const string &UcCode,bool save);
        void RemoveRequest(Student &student, const string &UcCode, bool save);
        void AddRequest(Student &student, const string &UcCode, bool save);
        void addPendingRequest(const Request &request);
        void discardRequest(int RequestID);
        void printPendingRequests();
        vector<Lecture> FuseSchedules(const Schedule &old_schedule, const Schedule &schedule_to_add, const string &UcCode);
        vector<Lecture>switchFuseSchedules(const Schedule &old_schedule, const Schedule &schedule_to_add, const string &UcCode);
        void performRequest(Request &request);
        set<Student> &getStudents();
        map<Class_UC, int> &getNumberOfStudents(map<Class_UC, int> &numberOfStudentsPerClass);
        bool checkAdd(const Student &studentToAdd, const Class_UC &classUcToCheck);
        bool checkBalanceAndCap(map<Class_UC, int> &numberOfStudentsPerClass) const;
        bool checkRemove(const Student &student, const Class_UC &classUc);
        bool checkSwitch(const Student &student, const Class_UC &oldClassUc, const Class_UC &newClassUc);
};


#endif //AED_PROJECT_DATAPROCESSOR_H
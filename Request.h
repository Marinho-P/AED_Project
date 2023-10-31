//
// Created by sergio on 29-10-2023.
//

#ifndef AED_PROJECT_REQUEST_H
#define AED_PROJECT_REQUEST_H


#include "Student.h"
#include "DataProcessor.h"

class Request {
private:


    Request(const DataProcessor &dataProcessor);

    DataProcessor dataProcessor;
public:
    void lookupAllRequests();
    void undoRequest(int RequestID);




    void SwitchRequest(Student &student, string type, Class_UC start, Class_UC end);



    bool checkScheduleCollisions(vector<Lecture> lectures);

    vector<Lecture> FuseSchedules(const Schedule &old_schedule, const Schedule &schedule_to_add, string &UcCode);




    void AddRequest(Student &student, string &UcCode);


    void RemoveRequest(Student &student, const string& UcCode);


    void saveRequest(const Student &student, const string &type, const string &recipient, const string &startCode,
                     const string &endCode);



    void ChangeFile(Student &student, const string &NewClassCode, const string &NewUcCode, const string &type);

    bool checkBalanceAndCap(unordered_map<string, int> &numberOfStudentsPerClass) const;

    unordered_map<string, int> &getNumberOfStudents(unordered_map<string, int> &numberOfStudentsPerClass);

    bool checkAdd(const Student &studentToAdd, const string &classCode);


    bool checkRemove(const Student &student, const string &classCode);
};


#endif //AED_PROJECT_REQUEST_H

//
// Created by sergio on 01-11-2023.
//

#ifndef AED_PROJECT_REQUEST_H
#define AED_PROJECT_REQUEST_H
#include <string>
#include "Student.h"

using namespace std;
class Request {
private:
    Student student;
    string type;
    string UcCode;
    string startCode;
    string endCode;
public:
    Request(Student &student, const string &type, const string &ucCode,
            const string &startCode, const string &endCode);


    const string &getType() const;

    const string &getUcCode() const;

    const string &getStartCode() const;

    const string &getEndCode() const;

    Student& getStudent();
};


#endif //AED_PROJECT_REQUEST_H

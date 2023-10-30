
#ifndef AED2324_P03_REQUESTS_H
#define AED2324_P03_REQUESTS_H
#include "Student.h"
#include <iostream>
#include "Class_UC.h"

class Request {
public:
    Request(const Student &student, const Class_UC &desiredClass, const string &type);
    void printHeader() const;
    void print() const;
    Student getStudent() const;
    Class_UC getDesiredUcClass() const;

private:
    Student student;
    Class_UC desiredUcClass;
    string type;
};
#endif //AED2324_P03_REQUESTS_H

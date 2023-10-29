//
// Created by sergio on 29-10-2023.
//

#ifndef AED_PROJECT_REQUEST_H
#define AED_PROJECT_REQUEST_H


#include "Student.h"

class Request {

public:
    Request();
    void performRequest(Student &student,set<Class_UC> existingClassesUc, string type, string I);
    void lookupAllRequests();
    void undoRequest(int RequestID);


    void saveRequest(Student &student, string type, string recipient, string startCode, string endCode);
};


#endif //AED_PROJECT_REQUEST_H

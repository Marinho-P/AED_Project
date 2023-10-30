#include "requests.h"

Request::Request(const Student &student, const Class_UC &desiredClass, const string &type) {
    if (type != "Changing" && type != "Removal" && type != "Enrollment") {
        return;
    }
    this->student = student;
    this->desiredUcClass = desiredClass;
    this->type = type;
}

void Request::printHeader() const {
    cout << "Student: " << student.getName() << " - " << student.getId() << "  |  ";

    if (type == "Removal") {
        for (const auto& uc : desiredUcClass) {
            cout << "Requested Uc: " << uc.getUcId();
        }
    } else {
        for (const auto& uc : desiredUcClass) {
            cout << "Requested class: " << uc.getUcId() << " - " << uc.getClassId();
        }
    }
}

void Request::print() const {
    printHeader();
    cout << "  |  " << "Type: " << type << endl;
}

Student Request::getStudent() const {
    return student;
}

Class_UC Request::getDesiredUcClass() const {
    return desiredUcClass;
}
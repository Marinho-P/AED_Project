#include "Request.h"

Request::Request( Student &student, const string &type, const string &ucCode,
                 const string &startCode, const string &endCode) : student(student),
                                                                                   type(type), UcCode(ucCode),
                                                                                   startCode(startCode),
                                                                                   endCode(endCode) {}

const string &Request::getType() const {
    return type;
}

const string &Request::getUcCode() const {
    return UcCode;
}

const string &Request::getStartCode() const {
    return startCode;
}

const string &Request::getEndCode() const {
    return endCode;
}
Student & Request::getStudent() {
    return student;

}
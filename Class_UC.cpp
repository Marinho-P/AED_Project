#include "Class_UC.h"

const string &Class_UC::getUcCode() const {
    return UC_Code;
}

const string &Class_UC::getClassCode() const {
    return Class_Code;
}

void Class_UC::setClassCode(const string &classCode) {
    Class_Code = classCode;
}

void Class_UC::setUcCode(const string &ucCode) {
    UC_Code = ucCode;
}

Class_UC::Class_UC(const string &ucCode, const string &classCode) {
    Class_Code = classCode;
    UC_Code = ucCode;
}

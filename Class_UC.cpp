#include "Class_UC.h"

Class_UC::Class_UC(const string &classCode_, const string &ucCode_) {
    classCode = classCode_;
    ucCode = ucCode_;
}

const string &Class_UC::getUcCode() const {
    return ucCode;
}

void Class_UC::setUcCode(const string &ucCode) {
    Class_UC::ucCode = ucCode;
}

const string &Class_UC::getClassCode() const {
    return classCode;
}

void Class_UC::setClassCode(const string &classCode) {
    Class_UC::classCode = classCode;
}

bool Class_UC::operator<(const Class_UC &other) const{
    if(ucCode < other.ucCode){
        return true;
    }
    else{
        if(ucCode == other.ucCode && classCode < other.classCode){
            return true;
        }
    }
    return false;
}

bool Class_UC::operator==(const Class_UC &other) const {
    return other.ucCode == ucCode && other.classCode == classCode;
}
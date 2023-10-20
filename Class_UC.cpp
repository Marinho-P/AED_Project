#include "Class_UC.h"


const string &Class_UC::getUcCode() const {
    return ucCode;
}

Class_UC::Class_UC(const string &ucCode_ ) {
    ucCode = ucCode_;
}

void Class_UC::addClassCode(const string &classCode) {
    classCodes.insert(classCode);
}

bool Class_UC::operator<(const Class_UC& other) const {
    return ucCode < other.getUcCode();
}

const set<string> &Class_UC::getClassCodes() const{
    return classCodes;
}

void Class_UC::printUcAndClasses() {
    cout << "Uc_code: " << ucCode << endl;
    cout << "Class codes:" << endl;
    for (const string& classCode:classCodes ) {
        cout << classCode << endl;
    }
}

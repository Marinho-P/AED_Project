#ifndef AED_PROJECT_UC_H
#define AED_PROJECT_UC_H
#include <string>
#include <set>
#include <iostream>

using namespace std;

class Class_UC{
    private:
        string ucCode;
        set<string> classCodes;
    public:
        Class_UC(const string &ucCode_);
        const string &getUcCode() const;
        void addClassCode(const string &ucCode);
        bool operator<(const Class_UC& other) const;
        const set<string> &getClassCodes() const;
        void printUcAndClasses();
};

#endif //AED_PROJECT_UC_H

#ifndef AED_PROJECT_UC_H
#define AED_PROJECT_UC_H
#include <string>
#include <set>
#include <iostream>

using namespace std;

class Class_UC{
    private:
        string ucCode;
        string classCode;
    public:
        Class_UC(const string &classCode_ ="" ,const string &ucCode_ = "");
        const string &getUcCode() const;
        void setUcCode(const string &ucCode);
        const string &getClassCode() const;
        void setClassCode(const string &classCode);
        bool operator<(const Class_UC &other) const;
        bool operator==(const Class_UC &other) const;
};

#endif //AED_PROJECT_UC_H

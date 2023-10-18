#ifndef AED_PROJECT_UC_H
#define AED_PROJECT_UC_H
#include <string>
using namespace std;

class Class_UC{
    private:
        string UC_Code;
        string Class_Code;

    public:
        Class_UC(const string &ucCode, const string &classCode);
        const string &getUcCode() const;
        const string &getClassCode() const;
        void setUcCode(const string &ucCode);
        void setClassCode(const string &classCode);
};

#endif //AED_PROJECT_UC_H

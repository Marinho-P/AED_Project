#ifndef AED_PROJECT_ESTUDANTE_H
#define AED_PROJECT_ESTUDANTE_H
#include <string>
#include "Schedule.h"
using namespace std;

class Student {
    private:
        string name;
        string id;
        Schedule schedule;
    public:
        Student(const string &name, const string &id,Schedule &schedule_);
        const string &getName() const;
        const string &getId() const;
        void setName(const string &name);
        void setId(const string &id);
};

#endif

#ifndef AED_PROJECT_SCHEDULE_H
#define AED_PROJECT_SCHEDULE_H

#include "Lecture.h"
#include <vector>
#include <set>
using namespace std;

class Schedule {
    private:
        vector<Lecture> lectures;
        string classCode;
    public:
        Schedule(const string &classCode = "");
        const vector<Lecture> &getSchedule() const;
        const string &getClassCode() const;
        void addLecture(Lecture lecture);
        bool operator<(const Schedule& other) const;
};

#endif //AED_PROJECT_SCHEDULE_H

#ifndef AED_PROJECT_SCHEDULE_H
#define AED_PROJECT_SCHEDULE_H

#include "Lecture.h"
#include <vector>
using namespace std;

class Schedule {
    private:
        vector<Lecture> schedule;
    public:
        Schedule(vector<Lecture> schedule);
        void printSchedule();
};


#endif //AED_PROJECT_SCHEDULE_H

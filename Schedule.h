#ifndef AED_PROJECT_SCHEDULE_H
#define AED_PROJECT_SCHEDULE_H

#include "Lecture.h"
#include "Class_UC.h"
#include <vector>
#include <set>
using namespace std;

class Schedule {
    private:
        vector<Lecture> lectures;
        Class_UC classUc;
    public:
        void printSchedule() const;
        string getSlotString(float time, string weekday,vector<Lecture> &toPrint,int &currentLine, int &linesOccupied, bool inSlot ) const;
        string timeFtS(float time) const;
        Schedule(const Class_UC &classUc = Class_UC());
        const vector<Lecture> &getLectures() const;
        const string &getClassCode() const;
        void addLecture(Lecture lecture);
        bool operator<(const Schedule& other) const;
        string centerString(string toFormat) const;
        const Class_UC &getClassUc() const;
};

#endif //AED_PROJECT_SCHEDULE_H

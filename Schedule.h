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
        void printSchedule() const;
        string getSlotString(float time, string weekday,vector<Lecture> &toPrint,int &currentLine, int &linesOccupied, bool inSlot ) const;
        string timeFtS(float time) const;
        Schedule(const string &classCode = "");
        const vector<Lecture> &getLectures() const;
        const string &getClassCode() const;
        void addLecture(Lecture lecture);
        bool operator<(const Schedule& other) const;
        string centerString(string toFormat) const;
};

#endif //AED_PROJECT_SCHEDULE_H

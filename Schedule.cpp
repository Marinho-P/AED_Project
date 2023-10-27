#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Schedule.h"




void Schedule::printSchedule() const { // word (ucCode-type) in each slot must be [0,13] characters long
    try {
        vector<Lecture> toPrint = lectures;
        sort(toPrint.begin(), toPrint.end()); // sorted by Start Time
        float time = 8.0;
        vector<string> daysoftheweek = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
        cout << "+-------------+-------------+-------------+-------------+-------------+-------------+\n" <<
                "|             |   Monday    |   Tuesday   |  Wednesday  |  Thursday   |    Friday   |\n" <<
                "+-------------+-------------+-------------+-------------+-------------+-------------+\n";


        for (size_t i = 0; i < 25; i++) {

            cout << "|" << centerString(timeFtS(time)) << "|";
            for (size_t i = 0; i < 5; i++) {
                cout << "             |";
            }
            cout << "\n";
            cout << "+-------------+";
            for (size_t i = 0; i < 5; i++) {
                cout << "-------------+";
            }
            cout << "\n";
            time += 0.5;
        }
    }catch (const out_of_range& error){
            cerr << error.what() << endl;
    }

}

Schedule::Schedule(const string &classCode) {

    this->classCode = classCode;
}

const vector<Lecture> &Schedule::getSchedule() const {
    return lectures;
}

const string &Schedule::getClassCode() const {
    return classCode;
}

void Schedule::addLecture(Lecture lecture)  {
    lectures.push_back(lecture);
}

bool Schedule::operator<(const Schedule &other) const {
    return classCode < other.classCode;
}

string Schedule::getSlotString(float time, string weekday, vector<Lecture> toPrint) {
    int i = 0;

    while(weekday != toPrint[i].getWeekday()){
        i++;
        if(time != toPrint[i].getStartHour()){
            return "             ";
        }
    }
    //int linesoccupied =  1 + 2*(toPrint[i].getStartHour() / 0.5;


    //return
}
string Schedule::timeFtS(float time) const{
    float remainder = time - (int)time;
    float hours = (int)time;
    stringstream ss;
    ss << hours;
    if(remainder == 0.5){

        return ss.str() + ":30";
    }
    else{
        return ss.str() + ":00";
    }
}

string Schedule::centerString(string toFormat) const {
    if( toFormat.size() > 13){
        throw out_of_range(toFormat + ": string too big for timeslot");
    }
    int tofill = 13 - toFormat.size();
    int pad1 = tofill/2;
    int pad2 = tofill - pad1;
    return string(pad1, ' ') + toFormat + string(pad2, ' ');
}


//L.EIC001-TP

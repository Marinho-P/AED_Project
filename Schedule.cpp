#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Schedule.h"




void Schedule::printSchedule() const { // word (ucCode-type) in each slot must be [0,13] characters long
    try {
        vector<Lecture> toPrint = lectures;
        float time = 8.0;
        vector<string> daysoftheweek = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
        vector<int> currentLine = {0,0,0,0,0};
        vector<int> linesOccupied = {-1,-1,-1,-1,-1};
        cout << "+-------------+-------------+-------------+-------------+-------------+-------------+\n" <<
             "|             |   Monday    |   Tuesday   |  Wednesday  |  Thursday   |    Friday   |\n" <<
             "+-------------+-------------+-------------+-------------+-------------+-------------+\n";


        for (size_t k = 0; k < 48; k++) {

            bool inSlot = !(k%2);
            if(inSlot) {
                cout << "|" << centerString(timeFtS(time) + "-" + timeFtS(time+0.5))   << "|";
            }
            else{
                cout << "|-------------|";
            }


            for (size_t i = 0; i < 5; i++) {
                sort(toPrint.begin(), toPrint.end()); // sorted by Start Time

                cout << centerString(getSlotString(time,daysoftheweek[i],toPrint,currentLine[i],linesOccupied[i],inSlot)) + "|";
            }
            cout << "\n";
            if(!(inSlot)){
                time += 0.5;
            }

        }
    }catch (const out_of_range& error){
        cerr << error.what() << endl;
    }

}

Schedule::Schedule(const string &classCode) {
    this->classCode = classCode;
}

const vector<Lecture> &Schedule::getLectures() const {
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


string Schedule::getSlotString(float time, string weekday, vector<Lecture> &toPrint, int &currentLine, int &linesOccupied ,bool inSlot ) const{
    int i = 0;
    if(toPrint.empty()){
        if(inSlot){
            return "             ";
        }
        else{
            return "-------------";
        }
    }
    while(true){
        if( weekday == toPrint[i].getWeekday() && time == toPrint[i].getStartHour()){
            break;
        }
        i++;
        if(i > 4){
            if(inSlot) {
                return "             ";
            }
            else{
                return "-------------";
            }
        }
    }
    if(linesOccupied == currentLine){
        toPrint.erase(next(toPrint.begin(),i));
        linesOccupied = -1;
        currentLine = 0;
        return "-------------";

    }

    if(linesOccupied == -1){
        linesOccupied = 2*(toPrint[i].getDuration() / 0.5) - 1 ;
        currentLine = 0;
    }
    if(!(inSlot)) {
        toPrint[i].setStartHour(toPrint[i].getStartHour() + 0.5);
    }
    if( currentLine == (linesOccupied / 2)){
        currentLine++;
        return toPrint[i].getUcCode()+ "-" + toPrint[i].getType();
    }
    else{
        currentLine++;

        return "             ";

    }


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
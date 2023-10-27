#include <iostream>
#include <iomanip>
#include <string>
#include "Schedule.h"


static const int n = 12;

Schedule::Schedule(vector<Lecture> schedule) {
    this->schedule = schedule;
}
void Schedule::printSchedule(){
    string time = "8:00";
    vector<string daysoftheweek = {};
    cout << "+------------+------------+------------+------------+------------+------------+\n" <<
            "|            |   Segunda  |   Terça    |   Quarta   |   Quinta   |    Sexta   |\n" <<
            "+------------+------------+------------+------------+------------+------------+\n";


    for(size_t i = 0; i < 24;i++){

        cout << "|" << time << "|";

    }
}

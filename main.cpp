#include "DataProcessor.h"

int main(){
    DataProcessor parseData;

    Schedule schedule;
    //cout << schedule.centerString("L.EIC001 - TP") << "\n";
    schedule.printSchedule();

    parseData.students_classes();
    parseData.classes();
    for (auto ball :parseData.getSchedule()){
        cout << ball.getClassCode() << endl;
    }
    parseData.studentsInUc(5);
    parseData.studentsInClass("1LEIC04");
    parseData.studentsInCourse("leiC");
    parseData.studentsInYear("2019");
}
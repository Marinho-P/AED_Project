#include "DataProcessor.h"

int main(){
    DataProcessor parseData;

    Schedule schedule;
    //cout << schedule.centerString("L.EIC001 - TP") << "\n";
    schedule.printSchedule();
    parseData.students_classes();
    parseData.classes();
    parseData.classes_per_uc();
    for (auto ball :parseData.getSchedule()){
        cout << ball.getClassCode() << endl;
    }
    //parseData.studentsInUc(9);
    parseData.studentsInClass("1LEIC021");
    //parseData.studentsInCourse("leiccc");
    //parseData.studentsInYear("2018");
    parseData.ucGreatestNumberStudents();
}
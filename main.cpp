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
}
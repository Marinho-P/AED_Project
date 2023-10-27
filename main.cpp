#include "DataProcessor.h"

int main(){
    DataProcessor parseData;
    parseData.students_classes();
    parseData.classes();
    for (auto ball :parseData.getSchedule()){
        cout << ball.getClassCode() << endl;
    }
    parseData.studentsInUc(5);
    parseData.studentsInClass("1LEIC04");
}
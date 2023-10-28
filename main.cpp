#include "DataProcessor.h"

int main(){
    DataProcessor parseData;

    parseData.getSchedules().begin()->printSchedule();

    parseData.students_classes();
    parseData.classes();

    //parseData.studentsInUc(9);
    //parseData.studentsInClass("1LEIC021");
    //parseData.studentsInCourse("leiccc");
    //parseData.studentsInYear("2018");
}
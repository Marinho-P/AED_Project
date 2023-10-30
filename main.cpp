#include "Menu.h"

int main(){
    Menu menu;
    DataProcessor parseData;
    //menu.run();
    //parseData.getSchedules().begin()->printSchedule();
    //parseData.students_classes();
    //parseData.classes();
    //cout << schedule.centerString("L.EIC001 - TP") << "\n";
    //parseData.students_classes();
    //parseData.classes();
    //parseData.classes_per_uc();
    //parseData.studentsInUc(9);
    //parseData.studentsInClass("1LEIC021");
    for (const Student &student: parseData.getStudents()){
        cout << student.getName() << endl;
        parseData.scheduleOfStudent(student);
    }
    //parseData.studentsInCourse("leiccc");
    //parseData.studentsInYear("2018");
    //parseData.ucGreatestNumberStudents();
    //for (Schedule schedule:parseData.getSchedules()){
    //    schedule.printSchedule();
    //}
}
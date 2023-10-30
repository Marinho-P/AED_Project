#include "Menu.h"

int main(){
    //Menu menu;
    DataProcessor parseData;
    //menu.run();
    //parseData.getSchedules().begin()->printSchedule();
    //parseData.students_classes();
    //parseData.classes();
    //cout << schedule.centerString("L.EIC001 - TP") << "\n";
    //parseData.students_classes();
    //parseData.classes();
    //parseData.classes_per_uc();
    Student student = Student("202079292","Jose Teofilo");
    student.addClassUc(Class_UC("L.EIC023","3LEIC14"));
    student.addClassUc(Class_UC("L.EIC024","3LEIC08"));
    const Student &ball = student;
    parseData.scheduleOfStudent(ball);
    //parseData.studentsInUc(9);
    //parseData.studentsInClass("1LEIC021");
    //parseData.studentsInCourse("leiccc");
    //parseData.studentsInYear("2018");
    //parseData.ucGreatestNumberStudents();
    //for (Schedule schedule:parseData.getSchedules()){
    //    schedule.printSchedule();
    //}
}
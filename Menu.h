
#ifndef AED2324_P03_MENU_H
#define AED2324_P03_MENU_H
#include "Schedule.h"
#include "Student.h"
#include "DataProcessor.h"

class Menu{
private:
    DataProcessor dataProcessor;
public:
    Menu();
    int run();
    void ClassSchedule();
//    void input() const;
    void CheckStudent();
    int options() const;
//    int sorting() const;
    //  int requests() const;
    //  void checkUcSchedule() const;
    //void checkUcStudents() const;
    //void checkClassSchedule() const;
    //void checkClassStudents() const;
    //void checkStudentSchedule() const;
    //void changeRequest(Student* student);
    //void removeRequest(Student* student);
    //void newRequest(int option);
    //void enrollmentRequest(Student* student);
    //void processRequests();
    //void printPendingRequests() const;
    //void save();
private:
    Schedule manager;
};
#endif //AED2324_P03_MENU_H

#ifndef AED2324_P03_MENU_H
#define AED2324_P03_MENU_H
#include "Schedule.h"
#include "Student.h"
#include "DataProcessor.h"
#include "requests.h"

class Menu{
private:
    DataProcessor dataProcessor;
public:
    Menu();
    int run();
    void ClassSchedule();
    void CheckStudent();
    int options() const;
    void CheckStudentSchedule();
    int requestsMenu();



    //void checkUcStudents() const;
    //void checkClassSchedule() const;
    //void checkClassStudents() const;

    void changeRequest(Student* student);
    void removeRequest(Student* student);
    void newRequest(int option);
    void enrollmentRequest(Student* student);
    //void processRequests();
    //void printPendingRequests() const;
    //void save();
    //void exit();
};
#endif //AED2324_P03_MENU_H
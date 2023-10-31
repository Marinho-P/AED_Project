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
    void CheckStudent();
    int options() const;
    int sorting() const;
    void checkClassSchedule() const;
    void checkClassStudents() const;
    void checkStudentSchedule() const;
    //void save();
};
#endif //AED2324_P03_MENU_H
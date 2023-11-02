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
private:
    void requests();
    void addRequestoList();
    void processRequests();
    void discardRequests();
    void listPendingRequests();
    void listSuccessfullRequests();
    void undoRequest();
    void CheckStudent();
    int options() const;
    string sorting() const;
    void checkStudentSchedule();
};
#endif //AED2324_P03_MENU_H
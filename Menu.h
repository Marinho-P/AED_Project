#ifndef AED2324_P03_MENU_H
#define AED2324_P03_MENU_H
#include "Schedule.h"
#include "Student.h"
#include "DataProcessor.h"

/**
 * @brief Class that serves as the interactive menu for the user
 */

class Menu{
private:
    /** @brief Attribute that can access all data processed */
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
    void countStudentsInAtLeastNUCs();
    void checkGreatestUc();
};
#endif //AED2324_P03_MENU_H
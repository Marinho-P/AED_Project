#ifndef AED2324_P03_MENU_H
#define AED2324_P03_MENU_H
#include "Schedule.h"
#include "Student.h"
#include "DataProcessor.h"
/**
 * @class Menu
 * @brief A class for handling the menu and user interaction.
 */
class Menu{
private:
    DataProcessor dataProcessor;
    /** @brief Data processor object for handling data. */

public:
    Menu();
    int run();
    void ClassSchedule();
    void CheckStudent();
    int options() const;
    void checkClassSchedule() const;
    void checkClassStudents() const;
    void checkStudentSchedule() const;
    //void save();
};
#endif //AED2324_P03_MENU_H
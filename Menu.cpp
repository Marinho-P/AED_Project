#include "Menu.h"
#include <iostream>

using namespace std;
Menu ::Menu() {
}


int Menu::run() {
        while (true) {
            int option = options();
            switch (option) {
                case 0:{
                    cout << ">> Exiting the menu." << endl;
                    return 0;
                }
                case 1: {

                //checkUcSchedule();

                    //input();
                    break;
                }
                case 2: {
                    CheckStudent();
                    break;
                }
                case 3: {
                    ClassSchedule();

                    break;
                }
                case 4: {
                    //checkClassStudents();
                    //input();
                    break;
                }
                case 5: {
                    //checkStudentSchedule();
                    //input();
                    break;
                }
                case 6:{
                    //int i = requests();
                    //if(i != 4) {
                    //    newRequest(i);
                    //}
                    break;
                }
                case 7: {
                    //printPendingRequests();
                    break;
                }
                case 8:{
                    //processRequests();
                    break;
                }
                case 9: {
                    //save();
                    return 0;
                }
                default:
                    cout << ">> Invalid option try again." << endl;
            }
        }
    }
int Menu::options() const{
    int choice;
    cout << "Menu Options:" << endl;
    cout << "1. Check UC Schedule" << endl; // not possible? (overlapping schedules)
    cout << "2. Check Students" << endl;
    cout << "3. Check Class Schedule" << endl;
    cout << "4. Check Class Students" << endl;
    cout << "5. Check Student Schedule" << endl;
    cout << "6. Requests" << endl;
    cout << "7. Print Pending Requests" << endl;
    cout << "8. Process Requests" << endl;
    cout << "9. Save" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}
void Menu::ClassSchedule() {
    string classCode;
    cout << "Enter a Class code:";
    cin >> classCode;
    cout << "\n";
    dataProcessor.scheduleOfClass(classCode);
}
void Menu::CheckStudent() {
    cout << "1. See all students in a class" << endl;
    cout << "2. See all students in a year" << endl;
    cout << "3. See all students in a course" << endl;
    cout << "Enter your choice:";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: {
            string classCode;
            cout << "Enter a class code:";
            cin >> classCode;
            cout << "\n";
            dataProcessor.studentsInClass(classCode);
            break;
        }
        case 2:{
            string year;
            cout << "Enter a year (ex. 2020):";
            cin >> year;
            cout << "\n";
            dataProcessor.studentsInYear(year);
            break;
        }
        case 3:{
            string course;
            cout << "Enter a course (ex. LEIC):";
            cin >> course;
            cout << "\n";
            dataProcessor.studentsInCourse(course);
            break;
        }
        default:{
            cout << "Invalid option" << endl;
        }




    }
}


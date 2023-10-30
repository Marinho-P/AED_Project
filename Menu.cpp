#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu(const Schedule &manager) {
    this->manager = manager;
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
                    //checkUcStudents();
                    //input();
                    break;
                }
                case 3: {
                    //checkClassSchedule();
                    //input();
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
    cout << "1. Check UC Schedule" << endl;
    cout << "2. Check UC Students" << endl;
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

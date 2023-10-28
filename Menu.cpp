#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu(const Schedule &manager) {
    this->manager = manager;
}

int Menu::run(){
    int Menu::run() {
        while (true) {
            int option = optionsMenu();
            switch (option) {
                case 1: {
                    checkUcShedule();
                    input();
                    break;
                }
                case 2: {
                    checkUcStudents();
                    input();
                    break;
                }
                case 3: {
                    checkClassSchedule();
                    input();
                    break;
                }
                case 4: {
                    checkClassStudents();
                    input();
                    break;
                }
                case 5: {
                    checkStudentSchedule();
                    input();
                    break;
                }
                case 6:{
                    int i = requests();
                    if(i != 4) {
                        newRequest(i);
                    }
                    break;
                }
                case 7: {
                    printPendingRequests();
                    break;
                }
                case 8:{
                    processRequests();
                    break;
                }
                case 9: {
                    save;
                    return 0;
                }
                default:
                    cout << ">> Submit a valid option." << endl;
            }
        }
    }
}
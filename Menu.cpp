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
                CheckStudent();
                break;
            }
            case 2: {
                ClassSchedule();

                break;
            }
            case 3: {
                CheckStudentSchedule();
                break;
            }
            case 4:{
                int i = requestsMenu();
                if(i != 0) {
                    requestsMenu();
                }
                break;
            }
            case 5: {
                //printPendingRequests();
                break;
            }
            case 6:{
                //processRequests();
                break;
            }
            case 7: {
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
    cout << "1. Check Students" << endl;
    cout << "2. Check Class Schedule" << endl;
    cout << "3. Check Student Schedule" << endl;
    cout << "4. Requests" << endl;
    cout << "5. Print Pending Requests" << endl;
    cout << "6. Process Requests" << endl;
    cout << "7. Save" << endl;
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
        case 2: {
            string year;
            cout << "Enter a year (ex. 2020):";
            cin >> year;
            cout << "\n";
            dataProcessor.studentsInYear(year);
            break;
        }
        case 3: {
            string course;
            cout << "Enter a course (ex. LEIC):";
            cin >> course;
            cout << "\n";
            dataProcessor.studentsInCourse(course);
            break;
        }
        default: {
            cout << "Invalid option" << endl;
        }
    }
}

void Menu::CheckStudentSchedule(){
    string upNumber;
    cout << "Insert the student's UP number: ";
    cin >> upNumber;
    dataProcessor.scheduleOfStudent(upNumber);
}
int Menu::requestsMenu(){
    int option;
    cout << "What changes do you want to make to your schedule?:" << endl;
    cout << "1 - Change class" << endl;
    cout << "2 - Enroll in a new uc" << endl;
    cout << "3 - Cancel a uc registration" << endl;
    cout << "0 - Go back" << endl;
    cin >> option;
    if (cin.fail()) {
        throw invalid_argument(">> Invalid number");
    }
    while(option < 0 || option > 3) {
        cout << ">> Submit a valid option: "; cin >> option; cout << endl;
    }
    return option;
}
void Menu::changeRequest(Student *student) {

}


void Menu::enrollmentRequest(Student *student) {

}


void Menu::removeRequest(Student *student) {

}



void Menu::newRequest(int option) {
    string upNumber;
    cout << "Insert the student's UP number: ";
    cin >> upNumber;
    cout << endl;
    Student *student = dataProcessor.findStudent(upNumber);
    if (student == nullptr) {
        cout << ">> Student not found." << endl;
        return;
    }

    switch (option) {
        case 1:
            changeRequest(student);
            break;
        case 2:
            enrollmentRequest(student);
            break;
        case 3:
            removeRequest(student);
            break;
        default:
            cout << ">> Invalid option." << endl;
    }
}

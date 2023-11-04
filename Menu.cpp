#include "Menu.h"
#include <iostream>
#include <limits>
using namespace std;
/**
 * @brief Class constructor of class Menu - call the constructor of DataProcessor implicitly
 * @details Time complexity - O(n+m*log(h)+w) with n, m, w being the number of lines of students_classes.csv, classes.csv, classes_per_uc.csv respectively and h the number of all classes' schedules
 */

Menu ::Menu() {

}

/**
 * @brief Menu that handles all of the program's functionality
 * @details If option 1 is picked : Time complexity - O(w) where w is the number of existing students
 * If option 2 is picked: Time complexity - O(n*log(n)) with n being number of students that fit a given restriction (Class,year,course,Uc) (Worst case scenario)
 * If option 3 is picked: Time complexity - O(n+m) with n being the number of all classes' schedules and m the number of lectures in a schedule
 * If option 4 is picked: Time complexity - O(n*log(k)+m*log(m)) with n being the number of classUCs of a student, k the number of schedules of a class and m the number of Lectures to print
 * If option 5 is picked: Time complexity - Refer to time complexity of requests()
 * If option 6 is picked: Time complexity - O(n*m) with n being the number of existing students and m the number of ClassUcs of a student
 */
int Menu::run() {
    while (true) {
        int option = options();
        switch (option) {
            case 0: {
                cout << ">> Exiting the menu." << endl;
                return 0;
            }
            case 1: {
                countStudentsInAtLeastNUCs();
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
                checkStudentSchedule();
                break;
            }
            case 5: {
                requests();
                break;
            }
            case 6:{
                checkGreatestUc();
                break;
            }
            default:
                cout << ">> Invalid option try again." << endl;
        }
    }
}
/**
 * @brief Prints in the terminal which options the user has [0,6]
 * @details Time complexity - O(1)
 * @return input of user
 */
int Menu::options() const{
    int choice;
    cout << "Menu Options:" << endl;
    cout << "1. Check number of students in at least n UCs" << endl;
    cout << "2. Check Students" << endl;
    cout << "3. Check Class Schedule" << endl;
    cout << "4. Check Student Schedule" << endl;
    cout << "5. Requests" << endl;
    cout << "6. Check the UCs with the greatest number of students" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice:";
    cin >> choice;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 7;
    }
    return choice;
}
/**
 * @brief Receives a classCode from the user and prints the class Schedule
 * @details Time complexity - O(n+m) with n being the number of all classes' schedules and m the number of lectures in a schedule
 */
void Menu::ClassSchedule(){
    string classCode;
    cout << "Enter a Class code:";
    cin >> classCode;
    cout << "\n";
    dataProcessor.scheduleOfClass(classCode);
}
/**
 * @brief Receives an input from the user from [1,3] else goes to the starting menu. Gives various options to search students such as:
 * See all students in a class/year/course.
 * It displays the students based on the selected option and sorting preference
 * @details Time complexity - O(n*log(n)) with n being number of students that fit a given restriction (Class,year,course,Uc) (Worst case scenario)
 */
void Menu::CheckStudent() {
    cout << "1. See all students in a class" << endl;
    cout << "2. See all students in a year" << endl;
    cout << "3. See all students in a course" << endl;
    cout << "4. See all students in a UC" << endl;
    cout << "Press any other key to return to menu" << endl;
    cout << "Enter your choice:";
    int choice;
    cin >> choice;
    cout << endl;

    switch (choice) {
        case 1: {
            string classCode;
            cout << "Enter a class code:";
            cin >> classCode;
            cout << "\n";
            string sort = sorting();
            if (sort == "exit"){
                cout << ">> Returning to menu." << endl;
                return;
            }
            dataProcessor.studentsInClass(classCode,sort);
            break;
        }
        case 2:{
            string year;
            cout << "Enter a year (ex. 2020):";
            cin >> year;
            cout << "\n";
            string sort = sorting();
            if (sort == "exit"){
                cout << ">> Returning to menu." << endl;
                return;
            }
            dataProcessor.studentsInYear(year,sort);
            break;
        }
        case 3:{
            string course;
            cout << "Enter a course (ex. LEIC):";
            cin >> course;
            cout << "\n";
            string sort = sorting();
            if (sort == "exit"){
                cout << ">> Returning to menu." << endl;
                return;
            }
            dataProcessor.studentsInCourse(course,sort);
            break;
        }
        case 4:{
            string UC;
            cout << "Enter a UC (ex. L.EIC001):";
            cin >> UC;
            cout << "\n";
            string sort = sorting();
            if (sort == "exit"){
                cout << ">> Returning to menu." << endl;
                return;
            }
            dataProcessor.studentsInUc(UC,sort);
        }
        default:{
            cout << ">> Returning to menu" << endl;
        }
    }
}
/**
 * @brief Menu that handles all request functionality
 * @details If option 1 is picked : Time complexity - O(1)
 * If option 2,3 or 4  is picked: Time complexity - O(n) where n is the number of pending requests
 * If option 5 or 6 is picked: Time complexity - O(k) where k is the number of successful requests in 'RequestHistory.csv'
 */

void Menu :: requests(){
    cout << "1. Add new request to list of pending requests" << endl;
    cout << "2. Process request(s)" << endl;
    cout << "3. Discard request(s)" << endl;
    cout << "4. List pending requests" << endl;
    cout << "5. List successful requests" << endl;
    cout << "6. Undo Successful request" << endl;
    cout << "Press any other key to return to menu" << endl;
    cout << "Enter your choice:" ;
    int option;
    cin >> option;
    cout << endl;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Incorrect input >> Returning to menu" << endl;
        return;
    }
    switch(option){
        case 1:{
            addRequestoList();
            break;
        }
        case 2:{
            processRequests();
            break;
        }
        case 3:{
            discardRequests();
            break;
        }
        case 4:{
            listPendingRequests();
            break;
        }
        case 5:{
            listSuccessfullRequests();
            break;
        }
        case 6:{
            undoRequest();
        }
         default:{
            cout << ">> Returning to menu" << endl;
            break;
        }

    }
}
/**
 * @brief Adds a pending request to a vector containing all pending requests
 * @details Time complexity - O(1)
 */
void Menu::addRequestoList() {
    string id;
    cout << "Enter student id:";
    cin >> id;
    cout << endl;
    Student find_Student = Student();
    find_Student.setId(id);
    auto it  =  dataProcessor.getStudents().find(find_Student);
    if (it == dataProcessor.getStudents().end()) {
        cout << "Student not found" << endl;
        return;
    }
    cout << "1. Change class of an UC" << endl;
    cout << "2. Enroll in a new UC" << endl;
    cout << "3. Leave UC" << endl;
    cout << "Press any other key to return to menu" << endl;
    cout << "Enter your choice:";
    int choice;
    cin >> choice;
    cout << endl;
    switch (choice) {
        case 1:{
            string UcCode,startCode,endCode;
            cout << "Enter the UcCode:";
            cin  >> UcCode;
            cout << endl << "Enter the classCode of the class that will be changed:";
            cin >> startCode;
            cout << endl << "Enter the classCode of the new class:";
            cin >> endCode;
            cout << endl;


            dataProcessor.addPendingRequest(Request(const_cast<Student&> (*it),"switch",UcCode,startCode, endCode ));


            break;
        }
        case 2:{
            string UcCode;
            cout << "Enter a UcCode:";
            cin >> UcCode;
            cout << endl;


            dataProcessor.addPendingRequest(Request(const_cast<Student&> (*it),"add",UcCode,"-", "-" ));

            break;

        }
        case 3:{
            string UcCode;
            cout << "Enter a UcCode:";
            cin >> UcCode;
            cout << endl;

            dataProcessor.addPendingRequest(Request(const_cast<Student&> (*it),"remove",UcCode,"-", "-" ));

            break;
        }
        default:{
            cout << ">> Returning to menu" << endl;
            break;
        }
    }


}
/**
 * @brief Processes one or all requests at once given a RequestId else doesn't do any if invalid RequestId
 * RequestId = 0 (Process all requests)
 * @details Time complexity - O(n) with n being the number of pending requests
 */
void Menu::processRequests() {
    int RequestId;
    cout << "Enter a Pending Request Id ( or 0 for all requests):";
    cin >> RequestId;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Incorrect input >> Returning to menu" << endl;
    }
    else{
        dataProcessor.processRequest(RequestId);
    }

}
/**
 * @brief Discards one or all pending requests stored in the vector PendingRequests
 * @details Time complexity - O(n) with n being the number of all stored pending requests
 */
void Menu::discardRequests() {
    int RequestId;
    cout << "Enter a Pending Request Id ( or 0 for all requests):";
    cin >> RequestId;
    cout << endl;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Incorrect input >> Returning to menu" << endl;
    }
    else{
        dataProcessor.discardRequest(RequestId);
    }
}
/**
 * @brief Prints all current stored pending requests having two different formats between switch and add/remove
 * @details Time complexity - O(n) with n being the number of requests currently stored
 */
void Menu::listPendingRequests() {
    dataProcessor.printPendingRequests();

}
/**
 * @brief Lists all successful requests saved in 'RequestHistory.csv'
 * @details Time complexity - O(n) where n is the number of lines in 'RequestHistory.csv'
 */
void Menu::listSuccessfullRequests() {
    dataProcessor.lookupAllRequests();

}
/**
 * @brief Given a request id, it undoes that request
 * @details Time complexity - O(n) where n is the number of successful request kept in 'RequestHistory.csv'
 */
void Menu::undoRequest() {
    int RequestId;
    cout << "Enter a successful Request Id:";
    cin >> RequestId;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Incorrect input >> Returning to menu" << endl;
    }
    else{
        dataProcessor.undoRequest(RequestId);

    }

}

/**
 * @brief Gives the user a sorting option
 * @details Time complexity - O(1)
 * @return type of sorting : "A to Z", "Z to A", "Numerical", "Numerical in reverse"
 */

string Menu::sorting() const {
    cout << "1. A to Z" << endl;
    cout << "2. Z to A" << endl;
    cout << "3. Numerical" << endl;
    cout << "4. Numerical in reverse" << endl;
    cout << "Press any other key to return to menu" << endl;
    cout << "In which order do you want the students to be displayed? ";
    int option; cin >> option; cout << endl;
    switch (option) {
        case 1:
            return "A to Z";
        case 2:
            return "Z to A";
        case 3:
            return "numerical";
        case 4:
            return "reverse numerical";
        default:{
            return "exit";
        }
    }
}
/**
 * @brief Checks a student's schedule given their Id/UpNumber
 * @details Time complexity - O(n*log(k)+m*log(m)) with n being the number of classUCs of a student, k the number of schedules of a class and m the number of Lectures to print
 */
void Menu::checkStudentSchedule()  {
    string upNumber;
    cout << "Insert the student's UP number: ";
    cin >> upNumber;
    cout << endl;
    Student student = Student();
    student.setId(upNumber);
    auto it = dataProcessor.getStudents().find(student);
    if(it == dataProcessor.getStudents().end()){
        cout << "Student not found >> Returning to menu" << endl;
    }
    else{
        dataProcessor.scheduleOfStudent(*(it));

    }
}
/**
 * @brief Checks how many students are in at least N UCs. N is a given input by the user
 * @details Time complexity - O(w) with w being the total number of existing students
 */
void Menu::countStudentsInAtLeastNUCs() {
    int n;
    cout << "Enter n:";
    cin >> n;
    cout << endl;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Incorrect input >> Returning to menu" << endl;
    }
    else{
        dataProcessor.studentsInAtLeastNUCs(n);
        cout << ">> Returning to menu" << endl;
    }

}
/**
 * @brief Checks the UC with the most students enrolled
 * @details Time complexity - O(n*m) with n being the number of existing students and m the number of ClassUcs of a student
 */
void Menu::checkGreatestUc() {
    dataProcessor.ucGreatestNumberStudents();
}


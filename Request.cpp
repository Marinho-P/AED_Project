//
// Created by sergio on 29-10-2023.
//
static int Cap = 25;
#include <fstream>
#include <sstream>
#include "Request.h"
// each line of RequestHistory.csv goes : id, StudentName, type (add, remove or switch), recipient( UC or class), startCode, endCode
Request:: Request(const DataProcessor &dataProcessor){
    this->dataProcessor = dataProcessor;
}
void Request::AddRequest(Student &student, string &UcCode ) {
    for(const Class_UC &classUc: student.getClassesUcs()){
        if(classUc.getUcCode() == UcCode){
            cout << "Request denied: Student is already enrolled in specified UC" << endl;
        }
    }
    if(student.getClassesUcs().size() >= 7){
        cout << "Request denied: A student cannot be registered in more than 7 UCs at any given time" << endl;
        return;
    }
    for(  const Schedule &schedule: dataProcessor.getSchedules()){
        Schedule old_schedule = dataProcessor.createStudentSchedule(student);
        if(checkAdd(student,schedule.getClassCode())){
            if(checkScheduleCollisions( FuseSchedules(old_schedule,schedule,UcCode) )){
                student.addClassUc(Class_UC(schedule.getClassCode(), UcCode));
                saveRequest(student,  "add",  "UC", UcCode, (string &) "");
                ChangeFile(student, schedule.getClassCode(), UcCode, "add");
                cout << "Request accepted" << endl;
                return;
            }
        }

    }
    cout << "Request denied: No class with vacancy found" << endl;

    // TODO: check if possible to remove and, if so, alter internal memory and files ( output: ACCEPTED or DENIED)

}
void Request::RemoveRequest(Student &student, const string& UcCode){
    bool check = false;
    string classCode;
    for( const Class_UC &classUc: student.getClassesUcs()){
        if(classUc.getUcCode() == UcCode){
            check = true;
            classCode = classUc.getUcCode();
            break;
        }
    }
    if(!(check)){
        cout << "Request denied: Student isn't enrolled on specified UC";
        return;
    }
    if(checkRemove(student,classCode)){
        for(auto it = student.getClassesUcs().begin();it != student.getClassesUcs().end();){ // removes Uc from student
            if(it->getUcCode() == UcCode){
                it = student.removeClassUc(it);
            }
            else{
                ++it;
            }
        }
        saveRequest(student,  "remove",  "UC", UcCode, "");

        cout << "Request accepted" << endl;
    }
    else{
        cout << "Request denied: removing Student from UC would disturb the balance between classes" << endl;
    }

}
void Request::SwitchRequest(const Student &student, const string &) {

}




void Request::lookupAllRequests() {
    ifstream file("RequestHistory.csv");
    if(!(file.is_open())){
        cout << "Couldn't find 'RequestHistory.csv' file";
        return ;
    }
    string line;
    int RequestID = 1;
    while(getline(file, line)){
        istringstream separate_comma(line);
        string StudentName, id, type , recipient, startCode, endCode;

        if(type == "switch"){

            getline(separate_comma, id, ',');
            getline(separate_comma, StudentName, ',');
            getline(separate_comma, type, ',');
            getline(separate_comma, recipient, ',');
            getline(separate_comma, startCode, ',');
            separate_comma >> endCode;
            cout <<"RequestID:" << RequestID << " Student Name:" <<  StudentName << "(" << id << ") Type: switch(" << recipient << ") " << startCode << " -> " << endCode;
        }
        else{
            getline(separate_comma, id, ',');
            getline(separate_comma, StudentName, ',');
            getline(separate_comma, type, ',');
            getline(separate_comma, recipient, ',');
            separate_comma >> startCode;
            cout <<"RequestID:" << RequestID << " Student Name:" << StudentName << "(" << id << ") Type: "<< type << "(" << recipient << ") " << startCode;

        }
        RequestID++;


    }



}



void Request::saveRequest(const Student &student, const string &type, const string &recipient,const  string &startCode,const string &endCode) {
    ofstream file("RequestHistory.csv");
    if(!(file.is_open())) {
        cout << "Couldn't find 'RequestHistory.csv' file";
        return;
    }
    if(type == "switch"){
        file << student.getId() <<"," <<student.getName() << "," << recipient << "," << startCode << "," << endCode << endl;

    }
    else{
        file << student.getId() <<"," <<student.getName() << "," << recipient << "," << startCode << endl;

    }
    file.close();

}

void Request::undoRequest(int RequestID) {
    int counter = 1;
    ifstream file("RequestHistory.csv");
    ofstream temp("tempFile.csv");
    if(!(file.is_open())) {
        cout << "Couldn't find 'RequestHistory.csv' file";
        return;

    }
    string line;
    while(getline(file,line))   {
        if(counter == RequestID){ // skipped adding line
            // TODO: performRequest() (reversed)
        }
        else{
            temp << line;
        }
    }
    remove("RequestHistory.csv");
    rename("tempFile.csv","RequestHistory.csv");
}
bool compareLectures(const Lecture& a, const Lecture& b) {
    if (a.getWeekday() == b.getWeekday()) {
        return a.getStartHour() < b.getStartHour();
    }
    return a.getWeekday() < b.getWeekday();
}
bool Request :: checkScheduleCollisions( vector<Lecture> lectures){
    sort(lectures.begin(),lectures.end(),compareLectures);
    for (size_t i = 0; i < lectures.size() - 1; ++i) {
        const Lecture& currentLecture = lectures[i];
        const Lecture& nextLecture = lectures[i + 1];

        // Check for overlap on the same day
        if (currentLecture.getWeekday() == nextLecture.getWeekday()) {
            float currentEndTime = currentLecture.getStartHour() + currentLecture.getDuration();
            if (currentEndTime > nextLecture.getStartHour()) {
                return true; // Overlapping lectures found
            }
        }
    }

    return false; // No overlapping lectures found

}
bool Request:: checkAdd(const Student &studentToAdd, const string &classCode ){
    for( const Class_UC &classUc : studentToAdd.getClassesUcs()){ // if student is already in a class then it's always available
        if(classCode == classUc.getClassCode()){
            return true;
        }
    }
    unordered_map<string,int> numberOfStudentsPerClass;
    numberOfStudentsPerClass = getNumberOfStudents(numberOfStudentsPerClass);

    numberOfStudentsPerClass[classCode]++; // add student to desired class



    return checkBalanceAndCap(numberOfStudentsPerClass);

}

unordered_map<string, int> &Request::getNumberOfStudents(unordered_map<string, int> &numberOfStudentsPerClass) {
    for (const Student& student: dataProcessor.getStudents()){ // get number of students per class
        set<string> ClassesPerStudent;
        for (const Class_UC& classUc :student.getClassesUcs() ){
            if(ClassesPerStudent.find(classUc.getClassCode()) == ClassesPerStudent.end()){
                ClassesPerStudent.insert(classUc.getClassCode());
            }

        }
        for(const string& C :ClassesPerStudent ){
            numberOfStudentsPerClass[C]++;
        }

    }
    return numberOfStudentsPerClass;
}

bool Request::checkBalanceAndCap(unordered_map<string, int> &numberOfStudentsPerClass) const {
    string ClassWithMostStudents;
    string ClassWithLeastStudents;
    int MostStudents = INT_MIN;
    int LeastStudents = INT_MAX;
    for( const auto& pair: numberOfStudentsPerClass){
        if(pair.second > MostStudents){
            ClassWithMostStudents = pair.first;
            MostStudents = pair.second;
        }
        if(pair.second < LeastStudents){
            ClassWithLeastStudents = pair.first;
            LeastStudents = pair.second;
        }
    }
    if(MostStudents-LeastStudents > 4 || MostStudents > Cap){
        return false;
    }
    else{
        return true;
    }
}

vector<Lecture> Request :: FuseSchedules(const Schedule &old_schedule, const Schedule &schedule_to_add, string &UcCode){
    vector<Lecture> result = old_schedule.getLectures();
    for(const Lecture &lecture: schedule_to_add.getLectures()){
        if(UcCode == lecture.getUcCode()){
            result.push_back(lecture);
        }
    }
    return  result;
}
void Request :: ChangeFile( Student &student, const string &NewClassCode, const string &NewUcCode, const string &type) {
    ifstream file("students_classes.csv");
    ofstream temp("tempFile.csv");
    string line;
    while(getline(file,line)){
        istringstream separate_comma;
        string id, StudentName, UcCode , ClassCode;
        separate_comma >> id;
        separate_comma.ignore();
        separate_comma >> StudentName;
        separate_comma.ignore();
        separate_comma >> UcCode;
        separate_comma.ignore();
        separate_comma >> ClassCode;

        if( id == student.getId() & type == "add"){
            temp << id << "," << StudentName << "," << NewUcCode << "," << NewClassCode << endl;
        }
        if (UcCode == NewUcCode & id == student.getId() & type == "remove" ){
            continue;
        }
        if( type == "switch" & )
        temp << line;
    }
    remove("student_classes.csv");
    rename("tempFile.csv","students_classes.csv");
}

bool Request::checkRemove(const Student &student, const string &classCode) {
    unordered_map<string,int> numberOfStudentsPerClass;
    numberOfStudentsPerClass = getNumberOfStudents(numberOfStudentsPerClass);

    numberOfStudentsPerClass[classCode]--; // remove  student from desired class



    return checkBalanceAndCap(numberOfStudentsPerClass);
}


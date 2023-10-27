#include "DataProcessor.h"


DataProcessor::DataProcessor(){}

void DataProcessor::classes_per_uc() {

}

const set<Class_UC> &DataProcessor::getClassUc() const{
    return classes_uc;
}

const set<Schedule> &DataProcessor::getSchedule() const{
    return schedules;
}

void DataProcessor::students_classes() {
    ifstream file("students_classes.csv");
    string header;
    getline(file,header);
    string line;
    Student lastSeenStudent;
    set<Class_UC> setOfClasses;
    bool first_it = true;
    while (getline(file,line)){
        istringstream separate_comma(line);
        string ucCode,classCode,studentName,studentCode;
        getline(separate_comma,studentCode,',');
        getline(separate_comma,studentName,',');
        getline(separate_comma,ucCode,',');
        getline(separate_comma,classCode,',');
        if(first_it) {
            setOfClasses.insert(Class_UC(classCode, ucCode));
            lastSeenStudent = Student(studentName, studentCode, setOfClasses);
            first_it = false;
        }

        if (lastSeenStudent.getId() == studentCode){
            lastSeenStudent.addClassUc(Class_UC(classCode,ucCode));
        } else{
            students.insert(lastSeenStudent);
            setOfClasses = set<Class_UC>();
            lastSeenStudent = Student(studentName,studentCode,setOfClasses);
            lastSeenStudent.addClassUc(Class_UC(classCode,ucCode));
        }

    }
    students.insert(lastSeenStudent);

}

void DataProcessor::classes(){
    ifstream file("classes.csv");
    string header;
    getline(file,header);
    string line;
    while (getline(file,line)){
        istringstream separate_comma(line);
        string classCode,ucCode,weekday,startHour,duration,type;
        getline(separate_comma,classCode,',');
        getline(separate_comma,ucCode,',');
        getline(separate_comma,weekday,',');
        getline(separate_comma,startHour,',');
        getline(separate_comma,duration,',');
        getline(separate_comma,type,',');
        Lecture lecture = Lecture(duration,startHour,type,weekday,ucCode);
        auto it = schedules.find(Schedule(classCode));
        if (it != schedules.end()) {
            Schedule modifiedSchedule = *it;
            modifiedSchedule.addLecture(lecture);
            it = schedules.erase(it);
            schedules.insert(modifiedSchedule);
        } else {
            Schedule newSchedule(classCode);
            newSchedule.addLecture(lecture);
            schedules.insert(newSchedule);
        }
    }
}

void DataProcessor::studentsInUc(int n) {
    int res = 0;
    for (const Student& student: students){
        if (student.getClassesUcs().size() >= n){
            res++;
        }
    }
    cout << res << endl;
}

const set<Student> &DataProcessor::getStudents() const {
    return students;
}

void DataProcessor::studentsInClass(const string& classCode) {
    cout << "Students in class " << classCode << " are:" << endl;
    vector<Student> temp;
    for (const Student& student:students){
        for (const Class_UC& classUc:student.getClassesUcs()){
            if (classCode == classUc.getClassCode()){
                temp.push_back(student);
                break;
            }
        }
    }
    sort(temp.begin(),temp.end(),[](const Student& a ,const Student& b){return a.getName()<b.getName();});
    if (!temp.empty()){
        cout << "------------------------------" << endl;
        cout << "Name / ID" << endl;
        cout << "------------------------------" << endl;
        for (const Student& student : temp){
            cout << student.getName() << " / " << student.getId() << endl;
        }
        cout << "------------------------------" << endl;
    }
    else {
        cout << "No students in this class." << endl;
    }
}
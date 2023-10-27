#include "DataProcessor.h"


DataProcessor::DataProcessor(){}

void DataProcessor::classes_per_uc() {

}

set<Class_UC> DataProcessor::getClassUc(){
    return classes_uc;
}

set<Schedule> DataProcessor::getSchedule(){
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
        string classCode,ucCode,weekday,type;
        float duration,startHour;
        separate_comma >> classCode;
        separate_comma.ignore(1);
        separate_comma >>  ucCode;
        separate_comma.ignore(1);
        separate_comma >> weekday;
        separate_comma.ignore(1);
        separate_comma >> startHour;
        separate_comma.ignore(1);
        separate_comma >> duration;
        separate_comma.ignore(1);
        separate_comma >> type;
        separate_comma.ignore(1);
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
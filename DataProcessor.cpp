#include "DataProcessor.h"


DataProcessor::DataProcessor(){
    students_classes();
    classes();
}

void DataProcessor::classes_per_uc() {
    ifstream file("classes_per_uc.csv");
    string header;
    getline(file,header);
    string line;
    while (getline(file,line)){
        istringstream separated_comma(line);
        string classCode , ucCode;
        getline(separated_comma,ucCode,',');
        getline(separated_comma,classCode,',');
        existingClassesUc.insert(Class_UC(classCode,ucCode));
    }
}

const set<Class_UC> &DataProcessor::getClassUc() const{
    return existingClassesUc;
}

const set<Schedule> &DataProcessor::getSchedules() const{
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
        getline(separate_comma, classCode, ',');
        getline(separate_comma, ucCode, ',');
        getline(separate_comma, weekday, ',');
        separate_comma >> startHour;
        separate_comma.ignore();
        separate_comma >> duration;
        separate_comma.ignore();
        separate_comma >> type;
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

void DataProcessor::studentsInUc(int n) { // IDK what this does
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

void printStudents(vector<Student> temp){
        sort(temp.begin(),temp.end(),[](const Student& a ,const Student& b){return a.getName()<b.getName();});
        cout << "------------------------------" << endl;
        cout << "Name / ID" << endl;
        cout << "------------------------------" << endl;
        for (const Student& student : temp){
            cout << student.getName() << " / " << student.getId() << endl;
        }
        cout << "------------------------------" << endl;
}

void DataProcessor::studentsInClass(const string& classCode) {
    vector<Student> temp;
    for (const Student& student:students){
        for (const Class_UC& classUc:student.getClassesUcs()){
            if (classCode == classUc.getClassCode()){
                temp.push_back(student);
                break;
            }
        }
    }
    if (!temp.empty()){
        cout << "Students in class " << classCode << " are:" << endl;
        printStudents(temp);
    }
    else{
        cout << "------------------------------------" << endl;
        cout << "There are no students in this class." << endl;
        cout << "------------------------------------" << endl;
    }
}

void DataProcessor::studentsInCourse(string course) {
    transform(course.begin(), course.end(), course.begin(), ::toupper);
    if (course == "LEIC") {
        cout << "Students in course " << course << " are:" << endl;
        vector<Student> temp;
        copy(students.begin(),students.end(), back_inserter(temp));
        printStudents(temp);
    }
    else{
        cout << "-------------------------------------" << endl;
        cout << "There are no students in that course." << endl;
        cout << "-------------------------------------" << endl;
    }

}
void DataProcessor::studentsInYear(const string &year) {
    vector<Student> temp;
    for (const Student& student:students){
        if(year == student.getYear()){
            temp.push_back(student);
        }
    }
    if (!temp.empty()){
        cout << "Students from " << year << " are:" << endl;
        printStudents(temp);
    }
    else{
        cout << "-------------------------------------" << endl;
        cout << "There are no students from that year." << endl;
        cout << "-------------------------------------" << endl;
    }
}

void DataProcessor::ucGreatestNumberStudents() {
    unordered_map<string,int> numberUcStudents;
    for (const Student& student:students){
        for (const Class_UC& classesUc :student.getClassesUcs() ){
            numberUcStudents[classesUc.getUcCode()]++;
        }
    }
    int maxNumberStudent = INT_MIN;
    vector<string> ucMax;
    for (const auto& pair:numberUcStudents){
        if (pair.second > maxNumberStudent){
            maxNumberStudent = pair.second;
            ucMax.clear();
            ucMax.push_back(pair.first);
        }
        else if (pair.second == maxNumberStudent){
            ucMax.push_back(pair.first);
        }
    }
    if (ucMax.size() > 1){
        int lastIteration = (int)ucMax.size()-1;
        cout << "-----------------------------------" << endl;
        cout << "The UCs with the most students are: " << endl;
        cout << "-----------------------------------" << endl;
        for (const string& ucs :ucMax){
            if (!lastIteration--){
                cout << ucs << endl;
            }
            cout << ucs <<  "/";
        }
        cout << "Having " << maxNumberStudent << " number of students." << endl;
        cout << "-----------------------------------" << endl;
    } else{
        cout << "---------------------------------" << endl;
        cout << "The UC with the most students is: " << endl;
        cout << "---------------------------------" << endl;
        cout << ucMax.front() << endl;
        cout << "Having " << maxNumberStudent << " enrolled students." << endl;
        cout << "-----------------------------------" << endl;
    }
}

void DataProcessor::scheduleOfClass(const string &classCode) {
    for(const Schedule& schedule:schedules){
        if (schedule.getClassCode() == classCode){
            schedule.printSchedule();
            return;
        }
    }
    cout << "No schedule found." << endl;
}
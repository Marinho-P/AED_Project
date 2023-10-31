#include "DataProcessor.h"

/**
 * @brief Constructor of DataProcessor.Reads all data from the given csv files and stores them in the corresponding data structures
 * @details Time complexity - O(n+m) with n and m being the number of lines of students_classes.csv and classes.csv respectively
 */
DataProcessor::DataProcessor(){
    students_classes();
    classes();
    classes_per_uc();
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
/**
 * @brief Getter of all classes' schedules
 * @details Time complexity - O(1)
 * @return a set of schedules
 */
const set<Schedule> &DataProcessor::getSchedules() const{
    return schedules;
}
/**
 * @brief Processes data of the file students_classes.csv
 * @details Time complexity - O(n) with n being the number of lines of the file
 */
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
        separate_comma >> classCode;
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
/**
 * @brief Processes data of the file classes.csv
 * @details Time complexity - O(m) with m being the number of lines of the file
 */
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
        auto it = schedules.find(classCode);
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
/**
 * @brief Checks the number of students registered in at least n UCs
 * @details Time complexity - O(w) with w being the total number of existing students
 * @param n being the number of UCs
 */
void DataProcessor::studentsInUc(int n) {
    int res = 0;
    for (const Student& student: students){
        if (student.getClassesUcs().size() >= n){
            res++;
        }
    }
    cout << res << endl;
}
/**
 * @brief Getter of all given students
 * @details Time complexity - O(1)
 * @return a set of the existing students
 */
const set<Student> &DataProcessor::getStudents() const {
    return students;
}
/**
 * @brief Auxiliary function to print a given vector of students.It is printed in a certain format regarding the sortOption
 * @details Time complexity - O(n) with n being number of students stored in a given vector
 * @param temp vector of students
 * @param sortOption has 4 different inputs : A to Z, Z to A, numerical and reversed numerical
 */
void printStudents(vector<Student> students,const string& sortOption){
    bool alphabetic = false;
    if (sortOption == "A to Z") {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.getName() < b.getName();
        });
        alphabetic = true;
    } else if (sortOption == "Z to A") {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.getName() > b.getName();
        });
        alphabetic = true;
    } else if (sortOption == "numerical") {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.getId() < b.getId();
        });
    } else if (sortOption == "reverse numerical") {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.getId() > b.getId();
        });
    }
    cout << "------------------------------" << endl;
    if (alphabetic){
        cout << "Name / ID" << endl;
        cout << "------------------------------" << endl;
        for (const Student& student : students){
            cout << student.getName() << " / " << student.getId() << endl;
        }
    }
    else{
        cout << "ID / Name" << endl;
        cout << "------------------------------" << endl;
        for (const Student& student : students){
            cout << student.getId() << " / " << student.getName() << endl;
        }
    }
    cout << "------------------------------" << endl;
}
/**
 * @brief Checks which students are in a given class and prints them
 * @details Time complexity - O(n*m) with n being the number of existing students, and m the number of classes of each student
 * @param classCode The code of a given class
 * @param sortOption has 4 different inputs : A to Z, Z to A, numerical and reversed numerical
 */
void DataProcessor::studentsInClass(const string& classCode,const string& sortOption) {
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
        printStudents(temp,sortOption);
    }
    else{
        cout << "------------------------------------" << endl;
        cout << "There are no students in this class." << endl;
        cout << "------------------------------------" << endl;
    }
}
/**
 * @brief Checks how many students are in LEIC course and prints them
 * @details Time complexity - O(n) with n being the number of existing students
 * @param course A given course
 * @param sortOption has 4 different inputs : A to Z, Z to A, numerical and reversed numerical
 */
void DataProcessor::studentsInCourse(string course,const string& sortOption) {
    transform(course.begin(), course.end(), course.begin(), ::toupper);
    if (course == "LEIC") {
        cout << "Students in course " << course << " are:" << endl;
        vector<Student> temp;
        copy(students.begin(),students.end(), back_inserter(temp));
        printStudents(temp,sortOption);
    }
    else{
        cout << "-------------------------------------" << endl;
        cout << "There are no students in that course." << endl;
        cout << "-------------------------------------" << endl;
    }
}
/**
 * @brief Checks the students from a given year and prints them
 * @details Time complexity - O(n) with n being the number of existing students
 * @param year A given year (ex:2022)
 * @param sortOption has 4 different inputs : A to Z, Z to A, numerical and reversed numerical
 */
void DataProcessor::studentsInYear(const string &year,const string& sortOption) {
    vector<Student> temp;
    for (const Student& student:students){
        if(year == student.getYear()){
            temp.push_back(student);
        }
    }
    if (!temp.empty()){
        cout << "Students from " << year << " are:" << endl;
        printStudents(temp,sortOption);
    }
    else{
        cout << "-------------------------------------" << endl;
        cout << "There are no students from that year." << endl;
        cout << "-------------------------------------" << endl;
    }
}
/**
 * @brief Checks the Uc or Ucs with the most number of enrolled students and prints the ucCode and the number of students
 * @details Time complexity - O(n*m) with n being the number of existing students and m the number of ClassUcs of a student
 */
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
        cout << "Having " << maxNumberStudent << " enrolled students." << endl;
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
/**
 * @brief Checks the schedule of a given class and prints it
 * @details Time complexity - O(n+m) with n being the number of all classes' schedules and m the number of lectures in a schedule
 * @param classCode A given class
 */
void DataProcessor::scheduleOfClass(const string &classCode)const {
    for(const Schedule& schedule:schedules){
        if (schedule.getClassCode() == classCode){
            schedule.printSchedule();
            return;
        }
    }
    cout << "No schedule found." << endl;
}
/**
 * @brief Checks the schedule of a student, given its Id and prints its schedule
 * @details Time complexity - O(n*k*log(k)*t+m*log(m)) with n being the number of classUCs of a student, k the number of schedules of a class, t the number of lectures in a schedule and m the number of existing students
 * @param Id Given Id of a student
 */

void DataProcessor::scheduleOfStudent(const string &Id)const {
    Schedule new_schedule;
    auto student = students.find(Id);
    if (student != students.end()){
        for (const Class_UC &classUc:(*student).getClassesUcs()){
            auto it = schedules.find(Schedule(classUc.getClassCode()));
            if (it != schedules.end()){
                for (const Lecture& lecture:(*it).getLectures()){
                    if (lecture.getUcCode() == classUc.getUcCode()){
                        new_schedule.addLecture(lecture);
                    }
                }
            }
        }
        new_schedule.printSchedule();
    }
}


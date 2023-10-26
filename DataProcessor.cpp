#include "DataProcessor.h"


DataProcessor::DataProcessor(){}

void DataProcessor::classes_per_uc() {
    ifstream file("classes_per_uc.csv");
    string header;
    getline(file,header); // ignore the header
    string line;
    while (getline(file,line)){
        istringstream separate_comma(line);
        string ucCode,classCode;
        getline(separate_comma,ucCode,',');
        getline(separate_comma,classCode,',');
        auto it = classes_uc.begin();
        while (it != classes_uc.end()) {
            if (it->getUcCode() == ucCode) {
                Class_UC modifiedClassUC(*it);
                modifiedClassUC.addClassCode(classCode);
                it = classes_uc.erase(it);
                classes_uc.insert(modifiedClassUC);
                break;
            }
            ++it;
        }
        if (it == classes_uc.end()) {
            Class_UC newClassUC(ucCode);
            newClassUC.addClassCode(classCode);
            classes_uc.insert(newClassUC);
        }
    }
}

set<Class_UC> DataProcessor::getClassUc(){
    return classes_uc;
}

void DataProcessor::students_classes() {
    ifstream file("students_classes");
    string header;
    getline(file,header);
    string line;
    while (getline(file,line)){
        istringstream separate_comma(line);
        string ucCode,classCode,studentName,studentCode;
        getline(separate_comma,studentName,',');
        getline(separate_comma,studentCode,',');
        getline(separate_comma,ucCode,',');
        getline(separate_comma,classCode,',');
        Student testStudent = Student(studentName,studentCode);
        auto it = find(students.begin(),students.end(),testStudent) ;
        if (it != students.end()){
            *it.addClassUc(Class_UC(classCode,ucCode));
        }
        else{
            set<Class_UC> studentClassesUc;
            Student student = Student(studentName,studentCode,studentClassesUc);
            students.insert(student);
        }
    }
}
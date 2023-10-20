#ifndef AED_PROJECT_DATAPROCESSOR_H
#define AED_PROJECT_DATAPROCESSOR_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include "Student.h"
#include "Class_UC.h"
using namespace std;

class DataProcessor {
    private:
        set<Student> students;
        set<Class_UC> classes_uc;
    public:
        DataProcessor();
        void classes_per_uc();
        set<Class_UC> getClassUc();
};


#endif //AED_PROJECT_DATAPROCESSOR_H

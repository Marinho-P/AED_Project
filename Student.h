#ifndef AED_PROJECT_ESTUDANTE_H
#define AED_PROJECT_ESTUDANTE_H
#include <string>
#include "Schedule.h"
#include "Class_UC.h"
using namespace std;

/**
 * @brief Class that stores given information of a student
 */
class Student {
    private:
        string name;
        string id;
        set<Class_UC> classesUcs;
    public:
        /** @brief Default class constructor of Student with name and id being a empty string and classesUcs a empty set
        *   @details Time complexity - O(1)
        */
        Student(const string &name = "", const string &id = "",const set<Class_UC> &classesUcs = set<Class_UC>());
        const string &getName() const;
        const string &getId() const;
        const set<Class_UC> &getClassesUcs() const;
        void setId(const string &id);
        bool operator<(const Student &other) const;
        bool operator==(const Student &other) const;
        void addClassUc(const Class_UC &classUc);
        string getYear() const;
        _Rb_tree_const_iterator<Class_UC> removeClassUc(const _Rb_tree_const_iterator<Class_UC> it){ return classesUcs.erase(it);}
        void removeClassUc(const Class_UC &classUc){ classesUcs.erase(classUc);};
};

#endif
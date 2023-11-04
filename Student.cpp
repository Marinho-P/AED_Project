#include "Student.h"
/**
 * @brief Class constructor of Student given an id, name, and a set of classesUcs
 * @details Time complexity - O(1)
 * @param name
 * @param id
 * @param classesUcs
 */

Student::Student(const string &name, const string &id, set<Class_UC> classesUcs) : name(name), id(id), classesUcs(classesUcs) {}
/**
 * @brief Getter of the name of a student
 * @details Time complexity - O(1)
 * @return name
 */
const string &Student::getName() const {
    return name;
}
/**
 * @brief Getter of the id of a student
 * @details Time complexity - O(1)
 * @return Id
 */
const string &Student::getId() const {
    return id;
}

/**
 * @brief Sets the id of a student to the given Id
 * @details Time complexity - O(1)
 * @param id
 */

void Student::setId(const string &id) {
    Student::id = id;
}
/**
 * @brief Checks if id of Student is less than the other
 * @details Time complexity - O(1)
 * @param other
 * @return true if id less than other.id else false
 */

bool Student::operator<(const Student &other) const{
    return id < other.id;
}
/**
 * @brief Checks if Student is equal to other Student
 * @details Time complexity - O(1)
 * @param other
 * @return true if Student is equal to comparing student
 */
bool Student::operator==(const Student &other) const {
    return id == other.id;
}
/**
 * @brief Adds a classUc to the classesUcs of a student
 * @details Time complexity - O(log(n)) with n being the number of classesUcs of a student
 * @param classUc
 */

void Student::addClassUc( const Class_UC &classUc) const {
    classesUcs.insert(classUc);
}

/**
 * @brief Getter of the ClassesUcs of a student
 * @details Time complexity - O(1)
 * @return classesUcs
 */
set<Class_UC> &Student::getClassesUcs() const{
    return classesUcs;
}
/**
 * @brief Getter of the year of registration of a student
 * @details Time complexity - O(1)
 * @return year of registration
 */
string Student::getYear() const {
    return id.substr(0,4);
}

/**
 * @brief Removes a Student's classUc
 * @details Time complexity - O(n) with n being the number of ClassesUc of a Student
 * @param classUc
 */

void Student::removeClassUc(const Class_UC &classUc)const {
    classesUcs.erase(classUc);
}



#include "Class_UC.h"
/**
 * @brief Constructor of class Class_UC , classCode and ucCode are set to given values.
 * @details Time complexity - O(1)
 * @param classCode_
 * @param ucCode_
 */
Class_UC::Class_UC(const string &classCode_, const string &ucCode_) {
    classCode = classCode_;
    ucCode = ucCode_;
}
/**
 * @brief Getter of the ucCode
 * @details Time complexity - O(1)
 * @return the ucCode
 */
const string &Class_UC::getUcCode() const {
    return ucCode;
}

/**
 * @brief Getter of the classCode
 * @details Time complexity - O(1)
 * @return the classCode
 */
const string &Class_UC::getClassCode() const {
    return classCode;
}

/**
 * @brief Operator that gives a sort ascending order option. First compares by ucCode and then by classCode
 * @details Time complexity - O(1)
 * @param other object of Class_Uc
 * @return true if ucCode is less than other.ucCode or same ucCodes and classCode less than other.classCode, else false
 */
bool Class_UC::operator<(const Class_UC &other) const{
    if(ucCode < other.ucCode){
        return true;
    }
    else{
        if(ucCode == other.ucCode && classCode < other.classCode){
            return true;
        }
    }
    return false;
}

/**
 * @brief Checks if a Class_Uc is equal to other
 * @details Time complexity - O(1)
 * @param other
 * @return true if ucCode is equal to other, ucCode else false
 */
bool Class_UC::operator==(const Class_UC &other) const {
    return other.ucCode == ucCode && other.classCode == classCode;
}

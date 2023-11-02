#include "Request.h"
/**
 * @brief Class constructor of Request given a student, type of request, ucCode, a startCode and an endCode
 * @details Time complexity - O(1)
 * @param student
 * @param type
 * @param ucCode
 * @param startCode
 * @param endCode
 */

Request::Request( Student &student, const string &type, const string &ucCode,
                 const string &startCode, const string &endCode) : student(student),
                                                                                   type(type), UcCode(ucCode),
                                                                                   startCode(startCode),
                                                                                   endCode(endCode) {}
/**
 * @brief Getter of type of request
 * @details Time complexity - O(1)
 * @return type of request
 */
const string &Request::getType() const {
    return type;
}
/**
 * @brief Getter of a request ucCode
 * @details Time complexity - O(1)
 * @return UcCode
 */
const string &Request::getUcCode() const {
    return UcCode;
}
/**
 * @brief Getter of the startCode
 * @details Time complexity - O(1)
 * @return startCode
 */
const string &Request::getStartCode() const {
    return startCode;
}
/**
 * @brief Getter of the endCode
 * @details Time complexity - O(1)
 * @return endCode
 */
const string &Request::getEndCode() const {
    return endCode;
}

/**
 * @brief Getter for the student doing a request
 * @details Time complexity - O(1)
 * @return student
 */
Student & Request::getStudent() {
    return student;
}
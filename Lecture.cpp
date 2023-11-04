#include "Lecture.h"

/**
 * @brief Class constructor of Lecture that initializes an object given a duration, startHour, type, weekday and ucCode
 * @details Time complexity - O(1)
 * @param duration
 * @param startHour
 * @param type
 * @param weekday
 * @param UcCode
 */

Lecture::Lecture(const float &duration,const float &startHour, const string &type, const string &weekday,const string &UcCode) {
    this->duration = duration; //float
    this->weekday = weekday;
    this->type = type;
    this-> startHour = startHour; // float
    UC_Code = UcCode;
}


/**
 * @brief Sets the startHour of a Lecture
 * @details Time complexity - O(1)
 * @param startHour
 */

void Lecture::setStartHour(float startHour) {
    Lecture::startHour = startHour;
}


/**
 * @brief Getter for the type of a Lecture
 * @details Time complexity - O(1)
 * @return type
 */

const string &Lecture::getType() const {
    return type;
}


/**
 * @brief Getter for the weekday of a Lecture
 * @details Time complexity - O(1)
 * @return day of the week
 */
const string &Lecture::getWeekday() const {
    return weekday;
}


/**
 * @brief Getter for the ucCode of a Lecture
 * @details Time complexity - O(1)
 * @return ucCode
 */
const string &Lecture::getUcCode() const{
    return UC_Code;
}

/**
 * @brief Checks if a Lecture starts first
 * @details Time complexity - O(1)
 * @param other Lecture to compare
 * @return true if startHour is less than other.startHour else false
 */
bool Lecture::operator<(const Lecture& other) const{
    return startHour < other.startHour;
}

/**
 * @brief Getter for the duration of a Lecture
 * @details Time complexity - O(1)
 * @return duration
 */

const float &Lecture::getDuration() const{
    return duration;
}

/**
 * @brief Getter for the startHour of a Lecture
 * @details Time complexity - O(1)
 * @return startHour
 */
const float &Lecture::getStartHour() const {
    return startHour;
}


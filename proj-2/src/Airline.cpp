//
// Created by aqueiros22 on 18-12-2023.
//


#include "Airline.h"
/**
 * @brief Constructor for the Airline class that initializes an object with a code, name, call sign, and country.
 * @details Time complexity - O(1)
 * @param code The airline code.
 * @param name The name of the airline.
 * @param callSign The call sign of the airline.
 * @param country The country to which the airline belongs.
 */
Airline:: Airline(string code, string name, string callSign, string country)
    : code_(code), name_(name), callSign_(callSign), country_(country) {}

/**
 * @brief Getter for the airline code.
 * @details Time complexity - O(1)
 * @return The airline code.
 */
string Airline::getCode() {
    return code_;
}
/**
 * @brief Getter for the name of the airline.
 * @details Time complexity - O(1)
 * @return The name of the airline.
 */
string Airline::getName() {
    return name_;
}
/**
 * @brief Getter for the call sign of the airline.
 * @details Time complexity - O(1)
 * @return The callSign of the airline.
 */
string Airline::getCallSign() {
    return callSign_;
}
/**
 * @brief Getter for the country to which the airline belongs.
 * @details Time complexity - O(1)
 * @return The country of the airline.
 */
string Airline::getCountry() {
    return country_;
}
/**
 * @brief Setter for the airline code.
 * @details Time complexity - O(1)
 * @param code The new airline code.
 */
void Airline::setCode(string code) {
    this->code_ = code;
}
/**
 * @brief Setter for the name of the airline.
 * @details Time complexity - O(1)
 * @param name The new name of the airline.
 */
void Airline::setName(string name) {
    this->name_ = name;
}
/**
 * @brief Setter for the call sign of the airline.
 * @details Time complexity - O(1)
 * @param callSign The new call sign of the airline.
 */
void Airline::setCallSign(string callSign) {
    this->callSign_ = callSign;
}
/**
 * @brief Setter for the country to which the airline belongs.
 * @details Time complexity - O(1)
 * @param country The new country of the airline.
 */
void Airline::setCountry(string country) {
    this->country_ = country;
}
//
// Created by aqueiros22 on 18-12-2023.
//

#include "Airport.h"

/**
 * @brief Constructor for the Airport class that initializes an object with a code, name, city, and coordinates.
 * @details Time complexity - O(1)
 * @param code The airport code.
 * @param name The name of the airport.
 * @param city A pointer to the City object to which the airport belongs.
 * @param latitude The latitude coordinate of the airport.
 * @param longitude The longitude coordinate of the airport.
 */
Airport::Airport(string code, string name, City* city, double latitude, double longitude)
        : code_(code), name_(name), city_(city), coordinate_(latitude, longitude) {}

/**
 * @brief Getter for the airport code.
 * @details Time complexity - O(1)
 * @return The airport code.
 */
string Airport::getCode() {
    return code_;
}

/**
 * @brief Getter for the name of the airport.
 * @details Time complexity - O(1)
 * @return The name of the airport.
 */
string Airport::getName() {
    return name_;
}

/**
 * @brief Getter for the City object to which the airport belongs.
 * @details Time complexity - O(1)
 * @return A pointer to the City object.
 */
City* Airport::getCity() {
    return city_;
}

/**
 * @brief Getter for the coordinates of the airport.
 * @details Time complexity - O(1)
 * @return The Coordinate object representing the latitude and longitude.
 */
Coordinate Airport::getCoordinate() {
    return coordinate_;
}

/**
 * @brief Setter for the airport code.
 * @details Time complexity - O(1)
 * @param code The new airport code.
 */
void Airport::setCode(string code) {
    this->code_ = code;
}

/**
 * @brief Setter for the name of the airport.
 * @details Time complexity - O(1)
 * @param name The new name of the airport.
 */
void Airport::setName(string name) {
    this->name_ = name;
}

/**
 * @brief Setter for the City object to which the airport belongs.
 * @details Time complexity - O(1)
 * @param city A pointer to the new City object.
 */
void Airport::setCity(City* city) {
    this->city_ = city;
}

/**
 * @brief Setter for the coordinates of the airport.
 * @details Time complexity - O(1)
 * @param latitude The new latitude coordinate.
 * @param longitude The new longitude coordinate.
 */
void Airport::setCoordinate(double latitude, double longitude) {
    this->coordinate_ = Coordinate(latitude, longitude);
}

//
// Created by aqueiros22 on 18-12-2023.
//

#include "City.h"

/**
 * @brief Constructor for the City class that initializes an object with a name and country.
 * @details Time complexity - O(1)
 * @param name The name of the city.
 * @param country The country to which the city belongs.
 */
City::City(const string& name, const string& country) : name_(name), country_(country) {}

/**
 * @brief Getter for the name of the city.
 * @details Time complexity - O(1)
 * @return The name of the city.
 */
string City::getName() const {
    return name_;
}

/**
 * @brief Getter for the country to which the city belongs.
 * @details Time complexity - O(1)
 * @return The country of the city.
 */
string City::getCountry() const {
    return country_;
}

/**
 * @brief Getter for the list of airports in the city.
 * @details Time complexity - O(1)
 * @return A constant reference to the vector of airport names.
 */
const vector<string>& City::getAirports() const {
    return airports_;
}

/**
 * @brief Setter for the name of the city.
 * @details Time complexity - O(1)
 * @param name The new name of the city.
 */
void City::setName(const string& name) {
    name_ = name;
}

/**
 * @brief Setter for the country to which the city belongs.
 * @details Time complexity - O(1)
 * @param country The new country of the city.
 */
void City::setCountry(const string& country) {
    country_ = country;
}

/**
 * @brief Adds an airport to the list of airports in the city.
 * @details Time complexity - O(1)
 * @param airport The name of the airport to be added.
 */
void City::addAirport(const string& airport) {
    airports_.push_back(airport);
}
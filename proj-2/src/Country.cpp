//
// Created by aqueiros22 on 18-12-2023.
//

#include "Country.h"

/**
 * @brief Constructor for the Country class that initializes an object with a name.
 * @details Time complexity - O(1)
 * @param name The name of the country.
 */
Country::Country(const string& name) : name_(name) {}

/**
 * @brief Getter for the name of the country.
 * @details Time complexity - O(1)
 * @return The name of the country.
 */
std::string Country::getName() const {
    return name_;
}

/**
 * @brief Getter for the set of cities in the country.
 * @details Time complexity - O(1)
 * @return A constant reference to the set of cities.
 */
const set<string>& Country::getCities() const {
    return cities_;
}

/**
 * @brief Adds a city to the set of cities in the country.
 * @details Time complexity - O(log n), where n is the number of cities in the set.
 * @param city The name of the city to be added.
 */
void Country::addCity(const string& city) {
    cities_.insert(city);
}


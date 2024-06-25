//
// Created by aqueiros22 on 18-12-2023.
//

#ifndef PROJETO_AED_2_CITY_H
#define PROJETO_AED_2_CITY_H

using namespace std;
#include <string>
#include <vector>
/**
 * @brief Class that represents  a city, name, country and the airports
 */
class City {
private:
    string name_;
    string country_;
    vector<string> airports_;

public:
    City(const string& name, const string& country);
    string getName() const;
    string getCountry() const;
    const vector<string>& getAirports() const;
    void setName(const string& name);
    void setCountry(const string& country);
    void addAirport(const string& airport);
};


#endif //PROJETO_AED_2_CITY_H

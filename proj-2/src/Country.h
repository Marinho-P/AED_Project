//
// Created by aqueiros22 on 18-12-2023.
//

#ifndef PROJETO_AED_2_COUNTRY_H
#define PROJETO_AED_2_COUNTRY_H


#include <string>
#include <set>

using namespace std;
/**
 * @brief Class that represents  a country, name and cities
 */
class Country {
private:
    string name_;
    set<string> cities_;
public:
    Country(const string& name);
    string getName() const;
    const set<string>& getCities() const;
    void addCity(const string& city);
};


#endif //PROJETO_AED_2_COUNTRY_H

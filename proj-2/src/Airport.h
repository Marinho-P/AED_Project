//
// Created by aqueiros22 on 18-12-2023.
//

#ifndef PROJETO_AED_2_AIRPORT_H
#define PROJETO_AED_2_AIRPORT_H
#include <string>
#include "Coordinate.h"
#include "City.h"

using namespace std;

/**
 * @brief Class that represents the airports, code, name, city and coordinates
 */
class Airport {
private:
    string code_;
    string name_;
    City* city_;
    Coordinate coordinate_;

public:
    Airport(string code, string name, City* city, double latitude, double longitude);
    string getCode();
    string getName();
    City* getCity();
    Coordinate getCoordinate();
    void setCode(string code);
    void setName(string name);
    void setCity(City* city);
    void setCoordinate(double latitude, double longitude);

};


#endif //PROJETO_AED_2_AIRPORT_H

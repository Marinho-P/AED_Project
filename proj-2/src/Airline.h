//
// Created by aqueiros22 on 18-12-2023.
//

#ifndef PROJETO_AED_2_AIRLINE_H
#define PROJETO_AED_2_AIRLINE_H
#include <string>
using namespace std;
/**
 * @brief Class that represents the airlines, code, name, callSign and country
 */
class Airline {
private:
    string code_;
    string name_;
    string callSign_;
    string country_;

public:
    Airline(string code, string name, string callSign, string country);
    string getCode();
    string getName();
    string getCallSign();
    string getCountry();
    void setCode(string code);
    void setName(string name);
    void setCallSign(string callSign);
    void setCountry(string country);

};


#endif //PROJETO_AED_2_AIRLINE_H

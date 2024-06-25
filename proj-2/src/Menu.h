//
// Created by pmigu on 21/12/2023.
//

#ifndef AED_PROJECT_2_MENU_H
#define AED_PROJECT_2_MENU_H


#include "Data.h"
/**
 * @brief Class that serves as the interactive menu for the user
 */
class Menu {
    private:
    /** @brief Attribute that can access all data processed */
        Data data;
    public:
        Menu();
        int run();
    private:
        void listNetworkStatistics();
        void listBestFlightOptions();
        void exit();
        int menuOptions() const;
        int networkStatisticsOptions() const;
        int flightsPerCity_AirlineOptions() const;
        int numberOfUniqueCountriesReachableOptions() const;
        bool flightOptionsInput(string &mode, string &searchTerm);

    unordered_set<string> getAllowedFilter();
};


#endif //AED_PROJECT_2_MENU_H

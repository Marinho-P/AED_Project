#include "Menu.h"
/**
 * @brief Constructor for the Menu class.
 */
Menu::Menu(){
}
/**
 * @brief Runs the menu and handles user input for various options.
 * @return 0 when the user chooses to exit.
 * @details Time complexity - O(n), where n is the number of airports or flights.
 */
int Menu::run(){
    int option = menuOptions();
    while(option != 0){
        switch(option){
            case 1:
                listNetworkStatistics();
                break;
            case 2:
                listBestFlightOptions();
                break;
            default:
                std::cout << "Invalid option try again" << std::endl;
        }
        option = menuOptions();
    }
    exit();
    return 0;
}
/**
 * @brief Exits the menu and displays an exit message.
 */
void Menu::exit(){
    std::cout << ">> Exiting the menu." << std::endl;
}
/**
 * @brief Lists the best flight options based on user input.
 * @details Time complexity - O(n), where n is the number of airports or flights.
 */
void Menu::listBestFlightOptions() {
    string sourceMode, source, destMode, dest;
    cout << "Enter a starting location:" << endl;
    if(!flightOptionsInput(sourceMode,source)){
        return;
    }

    cout << "Enter a destination location:" << endl;
    if(!flightOptionsInput(destMode,dest)){
        return;
    }
    unordered_set<string> allowed = getAllowedFilter();
    string minimize;
    cout << "Do you wish to minimize the number of airlines used? ( Y / N ):";
    cin >> minimize;
    bool valid = false;
    while(!valid){
        if(cin.fail() || (minimize != "Y" && minimize != "N")){
            cin.clear();
            cin.ignore();
            cout << "Invalid answer - try again" << endl;
            cout << "Do you wish to minimize the number of airlines used? ( Y / N ):";
            cin >> minimize;

        }
        else{
            valid = true;
        }
    }

    bool min;
    if( minimize == "Y"){
        min = true;
    }
    else{
        min = false;
    }
    data.bestFlightOption(sourceMode,source,destMode,dest,allowed,min);

}
/**
 * @brief Lists various network statistics based on user input.
 */
void Menu::listNetworkStatistics() {
    int option = networkStatisticsOptions();
    int flightPerCity_AirlineOption;
    int numberOfUniqueCountriesReachableOption;
    while(option != 0){
        switch(option){
            case 1:
                data.listAllAirportsAndAvailableFlights();
                break;
            case 2:
                data.flightsOutFromAirportAndDifferentAirlines();
                break;
            case 3:
                flightPerCity_AirlineOption = flightsPerCity_AirlineOptions();
                while(flightPerCity_AirlineOption != 0){
                    switch(flightPerCity_AirlineOption){
                        case 1:
                            data.numberOfFlightsPerCity_Airline("city");
                            break;
                        case 2:
                            data.numberOfFlightsPerCity_Airline("airline");
                            break;
                        default:
                            std::cout << "Invalid option try again" << std::endl;
                    }
                    flightPerCity_AirlineOption = flightsPerCity_AirlineOptions();
                }
                break;
            case 4:
                numberOfUniqueCountriesReachableOption = numberOfUniqueCountriesReachableOptions();
                while (numberOfUniqueCountriesReachableOption != 0){
                    switch(numberOfUniqueCountriesReachableOption){
                        case 1:
                            data.numberOfUniqueCountriesReachableAirport_City("airport");
                            break;
                        case 2:
                            data.numberOfUniqueCountriesReachableAirport_City("city");
                            break;
                        default:
                            std::cout << "Invalid option try again" << std::endl;
                    }
                    numberOfUniqueCountriesReachableOption = numberOfUniqueCountriesReachableOptions();
                }
                break;
            case 5:
                data.sumOfDestinationsAirport();
                break;
            case 6:
                data.sumOfDestinationsAirportWithLayOvers();
                break;
            case 8:
                int k;
                cout << "Enter k:";
                cin >> k;
                while (cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid input - try again" << endl;
                    cout << "Enter k:";
                    cin >> k;
                }
                data.topKAirports(k);
                break;
            case 7:
                data.checkMaximumTripStops();
                break;
            case 9:
                data.checkEssentialAirports();
                break;
            default:
                std::cout << "Invalid option try again" << std::endl;
        }
        option = networkStatisticsOptions();
    }
}
/**
 * @brief Displays network statistics menu options.
 * @return The selected menu option.
 */
int Menu::networkStatisticsOptions() const{
    int option;
    std::cout << "1. Check the number of flights available and global airports" << std::endl;
    std::cout << "2. Check how many flights are leaving from a specific airport and find out the number of different airlines involved" << std::endl;
    cout << "3. Check number of flights per city/airline" << endl;
    cout << "4. Check number of different countries that are reachable from an airport/city" << endl;
    cout << "5. Check number of destinations reachable from an airport"<< endl; // number of destinations means sum of airports,cities and countries
    cout << "6. Check number of reachable destinations from an airport with a maximum of X stops"<< endl; // number of destinations means sum of airports,cities and countries
    cout << "7. Check maximum trip and the pair(s) of the corresponding airports"<< endl;// number of destinations means sum of airports,cities and countries
    cout << "8. Check the top-k airport with the greatest air traffic capacity" << endl;
    cout << "9. Check the essential airports" << endl;
    cout<< "0. Back to main menu"<<endl;
    cout << "Enter your option:";
    cin >> option;
    return option;
}
/**
 * @brief Displays flights per city/airline menu options.
 * @return The selected menu option.
 */
int Menu::flightsPerCity_AirlineOptions() const{
    int option;
    cout << "1. Check number of flights choosing a city" << endl;
    cout << "2. Check number of flights choosing an airline" << endl;
    cout << "0. Go back" << endl;
    cout << "Enter your option:";
    cin >> option;
    return option;
}
/**
 * @brief Displays number of unique countries reachable menu options.
 * @return The selected menu option.
 */
int Menu::numberOfUniqueCountriesReachableOptions() const {
    int option;
    cout << "1. Check number of different countries that are reachable from an airport" << endl;
    cout << "2. Check number of different countries that are reachable from a city" << endl;
    cout << "0. Go back" << endl;
    cout << "Enter your option:";
    cin >> option;
    return option;
}
/**
 * @brief Displays the main menu options.
 * @return The selected menu option.
 */
int Menu::menuOptions() const {
    int option;
    std::cout << "1. List network statistics" << std::endl;
    std::cout << "2. List best flight options" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Enter your option:";
    std::cin >> option;
    return option;
}

/**
 * @brief Handles user input for indicating the location in flight options.
 * @param mode Reference to a string to store the location mode.
 * @param searchTerm Reference to a string to store the search term.
 * @details Time complexity - O(1)
 * @return False if user chooses "Go back", else true 
 */

bool Menu::flightOptionsInput(string &mode, string &searchTerm) {
    cout << "Indicate location by:" << endl;
    cout << "1. Airport code" << endl;
    cout << "2. Airport name" << endl;
    cout << "3. City name" << endl;
    cout << "4. Geographical coordinates" << endl;
    cout << "0.Go back" << endl;
    cout << "Enter your answer:";
    bool valid = false;
    string option;
    while(!valid){
        cin >> option;
        if(option == "1") {
            mode = "airportCode";
            valid = true;
        } else if(option == "2") {
            mode = "airportName";
            valid = true;
        } else if(option == "3") {
            mode = "cityName";
            valid = true;
        } else if(option == "4") {
            mode = "geoCoords";
            valid = true;
        } else if(option == "0") {
            return false;
        }else{
                cin.clear();
                cin.ignore();
                cout << "Incorrect value - Try again" << endl;
                cout << "Enter your answer:";
        }

    }

    if( mode == "airportCode" || mode == "airportName"){
        cout << "Enter the "+ mode +":";
        cin >> searchTerm;
        while(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Try again" << endl;
            cout << "Enter the "+ mode +" :";
            cin >> searchTerm;
        }
    }
    else if(mode == "cityName"){
        string city, country;
        cout << "Enter the city name:";
        cin >> city;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Invalid input - try again" << endl;
            cout << "Enter the city name:";
        }
        cout << "Enter the country name:";
        cin >> country;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Invalid input - try again" << endl;
            cout << "Enter the country name:";
        }
        searchTerm = city + "," + country;
    }
    else{
        double latitude,longitude;
        cout << "Enter the latitude:";
        cin >> latitude;
        if(cin.fail() || latitude > 90 || latitude < - 90){
            cin.clear();
            cin.ignore();
            cout << "Incorrect latitude - try again" << endl;
            cout << "Enter the latitude:";
            cin >> latitude;
        }
        cout << "Enter the longitude:";
        cin >> longitude;
        if(cin.fail() || longitude > 90 || longitude < - 90){
            cin.clear();
            cin.ignore();
            cout << "Incorrect longitude - try again" << endl;
            cout << "Enter the longitude:";
            cin >> longitude;
        }
        searchTerm = to_string(latitude) + "," + to_string(longitude);
    }
    return true;
}

/**
 * @brief Gets the list of allowed airlines from the user.
 * @return A unordered set of strings representing the allowed airlines.
 * @details Time complexity - O(k), where k is the number of allowed airlines.
 */


unordered_set<string> Menu::getAllowedFilter() {
    unordered_set<string> allowed;
    string input = "balls";
    cout << "Enter the airlines that you choose to travel with:" << endl;
    while(input != "q" & input != "all"){
        cout << "Enter the airline code ( enter 'all' for all airlines and 'q' to move to next step):";
        cin >> input;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Invalid input - try again" << endl;
        }
        else{
            allowed.insert(input);
        }
    }
    allowed.erase("q");
    return allowed;
}

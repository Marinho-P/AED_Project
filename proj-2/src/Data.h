

#ifndef PROJETO_AED_2_DATA_H
#define PROJETO_AED_2_DATA_H
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <limits>
#include "Airline.h"
#include "Airport.h"
#include "City.h"
#include "Country.h"
#include "Graph.h"
#include <unordered_map>
#include <map>

#define AIRLINES "../csv/airlines.csv"
#define AIRPORTS "../csv/airports.csv"
#define FLIGHTS "../csv/flights.csv"
/**
 * @brief Class that stores and processes useful data from the csv files
 */
class Data {
private:
    /** @brief Represents the number of flights. This variable is used to keep track of the total number of flights in the system */
    int nf = 0;
    /** @brief A hash map that stores airline objects using their unique codes as keys.
     * @details Time complexity - O(1) for access
     * */
    unordered_map <string, Airline*> airlines_ ;
    /** @brief A hash map that stores city objects using their names as keys.
    * @details Time complexity - O(1) for access
    * */
    unordered_map <string, City*> cities_; // cities O(1)
    /** @brief A hash map that stores airport objects using their names as keys.
    * @details Time complexity - O(1) for access
    */
    unordered_map <string, Airport*> airports_; // airports O(1)
    /** @brief A hash map that stores country objects using their names as keys.
  * @details Time complexity - O(1) for access
  */
    unordered_map <string, Country*> countries_;
    /** @brief A hash map that tracks the number of flights operated by each airline. It associates airline codes with the corresponding count of flights
*/
    unordered_map<string,int> airline_flights;
    /** @brief A pointer to a graph data structure that represents the network of flights. The graph likely contains vertices representing airports and edges representing flights between them
*/
    Graph<string>* flightG;
    /** @brief A vector of pairs where each pair consists of an airport code and its geographical coordinates. This information is useful for mapping the spatial layout of airports
     */
    vector<pair<string, Coordinate>> airportCoord_;

public:

    Data();
    unordered_map <string, Airport*> getAirports();
    unordered_map <string, Airline*> getAirlines();
    unordered_map <string, City*> getCities();
    unordered_map <string, Country*> getCountries();
    Graph<string>* getFlightG();
    void read_airlines();
    void read_airports();
    void read_flights();
    void listAllAirportsAndAvailableFlights() const;
    void flightsOutFromAirportAndDifferentAirlines();
    void numberOfFlightsPerCity_Airline(string city_airline);


    vector<Vertex<std::string> *> getFilteredVertex(string mode, string searchTerm);
    void numberOfUniqueCountriesReachableAirport_City(string airport_city);
    void sumOfDestinationsAirport();
    void sumOfDestinationsAirportWithLayOvers();
    void topKAirports(int k);
    void checkMaximumTripStops();


    int maxTrip(stack<pair<string, string>> &maxTrips);

    int findMaxTripBfs(stack<pair<string, string>> &pairs, Vertex<string> *source);

    void checkEssentialAirports();

    void dfs_art(Vertex<string> *v, stack<string> &s, vector<string> &airports, int &i);


    void countDestinationsBFS(Vertex<string> *vertex, int maxStops, unordered_set<string> &visitedAirports);



    void bestFlightOption(string sourceMode, string source, string destMode, string dest, unordered_set<string> allowed,
                          bool min);





    void
    bestFlightOption(vector<Vertex<string> *> source, vector<Vertex<string> *> dest,
                     const unordered_set<string> &allowed);








    Graph<string> getReverseGraph();


    void
    reverseDfsBestFlightOption(Vertex<string> *dest, Vertex<string> *source, vector<vector<string>> &pathsDiscovered,
                               vector<string> path);


    void fiterForSmallest(vector<vector<string>> &pathsDiscovered);

    void bestFlightOptionMin(vector<Vertex<string> *> sourceNodes, vector<Vertex<string> *> destNodes,
                             unordered_set<string> allowed);



    unordered_set<string> optimizeAirlines(vector<vector<string>> edge);


    void reverseDfsBestFlightOptionMin(Vertex<string> *dest, Vertex<string> *source,
                                       vector<pair<vector<string>, unordered_set<string>>> &pathsDiscovered,
                                       vector<string> path, vector<vector<string>> airlinesPerEdge);

    void filterForSmallestAndAirlines(vector<pair<vector<string>, unordered_set<string>>> &pathsDiscovered);

    vector<string> essentialAirportsForCirculation();

    void bfsBestFlightOption(Vertex<string> *source, unordered_set<string> allowed);
};


#endif //PROJETO_AED_2_DATA_H



#include <climits>
#include "Data.h"
/**
 * @brief Constructor for the Data class that initializes essential data structures.
 * * Time complexity: O(N), where N is the total number of entries in the airlines.csv, airports.csv, and flights.csv files.
 */
Data::Data() {
    flightG = new Graph<string>();
    read_airlines();
    read_airports();
    read_flights();
}
/**
 * @brief Getter for the map of airports.
 * @details Time complexity: O(1)
 * @return The unordered map of airports.
 *
 */
unordered_map<string, Airport*> Data::getAirports() {
    return airports_;
}
/**
 * @brief Getter for the map of airlines.
 * @details Time complexity: O(1)
 * @return The unordered map of airlines.
 */
unordered_map<string, Airline*> Data::getAirlines() {
    return airlines_;
}
/**
 * @brief Getter for the map of cities.
 * @details Time complexity: O(1)
 * @return The unordered map of cities.
 */
unordered_map<string, City*> Data::getCities() {
    return cities_;
}
/**
 * @brief Getter for the map of countries.
 * @details Time complexity: O(1)
 * @return The unordered map of countries.
 */
unordered_map<string, Country*> Data::getCountries() {
    return countries_;
}
/**
 * @brief Getter for the flight graph.
 * @details Time complexity: O(1)
 * @return A pointer to the flight graph.
 */
Graph<string>* Data::getFlightG() {
    return flightG;
}
/**
 * @brief Reads airline data from a file and populates relevant data structures.
 * @details Time complexity: O(N), where N is the number of entries in the airlines.csv file.
 */
void Data::read_airlines() {
    string code, name, callSign, countryName;
    ifstream input(AIRLINES);
    if (input.is_open()) {
        string line;
        getline(input, line);
        while (getline(input, line)) {
            istringstream iss(line);
            getline(iss, code, ',');
            getline(iss, name, ',');
            getline(iss, callSign, ',');
            getline(iss, countryName, ',');
            Airline* airline = new Airline(code, name, callSign, countryName);
            airlines_[code] = airline;
        }
    } else {
        cout << "Could not open the file\n";
    }
}
/**
 * @brief Reads airport data from a file and populates relevant data structures.
* @details Time complexity: O(N), where N is the number of entries in the airports.csv file.
 */
void Data::read_airports() {
    double latitude, longitude;
    string code, name, city, countryName;
    ifstream input(AIRPORTS);
    if (input.is_open()) {
        string line;
        getline(input, line);
        while (getline(input, line)) {
            stringstream iss(line);
            string token;
            getline(iss, code, ',');
            getline(iss, name, ',');
            getline(iss, city, ',');
            getline(iss, countryName, ',');
            string latitudeStr, longitudeStr;
            getline(iss, latitudeStr, ',');
            getline(iss, longitudeStr, ',');
            latitude = stod(latitudeStr);
            longitude = stod(longitudeStr);
            if(cities_.find(city + ',' + countryName) == cities_.end()){
                cities_[city + ',' + countryName] = new City(city, countryName);
            }
            Airport* airport = new Airport(code, name, cities_[city + ',' + countryName], latitude, longitude);
            string key = city + ',' + countryName;
            if(countries_.find(countryName) == countries_.end()){
                countries_[countryName] = new Country{countryName};
            }
            cities_[key]->addAirport(code);
            countries_[countryName]->addCity(key);
            airports_[code] = airport;
            airportCoord_.emplace_back(code, Coordinate(latitude, longitude));
        }
    } else {
        cout << "Could not open the file\n";
    }
}
/**
 * @brief Reads flight data from a file and populates relevant data structures.
 * @details Time complexity: O(N), where N is the number of entries in the flights.csv file.
 */
void Data::read_flights() {
    string sourceCode, targetCode, airlineCode;
    Vertex<string>* sourceVertex = nullptr;
    string previousSource = "place-holder";
    ifstream input(FLIGHTS);
    flightG = new Graph<string>();
    for(auto it = airports_.begin(); it != airports_.end();it++){
        flightG->addVertex(it->first);
    }
    if (input.is_open()) {
        string line;
        getline(input, line);
        while (getline(input, line)) {
            istringstream iss(line);
            getline(iss, sourceCode, ',');
            getline(iss, targetCode, ',');
            getline(iss, airlineCode, ',');
            Airport* source = airports_[sourceCode];
            Airport* target = airports_[targetCode];
            airline_flights[airlineCode]++;
            double dist = source->getCoordinate().dist_coordinates(target->getCoordinate());
            if(sourceCode != previousSource){ // tiny optimization, capitalizes on the formatting of the csv file
                sourceVertex = flightG->findVertex(sourceCode);
                previousSource = sourceCode;
            }
            Vertex<string>* destVertex = flightG->findVertex(targetCode);
            sourceVertex->addEdge(destVertex,dist,airlineCode);

            nf++;
        }
    } else {
        cout << "Could not open the file\n";
    }

}
/**
 * @brief Lists the number of flights and airports.
 * @details Time complexity: O(1)
 */
void Data::listAllAirportsAndAvailableFlights() const {
        cout << "/******************************************/" << endl;
        cout << "Number of flights: " << nf << endl;
        cout << "Number of airports: " << airports_.size() << endl;
        cout << "/******************************************/" << endl;
}
/**
 * @brief Displays information about flights from a specific airport with different airlines.
 * @details Time complexity: O(1)
 */
void Data::flightsOutFromAirportAndDifferentAirlines(){
    string airportCode;
    unordered_set<string> airlines;
    cout << "Airport code: ";
     cin.ignore();
     getline(cin,airportCode);
    auto airport = flightG->findVertex(airportCode);
    if(airport == nullptr){
        cout << "Airport not found" << endl;
        return;
    }
    for (auto &adj : airport->getAdj()) {
            airlines.insert(adj.getAirline());
    }
    cout << "/******************************************/" << endl;
    cout << "Number of flights out from airport " << airports_[airportCode]->getName() << " is " << airport->getAdj().size() << endl;
    cout << "Number of unique airlines are " << airlines.size() << endl;
    cout << "/******************************************/" << endl;
}

/**
 * @brief Calculates the number of unique countries reachable from a given airport or city.
 * @param airport_city The mode of calculation ("airport" or "city").
 * @details Time complexity: O(N), where N is the number of destinations from the specified airport or city.
 */
void Data::numberOfUniqueCountriesReachableAirport_City(string airport_city) { // keep in mind that if u are in the country and u can access it via city/airport it will count as part of the sum
    if(airport_city == "airport"){
        string airportCode;
        cout << "Airport code: ";
        cin.ignore();
        getline(cin,airportCode);
        auto it = airports_.find(airportCode);
        if (it == airports_.end()) {
            cout << "Airport not found" << endl;
            return;
        }
        unordered_set<string> countries;
        for(auto &adj : flightG->findVertex(airportCode)->getAdj()){
            auto airportDestiny = adj.getDest()->getInfo();
            auto country = airports_[airportDestiny]->getCity()->getCountry();
            countries.insert(country);
        }
        cout << "/******************************************/" << endl;
        cout << "Number of unique countries reachable from airport " << airportCode << " is " << countries.size() << endl;
        cout << "/******************************************/" << endl;
    }
    else{
        string city_country;
        cout << "Choose a city and its country (ex: Porto,Portugal):";
        cin.ignore();
        getline(cin,city_country);
        auto it = cities_.find(city_country);
        if (it == cities_.end()) {
            cout << "City not found" << endl;
            return;
        }
        istringstream iss(city_country);
        string city, country;
        getline(iss, city, ',');
        getline(iss, country);
        auto cityObj = it->second;
        unordered_set<string> countries;
        for(auto &airport : cityObj->getAirports()){
            for(auto &adj : flightG->findVertex(airport)->getAdj()){
                auto airportDestiny = adj.getDest()->getInfo();
                auto destinyCountry = airports_[airportDestiny]->getCity()->getCountry();
                countries.insert(destinyCountry);
            }
        }
        cout << "/******************************************/" << endl;
        cout << "Number of unique countries reachable from city " << city << " in " << country << " is " << countries.size() << endl;
        cout << "/******************************************/" << endl;
    }
}
/**
 * @brief Calculates the number of flights in a specific city or by a particular airline.
 * @param city_airline The mode of calculation ("city" or "airline").
 * @details Time complexity: O(N), where N is the number of flights associated with the specified city or airline.
 */
void Data::numberOfFlightsPerCity_Airline(string city_airline) {
    if (city_airline == "city") {
        cout << "Choose a city and its country (ex: Porto,Portugal):";
        string city_country;
        cin.ignore();
        getline(std::cin,city_country);
        auto it = cities_.find(city_country);
        if (it == cities_.end()) {
            cout << "City not found" << endl;
            return;
        }
        istringstream iss(city_country);
        string city, country;
        getline(iss, city, ',');
        getline(iss, country);
        auto cityObj = it->second;
        int nFlights = 0;
        for (auto &airport : cityObj->getAirports()) {
            nFlights += flightG->findVertex(airport)->getAdj().size();
        }
        cout << "/******************************************/" << endl;
        cout << "Number of flights in the city of " << city << " in " << country << " is "<< nFlights << endl;
        cout << "/******************************************/" << endl;
    }
    else{
        string airline;
        cout << "Choose an airline: ";
        cin.ignore();
        getline(cin,airline);
        auto it = airlines_.find(airline);
        if (it == airlines_.end()){
            cout << "Airline not found" << endl;
            return;
        }
        cout << "/******************************************/" << endl;
        cout << "Number of flights of "<< airline <<" airline" << " is " << airline_flights[airline] << endl;
        cout << "/******************************************/" << endl;
    }

}

/**
 * @brief Finds the best flight options between source and destination with specific constraints.
 * @param sourceMode The mode for specifying the source ("airportCode", "airportName", "cityName", "geoCoords").
 * @param source The source identifier.
 * @param destMode The mode for specifying the destination ("airportCode", "airportName", "cityName", "geoCoords").
 * @param dest The destination identifier.
 * @param allowed The unordered set of allowed airlines.
 * @param min If true, minimizes the number of airlines used.
 * @details Time complexity: O(N log N), where N is the total number of flights in the flights.csv file.
 */

void Data::bestFlightOption(string sourceMode,string source,string destMode, string dest,unordered_set<string> allowed, bool min){
    vector<Vertex<string>*> sourceNodes = getFilteredVertex(sourceMode,source);
    if(sourceNodes.size() == 0){
        cout << "No source airports found" << endl;
        return;
    }
    vector<Vertex<string>*> destNodes = getFilteredVertex(destMode,dest);
    if(destNodes.size() == 0){
        cout << "No destination nodes found" <<endl;
        return;
    }
    if(min){
        bestFlightOptionMin(sourceNodes,destNodes,allowed);
    }
    else{
        bestFlightOption(sourceNodes,destNodes,allowed);

    }
}
/**
 * @brief Retrieves a filtered list of vertices based on the specified mode and search term.
 * @param mode The filter mode, which can be "airportCode," "airportName," "cityName," or "geoCoords."
 * @param searchTerm The term to search for based on the specified mode.
 * @return A vector of Vertex pointers representing the filtered vertices.
 * @details Time complexity: O(N), where N is the number of vertices in the flight graph.
 */
vector<Vertex<string>*> Data:: getFilteredVertex(string mode,string searchTerm){
    vector<Vertex<string>*> res;
    if(mode == "airportCode"){
        res.push_back(flightG->findVertex(searchTerm));

    }
    if(mode == "airportName"){
        for( auto entry: airports_){
            if(entry.second->getName() == searchTerm){
                res.push_back(flightG->findVertex(entry.second->getCode()));
            }
        }
    }
    if(mode == "cityName"){
        for(auto entry : airports_){
            string compareString = entry.second->getCity()->getName() + "," +entry.second->getCity()->getCountry();
            if(compareString == searchTerm){
                res.push_back(flightG->findVertex(entry.second->getCode())); // might change depend on the teacher's answer
            }
        }
    }
    if(mode == "geoCoords"){
        istringstream coords(searchTerm);
        string latitudeStr;
        string longitudeStr;
        getline(coords,latitudeStr,',');
        getline(coords,longitudeStr,',');
        Coordinate coordinate(stod(latitudeStr), stod(longitudeStr ));
        double minDistance = numeric_limits<double>::max();
        for(auto entry:airports_){
            double distance = coordinate.dist_coordinates(entry.second->getCoordinate());
            if(distance < minDistance){
                res.clear();
                res.push_back(flightG->findVertex(entry.second->getCode()));
                minDistance = distance;
            }
            if(distance == minDistance){
                res.push_back(flightG->findVertex(entry.second->getCode()));
            }
        }

    }
    return res;
}

/**
 * @brief Finds the best flight options from a set of source airports to a set of destination airports.
 * @param source A vector of Vertex pointers representing the source airports.
 * @param dest A vector of Vertex pointers representing the destination airports.
 * @param allowed A unordered set of strings representing the allowed airlines.
 * @details Time complexity: O(S*(V+E)), where S is the number of vertices in the source vector, V is the total number of vertices in the flight graph and E is the total number of edges in the graph.
 */

void Data:: bestFlightOption(vector<Vertex<string>*> source, vector<Vertex<string>*> dest, const unordered_set<string>& allowed){

    vector<vector<string>> pathsDiscovered;
    vector<string> path;
    for(auto sourceVertex: source){
        bfsBestFlightOption(sourceVertex,allowed);
        Graph<string> reverse = getReverseGraph();
        Vertex<string>* reverseSource = reverse.findVertex(sourceVertex->getInfo());
        for(auto destVertex: dest){
            Vertex<string>* reverseDest = reverse.findVertex(destVertex->getInfo());
            reverseDfsBestFlightOption(reverseDest,reverseSource,pathsDiscovered,path);
        }
    }
    fiterForSmallest(pathsDiscovered);
    cout << "Number of paths found: " << pathsDiscovered.size() << endl;
    for(auto currentPath:pathsDiscovered){
        for(auto airport: currentPath){
            cout << airport << " -> ";
        }
        cout << currentPath.size() << " airports visited\n";
    }
}



/**
 * @brief Using bfs, calculates the distance between the source vertex and every other vertex.
 * @param source
 * @param dest
 * @param allowed
 * @details Time complexity: O(V+E), where V is the total number of vertices in the flight graph and E is the total number of edges in the graph.
 */
void Data::bfsBestFlightOption(Vertex<string>* source, unordered_set<string> allowed){
    for( auto v: flightG->getVertexSet()){
        v.second->setVisited(false);
        v.second->setNum(INT_MAX);
    }
    queue<Vertex<string>*> queue;
    source->setNum(0);
    queue.push(source);
    source->setVisited(true);
    while(!queue.empty()){
        Vertex<string>* u = queue.front();
        queue.pop();
        unordered_set<Vertex<string>*> locations;
        for(auto edge:u->getAdj()){
            if(allowed.find(edge.getAirline()) != allowed.end() || allowed.find("all") != allowed.end()){
                locations.insert(edge.getDest());
            }
        }
        for(auto location:locations){
            if(location->isVisited()){
                continue;
            }

            location->setNum(u->getNum()+1);
            location->setVisited(true);
            queue.push(location);

        }
    }


}
/**
 * @brief returns a version of the flightGraph with all of its edges reversed
 * @return reversed - the reversed version of the flightGraph
 * @details Time complexity: O(V+E), where V is the total number of vertices of the flight graph and E is the total number of edges in the graph.
 */
Graph<string> Data:: getReverseGraph(){
    Graph<string> reversed;
    for(auto v: flightG->getVertexSet()){
        Vertex<string>* newVertex = new Vertex<string>(v.second->getInfo());
        newVertex->setVisited(false);
        newVertex->setNum(v.second->getNum());
        reversed.addVertex(newVertex);
    }
    for(auto v: flightG->getVertexSet()){
        for(auto edge:v.second->getAdj()){
            reversed.addEdge(edge.getDest()->getInfo(),v.second->getInfo(),edge.getWeight(),edge.getAirline());
        }
    }
    return reversed;
}
/**
 * @brief Traverses the reversed graph starting on the dest node and through nodes of distance one less of the current node.
 * @param dest
 * @param source
 * @param pathsDiscovered
 * @param path
 * @details Time complexity: O(E) where E is the number of outgoing edges of source.
 */
void Data:: reverseDfsBestFlightOption(Vertex<string>* dest,Vertex<string>* source, vector<vector<string>> &pathsDiscovered,vector<string> path){

    path.push_back(dest->getInfo());
    if(dest == source){
        reverse(path.begin(),path.end());
        pathsDiscovered.push_back(path);
        return;
    }
    unordered_set<Vertex<string>*> locations;
    for(auto edge:dest->getAdj()){
        locations.insert(edge.getDest());
    }
    for(auto location:locations){
        if(location->getNum() == dest->getNum() - 1){
            reverseDfsBestFlightOption(location,source,pathsDiscovered,path);
        }
    }
}

/**
 * @brief Approximation algorithm for minimizing the number of airlines per path.
 * @param airlinesPerEdge
 * @return returnSet - set containing the approximation of the minimal set of airlines necessary.
 * @details Time complexity: Worst case scenario, when each flight in the path requires a different airlines, is O(N³) where N is the number of edges/airlines.
 */
unordered_set<string> Data::optimizeAirlines(vector<vector<string>> airlinesPerEdge) {
    unordered_set<string> returnSet;
    unordered_map<int,unordered_set<string>> airlinesPerEdgeMapped;
    unordered_set<int> edges;
    unordered_set<string> totalAirlines;
    for(int i = 0; i < airlinesPerEdge.size(); i++){
        unordered_set<string> edge;
        for(auto airline: airlinesPerEdge[i]){
            edge.insert(airline);
            totalAirlines.insert(airline);
        }
        airlinesPerEdgeMapped[i] = edge;
        edges.insert(i);
    }

    while(!edges.empty()){
        string best_choice;
        int max = INT_MIN;
        for(auto airline: totalAirlines){
            int edgesCovered = 0;
            for(auto edge:edges){
                if(airlinesPerEdgeMapped[edge].find(airline) != airlinesPerEdgeMapped[edge].end()){
                    edgesCovered++;
                }
            }
            if( edgesCovered > max){
                max = edgesCovered;
                best_choice = airline;
            }
        }
        returnSet.insert(best_choice);

        totalAirlines.erase(best_choice);
        for(auto edge: airlinesPerEdgeMapped){
            if(edge.second.find(best_choice) != edge.second.end()){
                edges.erase(edge.first);
            }
        }
    }

    return returnSet;
}
/**
 * @brief Calculates the sum of destinations from a specified airport.
 * @details Time complexity: O(N), where N is the number of vertices in the flight graph.
 */
void Data::sumOfDestinationsAirport() {
    string airportCode;
    cout << "Airport code:";
    cin.ignore();
    getline(cin,airportCode);
    auto it = airports_.find(airportCode);
    if (it == airports_.end()) {
        cout << "Airport not found" << endl;
        return;
    }
    vector<string> airports = flightG->bfs(airportCode);
    unordered_set<string> countries;
    unordered_set<City*> cities;
    for(auto &adj:airports){
        auto country = airports_[adj]->getCity()->getCountry();
        auto city = airports_[adj]->getCity();
        countries.insert(country);
        cities.insert(city);
    }
    cout << "/******************************************/" << endl;
    cout << "Sum of destinations from airport " << airportCode << " is " << airports.size() + countries.size() + cities.size() << endl;
    cout << "Number of unique countries destinations is " << countries.size() << endl;
    cout << "Number of unique cities destinations is " << cities.size() << endl;
    cout << "Number of unique airports destinations is " << airports.size() << endl;
    cout << "/******************************************/" << endl;
}
/**
 * @brief Calculates the sum of destinations from a specified airport considering layovers.
 * @details Time complexity: O(V+E), where V is the number of vertices in the flight graph and E the edges.
 */
void Data::sumOfDestinationsAirportWithLayOvers() {
    string airportCode;
    cout << "Airport code:";
    cin.ignore();
    getline(cin,airportCode);
    int layovers;
    cout << "Max number of layovers:";
    cin >> layovers;
    auto it = airports_.find(airportCode);
    if (it == airports_.end()) {
        cout << "Airport not found" << endl;
        return;
    }
    unordered_set<string> airports;
    unordered_set<string> countries;
    unordered_set<City*> cities;
    countDestinationsBFS(flightG->findVertex(airportCode),layovers,airports);
    for(auto &airport : airports){
        auto country = airports_[airport]->getCity()->getCountry();
        auto city = airports_[airport]->getCity();
        countries.insert(country);
        cities.insert(city);
    }
    cout << "/******************************************/" << endl;
    cout << "Sum of destinations from airport " << airportCode << " is " << airports.size() + countries.size() + cities.size() << endl;
    cout << "Number of unique countries destinations is " << countries.size() << endl;
    cout << "Number of unique cities destinations is " << cities.size() << endl;
    cout << "Number of unique airports destinations is " << airports.size() << endl;
    cout << "/******************************************/" << endl;
}
/**
 * @brief Performs a breadth-first search to count the number of destinations from a specified airport.
 *
 * @param vertex The starting airport vertex.
 * @param maxStops The maximum number of layovers allowed.
 * @param visitedAirports An unordered set to store the visited airports.
 * @details Time complexity: O(N^2), where N is the number of vertices in the flight graph.
 */
void Data::countDestinationsBFS(Vertex<string>* vertex, int maxStops, unordered_set<string>& visitedAirports) {
    for (auto v : flightG->getVertexSet())
        v.second->setVisited(false) ;
    std::queue<pair<Vertex<string>*, int>> q;
    q.push({vertex, 0});
    vertex->setVisited(true);
    while (!q.empty()) {
        auto currentPair = q.front();
        Vertex<string>* currentVertex = currentPair.first;
        int currentStops = currentPair.second;
        q.pop();

        if (currentStops <= maxStops && currentStops != 0) {
            visitedAirports.insert(currentVertex->getInfo());
        }
            for (auto &edge : currentVertex->getAdj()) {
                Vertex<string>* neighbor = edge.getDest();
                if (!neighbor->isVisited()) {
                    neighbor->setVisited(true);
                    q.push({neighbor, currentStops + 1});
                }
            }

    }
}
/**
 * @brief Auxiliary comparator class for topKAirports
 */
class pairCompare{
public:
    bool operator()(pair<string,int> below,pair<string,int> above){
        return below.second < above.second;

    }
};
/**
 * @brief Prints the top K airports with the greatest air traffic capacity.
 * @param k The number of airports to display.
 * @details Time complexity: O(N log K), where N is the total number of vertices in the flight graph.
 */
void Data::topKAirports(int k){
    unordered_map<string,int> flightsPerAirport;
    for(auto vertex: flightG->getVertexSet()){
        flightsPerAirport[vertex.second->getInfo()] += vertex.second->getAdj().size();
        for(auto edge:vertex.second->getAdj()){
            flightsPerAirport[edge.getDest()->getInfo()]++;
        }
    }
    priority_queue<pair<string,int>,vector<pair<string,int>>,pairCompare> queue;
    for(const auto& entry:flightsPerAirport){
        queue.emplace(entry);
    }
    cout << "The top " << k << " airports with the greatest air traffic capacity are:" << endl;
    for(int i = 0; i < k ; i++){
        cout << "Airport: " << queue.top().first << " Flights: " << queue.top().second << endl;
        queue.pop();
    }
}
/**
 * @brief Checks and prints the maximum number of stops between airports using bfs.
 * @details Time complexity: O(N*(N+E)), where N is the total number of vertices in the flight graph and E is total number of edges in the graph.
 */
void Data::checkMaximumTripStops() {

    stack<pair<string,string>> source_dest;
    int numberOfStops = maxTrip(source_dest);
    cout << "/*********************************/" << endl;
    cout << "Maximum number of stops is " << numberOfStops << endl;
    cout << "The pair(s) of the corresponding airports are:" << endl;
    while(!source_dest.empty()){
        cout << airports_[source_dest.top().first]->getName() << " -> " << airports_[source_dest.top().second]->getName() << endl;
        source_dest.pop();
    }
    cout << "/*********************************/" << endl;
}




/**
 * @brief Checks the maximum number of stops between airports using bfs.
 * @param maxTrips
 * @return maxDist - the distance of the longest trip(s)
 * @details Time complexity: O(N*(N+E)), where N is the total number of vertices in the flight graph and E is total number of edges in the graph.
 */
int Data::maxTrip(stack<pair<string, string>> &maxTrips) {
    int maxDist = INT_MIN;
    stack<pair<string,string>> stack;
    for(auto vertex: flightG->getVertexSet()){

        int dist = findMaxTripBfs(stack,vertex.second);
        if( dist > maxDist){
            maxTrips = stack;
            maxDist = dist;
        }
        else if( dist == maxDist){
            while(!stack.empty()){
                maxTrips.push(stack.top());
                stack.pop();
            }
        }
    }
    return maxDist;
}
/**
 * @brief Using bfs, calculates the distance of each vertex from source, then finds the farthest vertices and creates pairs for them.
 * @param pairs
 * @param source
 * @details Time complexity: O(N+E), where N is the total number of vertices in the graph and E is the total number of edges in the graph
 * @return max number of stops that a trip can have
 */
int Data::findMaxTripBfs(stack<pair<string, string>> &pairs, Vertex<string> *source) {
    unordered_set<Vertex<string>*> seen;
    queue<Vertex<string>*> queue;
    for(auto v: flightG->getVertexSet()){
        v.second->setVisited(false);
        v.second->setNum(INT_MIN);
    }
    source->setNum(0);
    source->setVisited(true);
    queue.push(source);
    while(!queue.empty()){
        Vertex<string>* u = queue.front();
        queue.pop();
        unordered_set<Vertex<string>*> locations;
        for(auto edge: u->getAdj()){
            locations.insert(edge.getDest());
        }
        for(auto location: locations){
            if(!location->isVisited()){
                seen.insert(location);
                location->setNum(u->getNum()+1);
                location->setVisited(true);
                queue.push(location);
            }
        }



    }
    int maxDist = INT_MIN;
    for(Vertex<string>* vertex:seen){
        if(vertex->getNum() > maxDist){
            maxDist = vertex->getNum();
            pairs = stack<pair<string,string>>();
            pairs.push({source->getInfo(), vertex->getInfo()});
        }
        else if(vertex->getNum() == maxDist){
            pairs.push({source->getInfo(), vertex->getInfo()});
        }
    }
    return maxDist;
}

/**
 * @brief Finds essential airports for circulation in the graph.
 * @return A vector of essential airports.
* @details Time complexity: O(V+E), where V is the number of vertices in the flight graph and E the edges.
 */

vector<string> Data::essentialAirportsForCirculation(){
    vector<string> airports;
    stack<string> nodes;
    for(auto vertex:flightG->getVertexSet()){
        vertex.second->setNum(0);
        vertex.second->setLow(0);
        vertex.second->setVisited(false);
        vertex.second->setProcessing(false);
    }
    int i = 1;
    for(auto vertice:flightG->getVertexSet()){
        if(!vertice.second->isVisited()){
            dfs_art(vertice.second,nodes,airports,i);
        }
    }
    return airports;
}
/**
 * @brief Depth-first search for finding essential airports for circulation.
 * @param currentVertex The current vertex during DFS.
 * @param traversalStack A stack to store the visited airports.
 * @param criticalAirports A vector to store the essential airports.
 * @param index An integer reference for assigning unique numbers to vertices.
 */

void Data::dfs_art(Vertex<string>* currentVertex, stack<string>& traversalStack, vector<string>& criticalAirports, int& index){
    bool isArticulationPoint = false;
    int childCount = 0;

    currentVertex->setVisited(true);
    currentVertex->setProcessing(true);
    currentVertex->setNum(index);
    currentVertex->setLow(index);
    traversalStack.push(currentVertex->getInfo());
    index++;

    for (auto adjacentEdge : currentVertex->getAdj()) {
        auto nextVertex = adjacentEdge.getDest();
        if (!nextVertex->isVisited()) {
            childCount++;
            dfs_art(nextVertex, traversalStack, criticalAirports, index);

            currentVertex->setLow(min(currentVertex->getLow(), nextVertex->getLow()));
            if (nextVertex->getLow() >= currentVertex->getNum()) {
                isArticulationPoint = true;
            }
        } else if (nextVertex->isProcessing()) {
            currentVertex->setLow(min(currentVertex->getLow(), nextVertex->getNum()));
        }
    }

    if ((currentVertex->getLow() == currentVertex->getNum() && childCount > 1) ||
        (currentVertex->getLow() != currentVertex->getNum() && isArticulationPoint)) {
        bool exitLoop = false;
        while (true) {
            string airport = traversalStack.top();
            traversalStack.pop();
            currentVertex->setProcessing(false);
            if (airport == currentVertex->getInfo()) {
                exitLoop = true;
            }
            if (exitLoop) {
                break;
            }
        }
        criticalAirports.push_back(currentVertex->getInfo());
    }
}

/**
 * @brief Checks and prints essential airports for circulation in the graph.
 */

void Data::checkEssentialAirports() {
    vector<string> essentialAirports = essentialAirportsForCirculation();
    cout << "Number of essential airports: " << essentialAirports.size() << endl;
    cout << "With them being: " << endl;
    for(const auto& airport:essentialAirports){
        cout << airports_[airport]->getName() << " - ";
    }
    cout << endl;
}

/**
 * @brief Finds the best flight options from a set of source airports to a set of destination airports, while minimizing the number of airlines.
 * @param source A vector of Vertex pointers representing the source airports.
 * @param dest A vector of Vertex pointers representing the destination airports.
 * @param allowed A unordered set of strings representing the allowed airlines.
 * @details Time complexity: O(S*(V+E)), where S is the number of vertices in the source vector, V is the total number of vertices in the flight graph and E is the total number of edges in the graph.
 */
void Data::bestFlightOptionMin(vector<Vertex<string> *> sourceNodes, vector<Vertex<string> *> destNodes,unordered_set<string> allowed) {
    vector<pair<vector<string>,unordered_set<string>>> pathsDiscovered;
    vector<string> path;
    vector<vector<string>> airlinePerEdge;
    for(auto sourceVertex: sourceNodes){
        bfsBestFlightOption(sourceVertex,allowed);
        Graph<string> reverse = getReverseGraph();
        Vertex<string>* reverseSource = reverse.findVertex(sourceVertex->getInfo());
        for(auto destVertex: destNodes){
            Vertex<string>* reverseDest = reverse.findVertex(destVertex->getInfo());
            reverseDfsBestFlightOptionMin(reverseDest,reverseSource,pathsDiscovered,path,airlinePerEdge);
        }
    }
    filterForSmallestAndAirlines(pathsDiscovered);
    cout << "Number of paths found: " << pathsDiscovered.size() << endl;
    for(auto currentPath:pathsDiscovered){
        for(auto airport: currentPath.first){
            cout << airport << " -> ";
        }
        cout << currentPath.first.size() << " airports visited ";

        cout << "| " << currentPath.second.size() << " airlines used\n";
    }
}
/**
 * @brief filters pathsDiscovered to only have the shortest paths.
 * @param pathsDiscovered
 * @details Time complexity: O(n) where n is the number of elements in the vector.
 */
void Data::fiterForSmallest(vector<vector<string>> &pathsDiscovered) {
    vector<vector<string>> result;
    int minSize = INT_MAX;
    for(auto path:pathsDiscovered){
        if(path.size() < minSize ){
            result.clear();
            result.push_back(path);
            minSize = path.size();
        }
        else if ( path.size() == minSize){
            result.push_back(path);
        }
    }
    pathsDiscovered = result;
}
/**
 * @brief Traverses the reversed graph starting on the dest node and through nodes of distance one less of the current node.
 * @param dest
 * @param source
 * @param pathsDiscovered
 * @param path
 * @details Time complexity: O(E) where E is the number of outgoing edges of source.
 */
void Data::reverseDfsBestFlightOptionMin(Vertex<string> *dest, Vertex<string> *source,vector<pair<vector<string>, unordered_set<string>>> &pathsDiscovered,vector<string> path, vector<vector<string>> airlinesPerEdge) {
    path.push_back(dest->getInfo());
    if(dest == source){
        reverse(path.begin(),path.end());
        unordered_set<string> optimized = optimizeAirlines(airlinesPerEdge);
        pathsDiscovered.push_back({path,optimized});
        return;
    }
    unordered_map<Vertex<string>*,vector<string>> locations;
    for(auto edge:dest->getAdj()){
        locations[edge.getDest()].push_back(edge.getAirline());
    }
    for(auto location:locations){
        if(location.first->getNum() == dest->getNum() - 1){
            vector<vector<string>>  newAirlines = airlinesPerEdge;
            newAirlines.push_back(location.second);
            reverseDfsBestFlightOptionMin(location.first,source,pathsDiscovered,path,newAirlines);
        }
    }
}
/**
 * @brief filters pathsDiscovered to only have the paths that are shortest and have the least airlines.
 * @param pathsDiscovered
 * @details Time complexity: O(n) where n is the number of elements in the vector.
 */
void Data::filterForSmallestAndAirlines(vector<pair<vector<string>, unordered_set<string>>> &pathsDiscovered) {
    int minAirports = INT_MAX;
    int minAirlines = INT_MAX;
    vector<pair<vector<string>, unordered_set<string>>> result;
    for(auto path:pathsDiscovered){
        if(path.first.size() < minAirports){
            result.clear();
            result.push_back(path);
            minAirports = path.first.size();
            minAirlines = path.second.size();
        }
        else if (path.first.size() == minAirports){
            if(path.second.size() < minAirlines){
                result.clear();
                result.push_back(path);
                minAirlines = path.second.size();
            }
            else if(path.second.size() == minAirlines){
                result.push_back(path);
            }
        }
    }
    pathsDiscovered = result;

}






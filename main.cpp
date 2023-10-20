#include "DataProcessor.h"

int main(){
    std::cout << "Hello, World!" << std::endl;
    std::ifstream inputFile("ball.txt");
    if (inputFile.is_open()) {
        // File opened successfully
    } else {
        std::cerr << "Error opening the CSV file." << std::endl;
        return 1;
    }
    return 0;
}
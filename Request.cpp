//
// Created by sergio on 29-10-2023.
//

#include <fstream>
#include <sstream>
#include "Request.h"
// each line of RequestHistory.csv goes : StudentName, id, type (add, remove or switch), recipient( UC or class), startCode, endCode

void Request::performRequest(Student &student, set<Class_UC> existingClassesUc, std::string type, std::string ) {
    // TODO: check if possible to remove and, if so, alter internal memory and files ( output: ACCEPTED or DENIED)

}

void Request::lookupAllRequests() {
    ifstream file("RequestHistory.csv");
    if(!(file.is_open())){
        cout << "Couldn't find 'RequestHistory.csv' file";
        return ;
    }
    string line;
    int RequestID = 1;
    while(getline(file, line)){
        istringstream separate_comma(line);
        string StudentName, id, type , recipient, startCode, endCode;
        getline(separate_comma, StudentName, ',');
        getline(separate_comma, id, ',');
        getline(separate_comma, type, ',');
        getline(separate_comma, recipient, ',');
        getline(separate_comma, startCode, ',');
        getline(separate_comma, endCode, ',');
        if(type == "switch"){
            cout <<"RequestID:" << RequestID << " Student Name:" <<  StudentName << "(" << id << ") Type: switch(" << recipient << ") " << startCode << " -> " << endCode;
        }
        else{
            cout <<"RequestID:" << RequestID << " Student Name:" << StudentName << "(" << id << ") Type: "<< type << "(" << recipient << ") " << startCode;

        }
        RequestID++;


    }



}



void Request::saveRequest(Student &student, string type, string recipient, string startCode, string endCode) {
    ofstream file("RequestHistory.csv");
    if(!(file.is_open())) {
        cout << "Couldn't find 'RequestHistory.csv' file";
        return;
    }
    file << student.getName() <<"," <<student.getId() << "," << recipient << "," << startCode << "," << endCode << endl;
    file.close();

}

void Request::undoRequest(int RequestID) {
    int counter = 1;
    ifstream file("RequestHistory.csv");
    ofstream temp("tempFile.csv");
    if(!(file.is_open())) {
        cout << "Couldn't find 'RequestHistory.csv' file";
        return;

    }
    string line;
    while(getline(file,line))   {
        if(counter == RequestID){ // skipped adding line
            // TODO: performRequest() (reversed)
        }
        else{
            temp << line;
        }
    }

}



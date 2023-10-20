#include "DataProcessor.h"

int main(){
    DataProcessor parseData;
    parseData.classes_per_uc();
    set<Class_UC> UcAndClasses = parseData.getClassUc();
    for(auto ucClass: UcAndClasses){
        ucClass.printUcAndClasses();
    }

}
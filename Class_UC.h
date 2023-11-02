#ifndef AED_PROJECT_UC_H
#define AED_PROJECT_UC_H
#include <string>
#include <set>
#include <iostream>

using namespace std;
/**
 * @brief Class that stores the ucCode of a class
 */

class Class_UC{
    private:
        /** @brief Code of a Uc */
        string ucCode;
        /** @brief Code of a Class */
        string classCode;
    public:
        /** @brief Default Constructor of Class_UC. ClassCode and ucCode are set to empty strings
        *   @details Time complexity - O(1)
        */
        Class_UC(const string &classCode_ ="" ,const string &ucCode_ = "");
        const string &getUcCode() const;
        void setUcCode(const string &ucCode);
        const string &getClassCode() const;
        void setClassCode(const string &classCode);
        bool operator<(const Class_UC &other) const;
        bool operator==(const Class_UC &other) const;
};

#endif //AED_PROJECT_UC_H
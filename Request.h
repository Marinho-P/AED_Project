#ifndef AED_PROJECT_REQUEST_H
#define AED_PROJECT_REQUEST_H
#include <string>
#include "Student.h"

/**
 * @brief Class that stores the information of a Request with a given student, type of request, the wanted or unwanted UcCode, and a startCode/endCode having meaning only in a switch request
 */
using namespace std;
class Request {
private:
    Student student;
    /** @brief There are three types of requests:
     * add/remove - Lets a student to either leave/join a certain Uc or class
     * switch - Lets a student trade their old Uc or class for a new one
     */
    string type;
    string UcCode;
    /** @brief In a switch request the startCode represents the previously registered classCode. If not that type of request its represented by a "-" */
    string startCode;
    /** @brief In a switch request the endCode represents the newly registered classCode. If not that type of request its represented by a "-" */
    string endCode;
public:
    Request(Student &student, const string &type, const string &ucCode,const string &startCode, const string &endCode);
    const string &getType() const;
    const string &getUcCode() const;
    const string &getStartCode() const;
    const string &getEndCode() const;
    Student& getStudent();
};

#endif //AED_PROJECT_REQUEST_H

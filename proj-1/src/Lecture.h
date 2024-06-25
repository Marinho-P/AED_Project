#ifndef AED_PROJECT_AULA_H
#define AED_PROJECT_AULA_H
#include <string>
using namespace std;

/**
 * @brief Class that represents a Lecture's duration, startHour, type, Uc and what day of the week takes place
 */

class Lecture{
    private:
        float duration;
        float startHour;
        /** @brief All types of a Uc:
        * P - Prática
        * T - Teórica
        * PL - Prática Laboratorial
        */
        string type;
        string weekday;
        /** @brief UcCode of a Lecture */
        string UC_Code;
    public:
        Lecture(const float &duration,const float &startHour, const string &type, const string &weekday, const string &Uc_Code);
        void setStartHour(float startHour);
        const string &getType() const;
        const float &getDuration() const;
        const string &getWeekday() const;
        const string &getUcCode() const;
        bool operator<(const Lecture& other) const;
        const float &getStartHour() const;
};

#endif //AED_PROJECT_AULA_H
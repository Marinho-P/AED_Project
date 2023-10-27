#ifndef AED_PROJECT_AULA_H
#define AED_PROJECT_AULA_H
#include <string>
using namespace std;

class Lecture{
    private:
        string duration;
        string startHour;
        string type;
        string weekday;
        string UC_Code;
    public:
        Lecture(const string &duration,const string &startHour, const string &type, const string &weekday, const string &Uc_Code);
        const string &getType() const;
        void setType(const string &type);
        const string &getWeekday() const;
        void setWeekday(const string &weekday);
        const string &getUcCode() const;
        bool operator<(const Lecture& other) const;
};

#endif //AED_PROJECT_AULA_H

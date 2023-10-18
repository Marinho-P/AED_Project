#ifndef AED_PROJECT_AULA_H
#define AED_PROJECT_AULA_H
#include <string>
using namespace std;

class Lecture{
    private:
        int duration;
        int startHour;
        string type;
        string weekday;
    public:
        Lecture(int duration, int startHour, const string &type, const string &weekday);
        int getDuration() const;
        void setDuration(int duration);
        int getStartHour() const;
        void setStartHour(int startHour);
        const string &getType() const;
        void setType(const string &type);
        const string &getWeekday() const;
        void setWeekday(const string &weekday);
};

#endif //AED_PROJECT_AULA_H

#ifndef COURSEWORK_DATE_H
#define COURSEWORK_DATE_H

#include <ostream>

using namespace std;

class Date {
private:
    int year, month, day;
protected:
    static int validateMonth(int month);

    static int validateDay(int day);

    static int validateYear(int year);

public:
    Date(int year, int month, int day);

    int getYear() const;

    void setYear(int year);

    int getMonth() const;

    void setMonth(int month);

    int getDay() const;

    void setDay(int day);

    friend ostream &operator<<(ostream &os, const Date &date);
};


#endif //COURSEWORK_DATE_H

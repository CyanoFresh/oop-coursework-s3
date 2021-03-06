#ifndef COURSEWORK_DATE_H
#define COURSEWORK_DATE_H

#include "ValidationException.h"
#include "Writable.h"
#include "nlohmann/json.hpp"
#include "Readable.h"

using namespace std;
using namespace nlohmann;

class Date: public Writable, public Readable {
private:
    int year = 0;
    int month = 0;
    int day = 0;
protected:
    static int validateMonth(int month);

    static int validateDay(int day);

    static int validateYear(int year);

public:
    Date(int year, int month, int day);

    Date() = default;

    int getYear() const;

    void setYear(int year);

    int getMonth() const;

    void setMonth(int month);

    int getDay() const;

    void setDay(int day);

    friend ostream &operator<<(ostream &os, const Date &date);

    void write(ofstream &stream) override;

    json jsonSerialize();

    void read(ifstream &ifstream) override;
};


#endif //COURSEWORK_DATE_H

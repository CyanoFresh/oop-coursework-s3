#include <stdexcept>
#include "Date.h"

Date::Date(int year, int month, int day)
        : year(year),
          month(checkMonth(month)),
          day(checkDay(day)) {}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = checkDay(month);
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = checkDay(day);
}

int Date::checkMonth(int month) {
    if (month < 1 || month > 12) {
        throw invalid_argument("Wrong Date month: should be between 1 and 12");
    }

    return month;
}

int Date::checkDay(int day) {
    if (day < 1 || day > 31) {
        throw invalid_argument("Wrong Date day: should be between 1 and 31");
    }

    return day;
}

ostream &operator<<(ostream &os, const Date &date) {
    return os << "[Date] year: " << date.year << " month: " << date.month << " day: " << date.day;
}

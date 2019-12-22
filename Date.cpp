#include "Date.h"
#include "ValidationException.h"

Date::Date(int year, int month, int day)
        : year(year),
          month(validateMonth(month)),
          day(validateDay(day)) {}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = validateYear(year);
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = validateDay(month);
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = validateDay(day);
}

int Date::validateYear(int year){
    if (year < 1980 || year > 2100) {
        throw ValidationException("Wrong Date year: are you time traveler?");
    }

    return year;
}

int Date::validateMonth(int month) {
    if (month < 1 || month > 12) {
        throw ValidationException("Wrong Date month: should be between 1 and 12");
    }

    return month;
}

int Date::validateDay(int day) {
    if (day < 1 || day > 31) {
        throw ValidationException("Wrong Date day: should be between 1 and 31");
    }

    return day;
}

ostream &operator<<(ostream &os, const Date &date) {
    return os << date.year << "." << date.month << "." << date.day;
}
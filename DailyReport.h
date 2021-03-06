#ifndef COURSEWORK_DAILYREPORT_H
#define COURSEWORK_DAILYREPORT_H


#include <ostream>
#include "Order.h"
#include "Date.h"
#include "table/ATable.h"
#include "nlohmann/json.hpp"

using namespace nlohmann;

class DailyReport {
    Array<Order *> orders;
    Date date;
public:
    DailyReport(const Array<Order *> &orders, const Date &date);

    DailyReport() = default;

    ~DailyReport() = default;

    const Array<Order *> &getOrders() const;

    Order *operator[](int i);

    void setOrders(Array<Order *> orders);

    const Date &getDate() const;

    void setDate(const Date &date);

    void addOrder(Order *order);

    friend ostream &operator<<(ostream &os, DailyReport *report);

    json jsonSerialize();

    void clear();

    void jsonDeserialize(ifstream &stream);

    void searchByText(const string &str);

    void searchByNum(const int num);
};


#endif //COURSEWORK_DAILYREPORT_H

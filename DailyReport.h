#ifndef COURSEWORK_DAILYREPORT_H
#define COURSEWORK_DAILYREPORT_H


#include <ostream>
#include "Order.h"
#include "Date.h"

class DailyReport {
    Array<Order *> orders;
    Date date;
public:
    DailyReport(const Array<Order *> &orders, const Date &date);

    DailyReport() = default;

    const Array<Order *> &getOrders() const;

    Order *operator[](int i);

    void setOrders(Array<Order *> orders);

    const Date &getDate() const;

    void setDate(const Date &date);

    void addOrder(Order *order);

    friend ostream &operator<<(ostream &os, DailyReport *report);
};


#endif //COURSEWORK_DAILYREPORT_H

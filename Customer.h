#ifndef COURSEWORK_CUSTOMER_H
#define COURSEWORK_CUSTOMER_H


#include <ostream>

using namespace std;

class Customer {
    long id = 0;
    float total = 0;
    float discount = 0;
protected:
    static float validateTotal(float total);

    static float validateDiscount(float discount);

    static long validateId(long id);

public:
    Customer(long id, float total, float discount);

    Customer() = default;

    long getId() const;

    void setId(long id);

    float getTotal() const;

    void setTotal(float total);

    float getDiscount() const;

    void setDiscount(float discount);

    friend std::ostream &operator<<(std::ostream &os, const Customer &customer);

    friend std::istream &operator>>(std::istream &is, Customer *customer);
};


#endif //COURSEWORK_CUSTOMER_H

#ifndef COURSEWORK_CUSTOMER_H
#define COURSEWORK_CUSTOMER_H


#include <ostream>

using namespace std;

class Customer {
private:
    long id;
    float total;
    float discount;
protected:
    static float checkTotal(float total);

    static float checkDiscount(float discount);

public:
    Customer(long id, float total, float discount);

    long getId() const;

    void setId(long id);

    float getTotal() const;

    void setTotal(float total);

    float getDiscount() const;

    void setDiscount(float discount);

    friend std::ostream &operator<<(std::ostream &os, const Customer &customer);
};


#endif //COURSEWORK_CUSTOMER_H

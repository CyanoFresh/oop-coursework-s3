#ifndef COURSEWORK_CUSTOMER_H
#define COURSEWORK_CUSTOMER_H


#include <ostream>
#include "Writable.h"
#include "nlohmann/json.hpp"
#include "ValidationException.h"

using namespace std;
using namespace nlohmann;

class Customer: public Writable {
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

    void write(ofstream &stream);

    json jsonSerialize();

    void read(ifstream &ifstream);
};


#endif //COURSEWORK_CUSTOMER_H

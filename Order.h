#ifndef COURSEWORK_ORDER_H
#define COURSEWORK_ORDER_H


#include "Customer.h"
#include "Product.h"
#include "Date.h"

class Order {
    Customer customer;
    Product *products;
    Date date;
    float totalPrice;
    float total;
};


#endif //COURSEWORK_ORDER_H

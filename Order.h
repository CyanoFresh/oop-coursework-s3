#ifndef COURSEWORK_ORDER_H
#define COURSEWORK_ORDER_H


#include "Customer.h"
#include "Product.h"
#include "Date.h"
#include "Array.h"

class Order {
    Customer *customer;
    Array <Product> products;
    Date date;
    float totalPrice;
    float total;
public:
    Order(Customer *customer, const Array<Product>& products, const Date &date, float totalPrice, float total);
    Order();

    Customer *getCustomer() const;

    void setCustomer(Customer *customer);

    const Array<Product> &getProducts() const;

    void setProducts(const Array<Product> &products);

    const Date &getDate() const;

    void setDate(const Date &date);

    float getTotalPrice() const;

    void setTotalPrice(float totalPrice);

    float getTotal() const;

    void setTotal(float total);
};


#endif //COURSEWORK_ORDER_H

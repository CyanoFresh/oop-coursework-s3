#include "Order.h"

#include <utility>

Order::Order(Customer *customer, const Array<Product> &products, const Date &date, float totalPrice, float total)
        : customer(customer),
          products(products),
          date(date),
          totalPrice(totalPrice),
          total(total) {}


Order::Order() {}

Customer *Order::getCustomer() const {
    return customer;
}

void Order::setCustomer(Customer *customer) {
    Order::customer = customer;
}

const Array<Product> &Order::getProducts() const {
    return products;
}

void Order::setProducts(const Array<Product> &products) {
    Order::products = products;
}

const Date &Order::getDate() const {
    return date;
}

void Order::setDate(const Date &date) {
    Order::date = date;
}

float Order::getTotalPrice() const {
    return totalPrice;
}

void Order::setTotalPrice(float totalPrice) {
    Order::totalPrice = totalPrice;
}

float Order::getTotal() const {
    return total;
}

void Order::setTotal(float total) {
    Order::total = total;
}

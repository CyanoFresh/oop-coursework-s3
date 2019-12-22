#include "Order.h"
#include "ValidationException.h"

Order::Order(Customer *customer, Array<Product *> products, const Date &date, float totalPrice, float total)
        : customer(customer),
          products(products),
          date(date),
          totalWithDiscount(validateTotalWithDiscount(totalPrice)),
          total(validateTotal(total)) {
    recalculate();
}

Customer *Order::getCustomer() const {
    return customer;
}

void Order::setCustomer(Customer *customer) {
    Order::customer = customer;
}

const Array<Product *> &Order::getProducts() const {
    return products;
}

void Order::setProducts(Array<Product *> products) {
    Order::products = products;
    recalculate();
}

const Date &Order::getDate() const {
    return date;
}

void Order::setDate(const Date &date) {
    Order::date = date;
}

float Order::getTotalPrice() const {
    return totalWithDiscount;
}

void Order::setTotalPrice(float totalPrice) {
    Order::totalWithDiscount = validateTotalWithDiscount(totalPrice);
}

float Order::getTotal() const {
    return total;
}

void Order::setTotal(float total) {
    Order::total = validateTotal(total);
}

float Order::validateTotal(float total) {
    if (total < 0) {
        throw ValidationException("Wrong Order total: should be greater than 0");
    }
    return total;
}

float Order::validateTotalWithDiscount(float totalWithDiscount) {
    if (totalWithDiscount < 0 || total > totalWithDiscount) {
        throw ValidationException("Wrong Order totalWithDiscount: should be greater than 0 and total price");
    }
    return totalWithDiscount;
}

void Order::addProduct(Product *product) {
    products.assign(product);
    recalculate();
}

Product *Order::operator[](int i) {
    return products[i];
}

void Order::recalculate() {
    for (int i = 0; i < products.size(); ++i) {
        Order::total += products[i]->getPrice();
        Order::totalWithDiscount += products[i]->getPrice();
        if (products[i]->isHasDiscount()) {
            Order::totalWithDiscount -= products[i]->getPrice() * customer->getDiscount();
        }
    }
}
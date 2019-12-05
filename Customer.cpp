#include "Customer.h"
#include <stdexcept>

Customer::Customer(long id, float total, float discount)
        : id(id),
          total(checkTotal(total)),
          discount(checkDiscount(discount)) {}

long Customer::getId() const {
    return id;
}

void Customer::setId(long id) {
    Customer::id = id;
}

float Customer::getTotal() const {
    return total;
}

void Customer::setTotal(float total) {
    Customer::total = checkTotal(total);
}

float Customer::getDiscount() const {
    return discount;
}

void Customer::setDiscount(float discount) {
    Customer::discount = checkDiscount(discount);
}

std::ostream &operator<<(std::ostream &os, const Customer &customer) {
    return os << "[Customer] id: " << customer.id << " total: " << customer.total << " discount: " << customer.discount;
}

float Customer::checkTotal(float total) {
    if (total < 0) {
        throw invalid_argument("Wrong Customer total: should be greater than 0");
    }
    return total;
}

float Customer::checkDiscount(float discount) {
    if (discount < 0 || discount > 1) {
        throw invalid_argument("Wrong Customer discount: should be between 0 and 1");
    }
    return discount;
}

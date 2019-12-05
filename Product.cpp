#include "Product.h"

Product::Product(const string& name, float price, bool hasDiscount)
        : name(checkName(name)),
          price(checkPrice(price)),
          hasDiscount(checkHasDiscount(hasDiscount)) {}

const string &Product::getName() const {
    return name;
}

void Product::setName(const string &name) {
    Product::name = name;
}

float Product::getPrice() const {
    return price;
}

void Product::setPrice(float price) {
    Product::price = price;
}

bool Product::isHasDiscount() const {
    return hasDiscount;
}

void Product::setHasDiscount(bool hasDiscount) {
    Product::hasDiscount = hasDiscount;
}

ostream &operator<<(ostream &os, const Product &product) {
    return os << "[Product] name: " << product.name << " price: " << product.price << " hasDiscount: " << product.hasDiscount;;
}

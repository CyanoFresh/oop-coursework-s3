#include "Product.h"
#include "ValidationException.h"

Product::Product(const string &name, float price, bool hasDiscount)
        : name(validateName(name)),
          price(validatePrice(price)),
          hasDiscount(validateHasDiscount(hasDiscount)) {}

const string &Product::getName() const {
    return name;
}

void Product::setName(const string &name) {
    Product::name = validateName(name);
}

float Product::getPrice() const {
    return price;
}

void Product::setPrice(float price) {
    Product::price = validatePrice(price);
}

bool Product::isHasDiscount() const {
    return hasDiscount;
}

void Product::setHasDiscount(bool hasDiscount) {
    Product::hasDiscount = validateHasDiscount(hasDiscount);
}

ostream &operator<<(ostream &os, const Product &product) {
    return os << "[Product] name: " << product.name << " price: " << product.price << " hasDiscount: "
              << product.hasDiscount;;
}

string Product::validateName(const string &name) {
    if (name.length() < 3 || name.length() > 255) {
        throw ValidationException("Product name should be longer than 3 and shorter than 255 symbols");
    }
    return name;
}

float Product::validatePrice(float price) {
    if (price < 0) {
        throw ValidationException("Product price should be greater than 0");
    }
    return price;
}

bool Product::validateHasDiscount(bool hasDiscount) {
    return hasDiscount;
}

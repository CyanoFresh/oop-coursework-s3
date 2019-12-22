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

istream &operator>>(istream &is, Product *product) {

    do {
        string tmp;
        cout << "Enter product name: " << endl;

        is.clear();
        is.sync();

        getline(is, tmp);

        try {
            product->setName(tmp);
        } catch (ValidationException &e) {
            cerr << e.what() << endl;
            continue;
        }

        break;
    } while (true);

    do {
        float tmp;
        cout << "Enter product price: " << endl;
        is >> tmp;

        try {
            product->setPrice(tmp);
        } catch (ValidationException &e) {
            cerr << e.what() << endl;
            continue;
        }

        break;
    } while (true);

    do {
        bool tmp;
        cout << "Enter has discount (0 = no): " << endl;
        is >> tmp;

        try {
            product->setHasDiscount(tmp);
        } catch (ValidationException &e) {
            cerr << e.what() << endl;
            continue;
        }

        break;
    } while (true);

    return is;
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

bool Product::operator==(const Product &rhs) const {
    return name == rhs.name &&
           price == rhs.price &&
           hasDiscount == rhs.hasDiscount;
}

bool Product::operator!=(const Product &rhs) const {
    return !(rhs == *this);
}
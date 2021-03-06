#ifndef COURSEWORK_PRODUCT_H
#define COURSEWORK_PRODUCT_H

#include <string>
#include <ostream>
#include "nlohmann/json.hpp"
#include "ValidationException.h"
#include "Readable.h"
#include "Writable.h"

using namespace std;
using namespace nlohmann;

class Product : public Readable, public Writable {
    string name;
    float price = 0;
    bool hasDiscount = false;
protected:
    static string validateName(const string &name);

    static float validatePrice(float price);

    static bool validateHasDiscount(bool hasDiscount);

public:
    Product(const string &name, float price, bool hasDiscount);

    Product() = default;

    const string &getName() const;

    void setName(const string &name);

    float getPrice() const;

    void setPrice(float price);

    bool isHasDiscount() const;

    void setHasDiscount(bool hasDiscount);

    friend ostream &operator<<(ostream &os, const Product &product);

    friend istream &operator>>(istream &is, Product *product);

    bool operator==(const Product &rhs) const;

    bool operator!=(const Product &rhs) const;

    void write(ofstream &stream) override;

    json jsonSerialize();

    void read(ifstream &stream) override;

    template<class T>
    Product operator+(T plusPrice);
};


#endif //COURSEWORK_PRODUCT_H

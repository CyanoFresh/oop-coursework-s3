#ifndef COURSEWORK_PRODUCT_H
#define COURSEWORK_PRODUCT_H

#include <string>
#include <ostream>

using namespace std;

class Product {
    string name;
    float price;
    bool hasDiscount;
protected:
    static string validateName(const string &name);

    static float validatePrice(float price);

    static bool validateHasDiscount(bool hasDiscount);

public:
    Product(const string &name, float price, bool hasDiscount);

    const string &getName() const;

    void setName(const string &name);

    float getPrice() const;

    void setPrice(float price);

    bool isHasDiscount() const;

    void setHasDiscount(bool hasDiscount);

    friend ostream &operator<<(ostream &os, const Product &product);
};


#endif //COURSEWORK_PRODUCT_H

#ifndef COURSEWORK_ORDER_H
#define COURSEWORK_ORDER_H


#include "Customer.h"
#include "Product.h"
#include "Date.h"
#include "Array.h"

class Order: public Writable, public Readable {
    Customer *customer = nullptr;
    Array<Product *> products;
    Date date;
    float total = 0;
    float totalWithDiscount = 0;
protected:
    static float validateTotal(float total);

    float validateTotalWithDiscount(float totalWithDiscount);

public:
    Order(Customer *customer, Array<Product *> products, const Date &date, float totalPrice, float total);

    Order() = default;

    ~Order() = default;

    Customer *getCustomer() const;

    void setCustomer(Customer *customer);

    const Array<Product *> &getProducts() const;

    Product *operator[](int i);

    void addProduct(Product *product);

    void setProducts(Array<Product *> products);

    const Date &getDate() const;

    void setDate(const Date &date);

    float getTotalPrice() const;

    void setTotalPrice(float totalPrice);

    float getTotal() const;

    void setTotal(float total);

    void recalculate();

    void write(ofstream &stream) override;

    json jsonSerialize();

    void read(ifstream &stream) override;
};


#endif //COURSEWORK_ORDER_H

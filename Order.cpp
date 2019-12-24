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

void Order::write(ofstream &stream) {
    stream.write((char *) &total, sizeof(total));
    stream.write((char *) &totalWithDiscount, sizeof(totalWithDiscount));

    date.write(stream);
    customer->write(stream);

    unsigned int size = products.size();
    stream.write((char *) &size, sizeof(size));

    for (int i = 0; i < size; ++i) {
        products[i]->write(stream);
    }
}

json Order::jsonSerialize() {
    json obj;
    obj["products"] = products.jsonSerialize();
    obj["customer"] = customer->jsonSerialize();
    obj["total"] = total;
    obj["totalWithDiscount"] = totalWithDiscount;
    return obj;
}

void Order::read(ifstream &stream) {
    stream.read((char *) &total, sizeof(float));
    stream.read((char *) &totalWithDiscount, sizeof(float));

    date.read(stream);
    customer = new Customer();
    customer->read(stream);

    int size;
    stream.read((char *) &size, sizeof(int));
    for (size_t i = 0; i < size; i++) {
        auto product = new Product();
        product->read(stream);
        addProduct(product);
        delete product;
    }
}

template<class T>
Order Order::operator+(T plusTotal) {
    totalWithDiscount += plusTotal;
    return *this;
}

void Order::jsonDeserialize(json j) {
    date = Date(j["date"][0], j["date"][1], j["date"][2]);
    total = j["total"];
    totalWithDiscount = j["totalWithDiscount"];
}

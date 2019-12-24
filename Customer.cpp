#include "Customer.h"
#include "ValidationException.h"

Customer::Customer(long id, float total, float discount)
        : id(validateId(id)),
          total(validateTotal(total)),
          discount(validateDiscount(discount)) {}

long Customer::getId() const {
    return id;
}

void Customer::setId(long id) {
    Customer::id = validateId(id);
}

float Customer::getTotal() const {
    return total;
}

void Customer::setTotal(float total) {
    Customer::total = validateTotal(total);
}

float Customer::getDiscount() const {
    return discount;
}

void Customer::setDiscount(float discount) {
    Customer::discount = validateDiscount(discount);
}

std::ostream &operator<<(std::ostream &os, const Customer &customer) {
    return os << "[Customer] id: " << customer.id << " total: " << customer.total << " discount: " << customer.discount;
}

long Customer::validateId(long id) {
    if (id < 0) {
        throw ValidationException("Wrong Customer id: should be greater than 0");
    }
    return id;
}

float Customer::validateTotal(float total) {
    if (total < 0) {
        throw ValidationException("Wrong Customer total: should be greater than 0");
    }
    return total;
}

float Customer::validateDiscount(float discount) {
    if (discount < 0 || discount > 1) {
        throw ValidationException("Wrong Customer discount: should be between 0 and 1");
    }
    return discount;
}

std::istream &operator>>(std::istream &is, Customer *customer) {
    do {
        long tmp;
        cout << "Enter customer id: " << endl;
        is >> tmp;

        try {
            customer->setId(tmp);
        } catch (ValidationException &e) {
            cerr << e.what() << endl;
            continue;
        }

        break;
    } while (true);

    do {
        float tmp;
        cout << "Enter customer total: " << endl;
        is >> tmp;

        try {
            customer->setTotal(tmp);
        } catch (ValidationException &e) {
            cerr << e.what() << endl;
            continue;
        }

        break;
    } while (true);

    while (true) {
        float tmp;
        cout << "Enter customer discount (0..1): " << endl;
        is >> tmp;

        try {
            customer->setDiscount(tmp);
        } catch (ValidationException &e) {
            cerr << e.what() << endl;
            continue;
        }

        break;
    }

    return is;
}

void Customer::write(ofstream &stream) {
    stream.write((char *) &id, sizeof(id));
    stream.write((char *) &total, sizeof(total));
    stream.write((char *) &discount, sizeof(discount));
}

json Customer::jsonSerialize() {
    json obj;
    obj["id"] = id;
    obj["total"] = total;
    obj["discount"] = discount;
    return obj;
}

void Customer::read(ifstream &ifstream) {
    ifstream.read((char *) &id, sizeof(id));
    ifstream.read((char *) &total, sizeof(total));
    ifstream.read((char *) &discount, sizeof(discount));
}

template<class T>
Customer Customer::operator+(T plusTotal) {
    total += plusTotal;
    return *this;
}

#include "DailyReport.h"

DailyReport::DailyReport(const Array<Order *> &orders, const Date &date) : orders(orders), date(date) {}

const Array<Order *> &DailyReport::getOrders() const {
    return orders;
}

void DailyReport::setOrders(Array<Order *> orders) {
    DailyReport::orders = orders;
}

void DailyReport::clear() {
    DailyReport::orders.clear();
}

const Date &DailyReport::getDate() const {
    return date;
}

void DailyReport::setDate(const Date &date) {
    DailyReport::date = date;
}

void DailyReport::addOrder(Order *order) {
    orders.assign(order);
}

Order *DailyReport::operator[](int i) {
    return orders[i];
}

ostream &operator<<(ostream &os, DailyReport *report) {
    os << "Order for " << report->date << endl;

    ATable::Table *table = new ATable::Table(ATable::DefaultAppearance(), "Orders");
    auto productTables = new vector<ATable::Table *>;

    table->addColumn(new ATable::SimpleColumn("Order #", 20));
    table->addColumn(new ATable::SimpleColumn("Customer Id", 20));
    table->addColumn(new ATable::SimpleColumn("Total", 20));
    table->addColumn(new ATable::SimpleColumn("With discount", 20));

    for (int i = 0; i < report->orders.size(); ++i) {
        Order *order = (*report)[i];

        table->addCell(0, new ATable::IntegerCell(i + 1));
        table->addCell(1, new ATable::IntegerCell(order->getCustomer()->getId()));
        table->addCell(2, new ATable::FloatCell(order->getTotal()));
        table->addCell(3, new ATable::FloatCell(order->getTotalPrice()));

        auto productsTable = new ATable::Table(ATable::DefaultAppearance(), &"Order Products "[i]);

        productsTable->addColumn(new ATable::SimpleColumn("Product #", 20));
        productsTable->addColumn(new ATable::SimpleColumn("Name", 20));
        productsTable->addColumn(new ATable::SimpleColumn("Price", 20));
        productsTable->addColumn(new ATable::SimpleColumn("Has discount", 20));

        for (int j = 0; j < order->getProducts().size(); ++j) {
            Product *product = (*order)[j];

            productsTable->addCell(0, new ATable::IntegerCell(j + 1));
            productsTable->addCell(1, new ATable::StringCell(product->getName()));
            productsTable->addCell(2, new ATable::FloatCell(product->getPrice()));
            productsTable->addCell(3, new ATable::IntegerCell(product->isHasDiscount()));
        }

        productTables->push_back(productsTable);
    }

    table->print(os);

    for (int i = 0; i < productTables->size(); i++) {
        os << endl << "Order #" << (i + 1) << " products: " << endl;
        productTables[0][i]->print(os);
    }

    delete table;
    delete productTables;

    return os;
}

json DailyReport::jsonSerialize() {
    json j;
    j["date"] = date.jsonSerialize();
    j["orders"] = orders.jsonSerialize();
    return j;
}

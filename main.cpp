#include <iostream>
#include "Date.h"
#include "ValidationException.h"
#include "Order.h"
#include "DailyReport.h"

using namespace std;

const int arrSize = 2;

string inputFilename() {
    string filename;

    while (true) {
        cin.clear();
        cin.sync();

        cout << "Enter filename:" << endl;

        getline(cin, filename);

        if (filename.empty()) {
            cerr << "Wrong filename" << endl;
            continue;
        }

        return filename;
    }
}

template<class T>
T averageProductsCount(Array<Order *> orders) {
    T sum = 0;

    for (int i = 0; i < orders.size(); ++i) {
        sum += orders[i]->getProducts().size();
    }

    return sum / orders.size();
}

template<typename T>
T averageTotal(Array<Order *> orders) {
    T sum = 0;

    for (int i = 0; i < orders.size(); ++i) {
        sum += orders[i]->getTotalPrice();
    }

    return sum / orders.size();
}

void handleCmd(const char cmd, DailyReport *dailyReport) {
    cout << "\n";

    switch (cmd) {
        case '1':
            for (int i = 0; i < 1; ++i) {
                cout << "Filling Order #" << i + 1 << " of " << arrSize << endl;

                auto order = new Order();
                auto customer = new Customer();

                cin >> customer;
                cout << endl;

                order->setCustomer(customer);

                for (int j = 0; j < arrSize; ++j) {
                    cout << "Filling Product #" << j + 1 << " of " << arrSize << endl;
                    auto product = new Product();
                    cin >> product;
                    cout << endl;
                    order->addProduct(product);
                }

                order->setDate(dailyReport->getDate());

                dailyReport->addOrder(order);
            }
            break;
        case '2':
            cout << dailyReport << endl;
            break;
        case '3':
            char choice;

            do {
                string filename;

                cout << "Select file type:" << endl;
                cout << "|1|  Binary\n";
                cout << "|2|  Text\n";
                cout << "|0|  Back\n";
                cout << "Enter option number:" << endl;

                cin >> choice;

                if (choice == '1' || choice == '2') {
                    filename = inputFilename();

                    ofstream file(filename, ios::binary);

                    if (!file.is_open()) {
                        cerr << "Cannot open file" << endl;
                        continue;
                    }

                    if (choice == '1') {
                        unsigned int size = dailyReport->getOrders().size();

                        file.write((char *) &size, sizeof(unsigned int));

                        for (int i = 0; i < size; i++) {
                            (*dailyReport)[i]->write(file);
                        }
                    } else if (choice == '2') {
                        file << dailyReport->jsonSerialize().dump(4);
                    }

                    file.close();
                    break;
                }
            } while (choice != '0');

            break;
        case '4': {
            string filename = inputFilename();

            ifstream file(filename, ios::binary);

            if (!file.is_open()) {
                cerr << "Cannot open file" << endl;
                break;
            }

            do {
                cout << "Select file type:" << endl;
                cout << "|1|  Binary\n";
                cout << "|2|  Text\n";
                cout << "|0|  Back\n";
                cout << "Enter option number:" << endl;

                cin >> choice;
                dailyReport->clear();

                if (choice == '1') {
                    int size;
                    file.read((char *) &size, sizeof(int));
                    for (size_t i = 0; i < size; i++) {
                        auto order = new Order();
                        order->read(file);
                        dailyReport->addOrder(order);
                        delete order;
                    }
                    cout << "Success!" << endl;
                    break;
                } else if (choice == '2') {
                    dailyReport->jsonDeserialize(file);
                    cout << "Success!" << endl;
                    break;
                }
            } while (choice != '0');

            file.close();

            break;
        }
        case '5': {
            do {
                cout << "Select search type:" << endl;
                cout << "|1|  By text\n";
                cout << "|2|  By number\n";
                cout << "|0|  Back\n";
                cout << "Enter option number:" << endl;

                cin >> choice;

                cin.clear();
                cin.sync();

                if (choice == '1') {
                    cout << "Enter text to search:" << endl;
                    string str;
                    getline(cin, str);
                    cout << "Result:" << endl;
                    dailyReport->searchByText(str);
                    choice = '0';
                } else if (choice == '2') {
                    cout << "Enter number to search:" << endl;
                    int look;
                    cin >> look;
                    cout << "Result:" << endl;
                    dailyReport->searchByNum(look);
                    choice = '0';
                }
            } while (choice != '0');

            break;
        }
        case '6': {
            cout << "Products count: " << averageProductsCount<float>(dailyReport->getOrders()) << endl;
            cout << "Average total: " << averageTotal<float>(dailyReport->getOrders()) << endl;
            break;
        }
        default:
            cerr << "Invalid option number" << endl;
            break;
    }

    cout << "\n";
}

int main() {
    auto dailyReport = new DailyReport();

    dailyReport->setDate(Date(2019, 12, 22));

    char option;

    do {
        cout << "Menu:\n\n";
        cout << "|1|  Create Objects\n";
        cout << "|2|  Print data\n";
        cout << "|3|  Write to file\n";
        cout << "|4|  Read from file\n";
        cout << "|5|  Search\n";
        cout << "|6|  Show average\n";
        cout << "|0|  Exit\n";
        cout << "Enter option number:" << endl;

        cin >> option;

        try {
            handleCmd(option, dailyReport);
        } catch (ValidationException &e) {
            cerr << e.what() << endl;
            continue;
        } catch (exception &e) {
            cerr << "Unexpected error, interrupting: " << e.what() << endl;
            break;
        }
    } while (option != '0');
}

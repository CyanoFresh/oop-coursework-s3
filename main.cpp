#include <iostream>
#include "Date.h"
#include "ValidationException.h"
#include "Order.h"
#include "DailyReport.h"

using namespace std;

const int arrSize = 1;

void handleCmd(const char cmd, DailyReport *dailyReport) {
    cout << "\n";

    switch (cmd) {
        case '1':
            for (int i = 0; i < arrSize; ++i) {
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

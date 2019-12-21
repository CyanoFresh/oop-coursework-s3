#include <iostream>
#include "Date.h"

using namespace std;

void handleCmd(const char cmd) {
    cout << "\n";

    switch (cmd) {
        case '1':
            cout << "LOL" << endl;
            break;
        default:
            cerr << "Invalid option number" << endl;
            break;
    }

    cout << "\n";
}

int main() {
    char option;

    do {
        cout << "Menu:\n\n";
        cout << "|1|  Create Files\n";
        cout << "|2|  Print data\n";
        cout << "|3|  Write to file\n";
        cout << "|4|  Read from file\n";
        cout << "|5|  Search\n";
        cout << "|0|  Exit\n";
        cout << "Enter option number:" << endl;

        cin >> option;

        try {
            handleCmd(option);
        } catch (invalid_argument &e) {
            cerr << e.what() << endl;
            continue;
        } catch (exception &e) {
            cerr << "Unexpected error, interrupting: " << e.what() << endl;
            break;
        }
    } while (option != '0');
}

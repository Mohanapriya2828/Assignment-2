#include <iostream>
#include <string>
using namespace std;

void Boarding();
void Announcement();

int main() {
    cout << "Plane arrived\n";
    Boarding();
    cout << "Close gate\n";
    return 0;
}

void Boarding() {
    string priority;
    cout << "Start Priority boarding? (yes/no): ";
    cin >> priority;

    if (priority == "yes") {
        string firstClass;
        cout << "First class passenger? (yes/no): ";
        cin >> firstClass;

        if (firstClass == "yes") {
            cout << "Board plane (First class)\n";
            GateClosureCheck();
        } else {
            string halfFirst;
            cout << "Half first class boarded? (yes/no): ";
            cin >> halfFirst;

            if (halfFirst == "yes") {
                cout << "All passengers board plane\n";
                GateClosureCheck();
            } else {
                cout << "Restarting boarding process...\n";
                Boarding();
            }
        }
    } else {
        cout << "No priority boarding, waiting...\n";
        Boarding();
    }
}



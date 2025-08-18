#include <iostream>
#include <string>
using namespace std;

void Boarding();
void GateClosureCheck();
void Announcement();

int main() {
    cout << "Start\n";
    cout << "Plane arrived\n";
    Boarding();
    cout << "Close gate\n";
    cout << "End\n";
    return 0;
}

void Boarding() {
    cout << "\n--- Boarding Started ---\n";
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

void GateClosureCheck() {
    cout << "\n--- Gate Closure Check ---\n";
    cout << "5 min before gate closes\n";
    string allBoarded;
    cout << "All boarded? (yes/no): ";
    cin >> allBoarded;

    if (allBoarded == "no") {
        Announcement();
        cout << "Waiting 5 min...\n";
        GateClosureCheck();
    } else {
        cout << "All passengers on board.\n";
    }
}

void Announcement() {
    cout << "Announcement: Final boarding call for remaining passengers!\n";
}

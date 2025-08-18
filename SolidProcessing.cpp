#include <iostream>
#include <string>
using namespace std;


void getWaste();
void wasteSeparation();

int main() {
    getWaste(); 
    wasteSeparation(); 
    return 0;
}


void getWaste() {
    cout << "Waste Collected Successfully." << endl;
}


void wasteSeparation() {
    string choice;
    cout << "Is the waste Organic? (yes/no): ";
    cin >> choice;

    if (choice == "yes") {
        energy(); 
    } else {
        cout << "Is the waste Reusable? (yes/no): ";
        cin >> choice;

        if (choice == "yes") {
            cout << "Waste is Reused for other applications." << endl;
            return;
        } else {
            cout << "Is the waste Recyclable? (yes/no): ";
            cin >> choice;

            if (choice == "yes") {
                cout << "Waste is Recycled for other applications." << endl;
                return;
            } else {
                landfill();
            }
        }
    }
}


void landfill() {
    cout << "Waste sent to Landfill." << endl;
}

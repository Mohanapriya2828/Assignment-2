#include <iostream>
#include <string>
using namespace std;


void getWaste();
void wasteSeparation();
void energy();
void landfill();
string getYesNo(string question);


int main() {
    getWaste();
    wasteSeparation();
    return 0;
}


void getWaste() {
    cout << "Waste Collected Successfully." << endl;
}


string getYesNo(string question) {
    string choice;
    while (true) {
        cout << question;
        cin >> choice;
        if (choice == "yes" || choice == "no") {
            return choice;
        } else {
            cout << "Invalid input! Please enter yes or no." << endl;
        }
    }
}


void wasteSeparation() {
    string choice = getYesNo("Is the waste Organic? (yes/no): ");

    if (choice == "yes") {
        energy(); 
    } else {
        choice = getYesNo("Is the waste Reusable? (yes/no): ");
        if (choice == "yes") {
            cout << "Waste is Reused for other applications." << endl;
            return;
        } else {
            choice = getYesNo("Is the waste Recyclable? (yes/no): ");
            if (choice == "yes") {
                cout << "Waste is Recycled for other applications." << endl;
                return;
            } else {
                landfill();
            }
        }
    }
}


void energy() {
    string choice = getYesNo("Does the waste have High Energy? (yes/no): ");

    if (choice == "yes") {
        cout << "Converted to Bio-Fuel." << endl;
    } else {
        cout << "Converted to Organic Fertilizer." << endl;
    }
}


void landfill() {
    cout << "Waste sent to Landfill." << endl;
}

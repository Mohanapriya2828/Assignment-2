#include <iostream>
using namespace std;

void SelectionProcess();
void Termination();
void PowerOn();
void PowerOff();



int main() {
    PowerOn();
    SelectionProcess();
    Termination();
    cout << "End\n";
    return 0;

}

void PowerOn() {
    cout << "Machine Powered On\n";
}

void SelectionProcess() {
    int choice;
    cout << "\nCoffee Selection Menu:\n";
    cout << "1. Latte\n";
    cout << "2. Espresso\n";
    cout << "3. Mocha\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 3: 
            cout << "Adding Chocolate Powder...\n";
            cout << "Adding Steamed Milk...\n";
            

        case 1: 
            if (choice == 1) {
                cout << "Adding Steamed Milk...\n";
            }
            

        case 2:
            cout << "Adding Hot Coffee...\n";
            break;

        default:
            cout << "Invalid Selection\n";
    }
}


void Termination() {
    char press;
    cout << "\nPress P to power off machine: ";
    cin >> press;

    if (press == 'P' || press == 'p') {
        PowerOff();
    } else {
        cout << "Returning to Selection Process...\n";
        SelectionProcess();
        Termination(); 
    }
}

void PowerOff() {
    cout << "Machine Powered Off\n";
}

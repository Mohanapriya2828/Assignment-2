#include <iostream>
using namespace std;

void SelectionProcess();
void PowerOn();
void PowerOff();



int main() {
    PowerOn();
    SelectionProcess();
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




void PowerOff() {
    cout << "Machine Powered Off\n";
}

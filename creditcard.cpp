#include <iostream>
#include <string>

using namespace std;

char getYesNo(string prompt) {
    char input;
    while (true) {
        cout << prompt << " (y/n): ";
        cin >> input;
        input = tolower(input);
        if (input == 'y' || input == 'n') return input;
        cout << "Invalid input. Please enter 'y' or 'n'." << endl;
    }
}


int main() {
    processPayment(); 
    return 0;
}

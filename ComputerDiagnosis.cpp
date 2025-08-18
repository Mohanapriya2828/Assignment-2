#include <iostream>
using namespace std;

char getYesNo(const string& prompt) {
    char answer;
    while (true) {
        cout << prompt;
        cin >> answer;
        if (answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N')
            return answer;
        cout << "Invalid input. Please enter Y/y or N/n only.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}



void powerCheck() {
    char computerOn = getYesNo("Is computer ON? (Y/N): ");
    if (computerOn == 'y' || computerOn == 'Y') {
        cout << "Error handling starts.\n";
    } else {
        cout << "Checking power supply...\n";
        powerSupplyCheck();
    }
}

int main() {
    cout << "Initialization Process:\n";
    char computerOn = getYesNo("Is computer ON? (Y/N): ");
    if (computerOn == 'y' || computerOn == 'Y') {
        cout << "Computer is ON. Proceeding to error check...\n";
        diagnose(); 
    } else {
        cout << "Computer is OFF. Proceeding to power check...\n";
        powerCheck(); 
        diagnose();  
    }

    cout << "Process ended.\n";
    return 0;
}
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


void diagnose() {
    char errorMsg = getYesNo("Is there an error message? (Y/N): ");
    if (errorMsg == 'y' || errorMsg == 'Y') {
        cout << "Perform Diagnosis.\nGo to Power Check.\n";
    } else {
        cout << "Computer is in good condition. Return.\n";
    }
}


void powerSupplyCheck() {
    char powerLight = getYesNo("Is power light ON? (Y/N): ");
    if (powerLight == 'y' || powerLight == 'Y') {
        cout << "Find specialist. Return.\n";
        return;
    }
    char pluggedIn = getYesNo("Is power plugged into wall? (Y/N): ");
    if (pluggedIn == 'y' || pluggedIn == 'Y') {
        cout << "Find specialist. Return.\n";
    } else {
        cout << "Plug power into the wall. Return.\n";
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
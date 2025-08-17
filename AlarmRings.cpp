#include <iostream>
#include <string>
using namespace std;

char getYesNoInput(string prompt) {
    char choice;
    while (true) {
        cout << prompt;
        cin >> choice;
        choice = tolower(choice);

        if (choice == 'y' || choice == 'n') {
            return choice;
        } else {
            cout << "Invalid input! Please enter y/n.\n";
        }
    }
}

void alarmProcess();
void checkingTime();
void snooze();
void leavingBed();

int main() {
    
    alarmProcess();
    leavingBed();
    return 0;
}

void alarmProcess() {
    cout << "Alarm rings...\n";
    char choice=getYesNoInput("Are you ready to wake up? (y/n): ");

    if (choice == 'y') {
        cout << "You are ready to wake up!\n";
        return; 
    } else {
        checkingTime();
    }
}

void checkingTime() {
    char choice=getYesNoInput("Will you be late? (y/n): ");

    

    if (choice == 'y') {
        cout << "You will be late! Better wake up now.\n";
        return; 
    } else {
        snooze();
    }
}

void snooze() {
    cout << "Snooze activated. Wait 5 minutes...\n";
    cout << "After 5 minutes...\n";
    alarmProcess(); 
}

void leavingBed() {
    cout << "Leaving bed...\n";
    cout << "Turn off alarm.\n";
    
}

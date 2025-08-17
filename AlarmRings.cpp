#include <iostream>
#include <string>
using namespace std;

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
    char choice;
    cout << "Are you ready to wake up? (y/n): ";
    cin >> choice;

    if (tolower(choice) == 'y') {
        cout << "You are ready to wake up!\n";
        return; 
    } else {
        checkingTime();
    }
}

void checkingTime() {
    char choice;
    cout << "Will you be late if you don't wake up now? (y/n): ";
    cin >> choice;

    if (tolower(choice) == 'y') {
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

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


#include <iostream>
using namespace std;

bool checkMetal() {
    char ans;
    cout << "Does passenger have metal? (y/n): ";
    cin >> ans;
    if (tolower(ans) == 'y') {
        cout << "Handsearch required.\n";
        return true;
    }
    return false;
}

bool checkDangerous() {
    char ans;
    cout << "Does passenger have dangerous goods? (y/n): ";
    cin >> ans;
    if (tolower(ans) == 'y') {
        cout << "Give up dangerous goods.\n";
        return true;
    }
    return false;
}

bool checkRestricted() {
    char ans;
    cout << "Does passenger have restricted articles? (y/n): ";
    cin >> ans;
    if (tolower(ans) == 'y') {
        cout << "Give up articles above permitted limits.\n";
        return true;
    }
    return false;
}

void securityScreening() {
    cout << "--- Security Screening ---\n";

    if (checkMetal()) {
        if (checkDangerous()) {
            checkRestricted();
        } else {
            checkRestricted();
        }
    } 
    else if (checkDangerous()) {
        checkRestricted();
    } 
    else if (checkRestricted()) {
    }

    cout << "Security screening completed. Return.\n";
}



int main() {
    cout << "Check-in and baggage drop completed.\n";

    cout << "Initial Security Screening...\n";
    securityScreening();

    return 0;
}

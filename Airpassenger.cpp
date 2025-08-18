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

bool permitToEnter() {
    string permit;
    cout << "Permit to enter country? (yes/no): ";
    cin >> permit;
    return permit == "yes";
}

void journeyProcess() {
    cout << "Boarding flight...\nFlight departs...\nFlight lands.\n";

    string connection;
    cout << "Is there a connection? (yes/no): ";
    cin >> connection;

    if (connection == "yes") {
        cout << "Connection flight -> Security screening required.\n";
        securityScreening();
        cout << "Proceeding to next flight...\n";
        return;
    }

    cout << "Proceeding to immigration...\n";
    if (!permitToEnter()) {
        cout << "Send to originate country.\nReturn.\n";
        return;
    }

    cout << "Claim baggage.\nJourney completed.\n";
}

int main() {
    cout << "Check-in and baggage drop completed.\n";

    cout << "Initial Security Screening...\n";
    securityScreening();

    cout << "Immigration Check...\n";
    if (!permitToEnter()) {
        cout << "Not permitted -> return to originate country.\n";
        return 0;
    }

    journeyProcess();

    cout << "Process finished.\n";
    return 0;
}

#include <iostream>
using namespace std;

void bringEssentials() {
    cout << "Bring wallet, keys, phone, wet towels.\n";
}

void contactFireDept() {
    cout << "Contacting fire department...\n";
}



void pushAlarmTrigger() {
    cout << "Push the fire alarm trigger to alert others!\n";
}


void detectorProcess() {
    cout << "Smoke detector detects smoke and triggers alarm.\n";
    bringEssentials();
    checkDoor();
}

void foundByYouOrSomeone() {
    char placeFire;
    cout << "Is the place of fire IN the building? (y/n): ";
    cin >> placeFire;
    if (placeFire == 'n' || placeFire == 'N') {
        contactFireDept();
        cout << "Returning to main menu.\n";
        return;
    } else if (placeFire == 'y' || placeFire == 'Y') {
        bringEssentials();
        pushAlarmTrigger();
        checkDoor();
    } else {
        cout << "Invalid input.\n";
    }
}

int main() {
    cout << "*** FIRE EVACUATION PLAN ***\n";
    cout << "How was the fire detected?\n";
    cout << "1. You see fire/smoke\n2. Someone sees fire/smoke\n3. Smoke detector\nChoose (1/2/3): ";
    int method;
    cin >> method;
    if (method == 3) {
        detectorProcess();
    } else if (method == 1 || method == 2) {
        foundByYouOrSomeone();
    } else {
        cout << "Invalid input.\n";
    }
    return 0;
}

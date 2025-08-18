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
void stepsToFollow() {
    cout << "Do not open the door.\n";
    cout << "Seal all the cracks with wet towels.\n";
    contactFireDept();
    cout << "Wave at the windows to identify survivors.\n";
    cout << "Wait for rescue.\n";
}
void reason1Flow();

void escapeFlow() {
    cout << "Go downstairs and get out of the building.\n";
    char escaped;
    cout << "Did you successfully leave the building? (y/n): ";
    cin >> escaped;
    if (escaped == 'y' || escaped == 'Y') {
        cout << "You have safely escaped the building! Stay safe.\n";
    } else {
        reason1Flow();
    }
}

void reason1Flow() {
    cout << "Reason-1: Cannot exit down due to fire/strong smoke.\n";
    char strongSmoke;
    cout << "Do you see strong smoke or fire while escaping? (y/n): ";
    cin >> strongSmoke;
    if (strongSmoke == 'y' || strongSmoke == 'Y') {
        goUp();
    } else {
        escapeFlow();
    }
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




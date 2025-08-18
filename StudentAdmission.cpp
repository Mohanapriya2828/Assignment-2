#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool registrationFormVerification() {
    char verified;
    while (true) {
        cout << "Is your registration form verified by admission office? (y/n): ";
        cin >> verified;
        verified = tolower(verified);
        if (verified == 'y') {
            return true;
        } else if (verified == 'n') {
            cout << "Please get your registration form verified by admission office and try again.\n";
        } else {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    }
}
void tutorAssignment() {
    char hasExtraCredits;
    cout << "Assigning personal tutor...\n";
    cout << "Meeting tutor...\n";
    while (true) {
        cout << "Do you have extra credits? (y/n): ";
        cin >> hasExtraCredits;
        hasExtraCredits = tolower(hasExtraCredits);
        if (hasExtraCredits == 'y') {
            cout << "Please choose additional courses.\n";
            break;
        } else if (hasExtraCredits == 'n') {
            cout << "No additional courses chosen.\n";
            break;
        } else {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    }
}

bool visaProcess() {
    char needVisa, appliedVisa;
    while (true) {
        cout << "Do you need a visa? (y/n): ";
        cin >> needVisa;
        needVisa = tolower(needVisa);
        if (needVisa == 'y') {
            cout << "Inform student to apply for visa.\n";
            while (true) {
                cout << "Have you applied for the visa? (y/n): ";
                cin >> appliedVisa;
                appliedVisa = tolower(appliedVisa);
                if (appliedVisa == 'y') {
                    return true;
                } else if (appliedVisa == 'n') {
                    cout << "Please apply for the visa to proceed.\n";
                } else {
                    cout << "Invalid input. Please enter 'y' or 'n'.\n";
                }
            }
        } else if (needVisa == 'n') {
            return true;
        } else {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    }
}

void feePayment() {
    char feePaid;
    while (true) {
        cout << "Have you paid the tuition fees? (y/n): ";
        cin >> feePaid;
        feePaid = tolower(feePaid);
        if (feePaid == 'y') {
            return;
        } else if (feePaid == 'n') {
            cout << "Please pay the tuition fees before proceeding.\n";
        } else {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    }
}

void accommodationAssignment() {
    char needAccom;
    while (true) {
        cout << "Do you need accommodation? (y/n): ";
        cin >> needAccom;
        needAccom = tolower(needAccom);
        if (needAccom == 'y') {
            cout << "Accommodation will be assigned to you.\n";
            break;
        } else if (needAccom == 'n') {
            break;
        } else {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    }
}


int main() {
    string studentName;

    cout << "Enter your name: ";
    cin.ignore(); 
    getline(cin, studentName);

    if (!registrationFormVerification()) {
        
    }

    if (!visaProcess()) {
        
    }

    feePayment();

    accommodationAssignment();

    tutorAssignment();

    cout << "\nRegistration process completed successfully for " << studentName << "!\n";

    return 0;
}

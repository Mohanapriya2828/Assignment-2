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

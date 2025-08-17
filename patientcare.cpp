#include <iostream>
#include <string>
using namespace std;

void patientRegistration();
bool nurseAvailability();
bool doctorAvailability();
void recordHealthCondition();
void assignDoctor();
void followUp();
void medication();
void patientLeaves();

int main() {
    

    cout << "Patient Arrives...\n";

    patientRegistration();

    while (!nurseAvailability()) {
        cout << "Wait 1 minute and recheck nurse availability...\n";
    }
    recordHealthCondition();

    while (!doctorAvailability()) {
        cout << "Wait 1 minute and recheck doctor availability...\n";
    }
    assignDoctor();

    followUp();
    medication();
    patientLeaves();

    return 0;
}


void patientRegistration() {
    char choice;
    cout << "Is patient already registered? (y/n): ";
    cin >> choice;

    if (tolower(choice) == 'y') {
        cout << "Patient already registered. Skipping registration...\n";
    } else {
        cout << "Registering new patient...\n";
    }
}

bool nurseAvailability() {
    char choice;
    cout << "Is nurse available? (y/n): ";
    cin >> choice;
    return (tolower(choice) == 'y');
}

bool doctorAvailability() {
    char choice;
    cout << "Is doctor available? (y/n): ";
    cin >> choice;
    return (tolower(choice) == 'y');
}

void recordHealthCondition() {
    cout << "Recording patient health condition...\n";
}

void assignDoctor() {
    cout << "Assigning patient to doctor...\n";
}


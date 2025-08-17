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


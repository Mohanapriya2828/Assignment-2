#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

char getYesNo(const string& prompt) {
    char choice;
    while (true) {
        cout << prompt;
        cin >> choice;
        choice = tolower(choice);
        if (choice == 'y' || choice == 'n') {
            return choice;
        } else {
            cout << "Invalid input, please enter y/n.\n";
        }
    }
}

void errorReport() {
    cout << "Generating error report...\n";
    ofstream file("error.csv", ios::app);
    if (file.is_open()) {
        file << "SampleIssue,Reported\n";
        file.close();
        cout << "Error Report Stored in error.csv\n";
    }
}
void errorDB() { cout << "Logging error into database...\n"; }
void errorAnalysis() { cout << "Performing error analysis...\n"; }
void solveIssue() { cout << "Solving issue based on error analysis...\n"; }
void issueFixed() {
    cout << "Confirming with customer if issue is fixed...\n";
    ofstream file("error.csv", ios::app);
    if (file.is_open()) {
        file << "SampleIssue,Fixed\n";
        file.close();
        cout << "Fix status stored in error.csv\n";
    }
}

int main() {
    char enquiry = getYesNo("Any enquiries? (y/n): ");
    if (enquiry == 'y') 
    {
        cout << "Answer the queries\n";
        return 0;
    }

    char issue = getYesNo("Is there an issue? (y/n): ");
    if (issue == 'n') 
    {
        cout << "There is no issue\n";
        return 0;
    }

    char simulate;
    while (true) {
        simulate = getYesNo("Is simulation successful? (y/n): ");
        if (simulate == 'y') {
            errorReport();
            errorDB();
            bool fixed = false;
            while (!fixed) {
                errorAnalysis();
                solveIssue();
                char isFixed = getYesNo("Is the issue fixed? (y/n): ");
                if (isFixed == 'y') {
                    issueFixed();
                    fixed = true;
                }
            }
            break;
        } else {
            cout << "Contacting customer for more information...\n";
        }
    }
    return 0;
}

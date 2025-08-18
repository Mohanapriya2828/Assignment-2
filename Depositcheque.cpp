#include <iostream>
#include <string>

using namespace std;

void initialization() {
    cout << "Initialization [I]...\n";
}

bool isValidAccountNumber(const string& account) {
    if (account.length() != 9) return false;
    for (char c : account) {
        if (!isdigit(c)) return false;
    }
    return true;
}

string enterValidAccountNumber(const string& prompt) {
    string account;
    while (true) {
        cout << prompt;
        cin >> account;
        if (isValidAccountNumber(account)) {
            break;
        } else {
            cout << "Invalid account number. Must be exactly 9 digits. Please enter again.\n";
        }
    }
    return account;
}

bool insertBankCard() {
    cout << "Insert Bank card (press y to insert): ";
    char c;
    cin >> c;
    return (c == 'y' || c == 'Y');
}

bool insertChequeToMachine() {
    cout << "Insert cheque to machine (press y to insert): ";
    char c;
    cin >> c;
    return (c == 'y' || c == 'Y');
}



int main() {
    cout << "Start\n";
    initialization();

    if (!insertBankCard()) {
        cout << "Bank card not inserted. Return.\n";
        return 0;
    }

    string accountNumber = enterValidAccountNumber("Enter bank account number (9 digits): ");
    cout << "Entered account number: " << accountNumber << "\n";

    if (!insertChequeToMachine()) {
        cout << "Cheque not inserted. Return.\n";
        return 0;
    }


    
    return 0;
}

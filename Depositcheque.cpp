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

struct TransactionData {
    string receiverAccount;
    string senderAccount;
    double value;
};

TransactionData receiverProcess() {
    TransactionData data;
    cout << "Receiver Process [RP]\n";
    data.receiverAccount = enterValidAccountNumber("Enter receiver 9-digit account number: ");
    data.senderAccount = enterValidAccountNumber("Enter sender 9-digit account number: ");
    cout << "Enter cheque value: ";
    cin >> data.value;
    return data;
}

bool senderReview() {
    char response;
    while (true) {
        cout << "Did the sender review take 7 days? (y/n): ";
        cin >> response;
        if (response == 'y' || response == 'Y') return true;
        else if (response == 'n' || response == 'N') return false;
        else cout << "Invalid input, enter y or n.\n";
    }
}


void bankProcess(TransactionData& data) {
    cout << "Bank process [BP]\n";
    cout << "Processing cheque value: " << data.value << "\n";

    
    if (senderReview()) {
        moneyTransferredToReceiver();
        return;
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

    TransactionData data = receiverProcess();

    bankProcess(data);

    
    return 0;
}

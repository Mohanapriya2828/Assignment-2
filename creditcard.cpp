#include <iostream>
#include <string>
#include <fstream>

using namespace std;

char getYesNo(string prompt) {
    char input;
    while (true) {
        cout << prompt << " (y/n): ";
        cin >> input;
        input = tolower(input);
        if (input == 'y' || input == 'n') return input;
        cout << "Invalid input. Please enter 'y' or 'n'." << endl;
    }
}

// Function to save transaction status to CSV
void saveTransactionToCSV(const string& filename, const string& status) {
    ofstream file(filename, ios::app); // Append mode
    if (file.is_open()) {
        file << "Transaction Status: " << status << "\n";
        file.close();
        cout << "Transaction saved to " << filename << endl;
    } else {
        cout << "Failed to open " << filename << " for writing.\n";
    }
}

int main() {
    cout << "Order placed by client." << endl;

    char paymentVerified, cardValid, fundsAvailable, accountValid;

    paymentVerified = getYesNo("Is payment verified by card network?");
    
    while (paymentVerified == 'y') {
        cardValid = getYesNo("Is card valid?");
        
        if (cardValid == 'y') {
            fundsAvailable = getYesNo("Are funds available?");
            
            if (fundsAvailable == 'y') {
                accountValid = getYesNo("Is account valid?");
                
                if (accountValid == 'y') {
                    cout << "Transaction complete." << endl;
                    cout << "Card holder receives statement." << endl;
                    saveTransactionToCSV("customer.csv", "Success");
                    return 0;
                } else {
                    cout << "Account not valid, returning to payment verification." << endl;
                    paymentVerified = getYesNo("Is payment verified by card network?");
                    continue;
                }
            } else {
                cout << "Funds not available, returning to payment verification." << endl;
                paymentVerified = getYesNo("Is payment verified by card network?");
                continue;
            }
        } else {
            cout << "Card not valid, returning to payment verification." << endl;
            paymentVerified = getYesNo("Is payment verified by card network?");
            continue;
        }
    }

    cout << "Payment not verified by card network. Transaction returned." << endl;
    saveTransactionToCSV("customer.csv", "Failed");
    return 0;
}

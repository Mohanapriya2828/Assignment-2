#include <iostream>
#include <string>

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

void processPayment() {
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
                    cout << "Card holder receives statement at end of cycle." << endl;
                    return;
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
}

int main() {
    processPayment(); 
    return 0;
}

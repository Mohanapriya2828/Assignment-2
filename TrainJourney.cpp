#include <iostream>
#include <string>

using namespace std;

bool promptYesNo(const string& question) {
    char response;
    cout << question << " (y/n): ";
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void collectTicket(const string& method) {
    if (method == "machine") {
        cout << "Collect your ticket from the machine.\n";
    } else if (method == "mail") {
        cout << "Check the letter box in 3 days for your ticket.\n";
    }
}

void ticket() {
    while (true) {
        cout << "How do you want to collect your ticket?\n";
        cout << "1. From machine\n2. Mail\nChoose (1 or 2): ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            collectTicket("machine");
            break;
        } else if (choice == 2) {
            collectTicket("mail");
            break;
        } else {
            cout << "Invalid choice, please try again.\n";
        }
    }
}

void selectSeat() {
    cout << "Selecting seat for reservation...\n";
}

bool reservation() {
    while (true) {
        if (promptYesNo("Do you need a seat reservation?")) {
            selectSeat();
            ticket();
            return true; 
        } else {
            cout << "You need to decide whether you want reservation or not.\n";
        }
    }
}

void ticketCheck(bool discounted) {
    cout << "Ticket checked.\n";
    if (discounted) {
        if (promptYesNo("Show valid documentation for discounted ticket?")) {
            cout << "Documentation accepted.\n";
        } else {
            cout << "Valid documentation required. Returning to ticket check.\n";
            ticketCheck(discounted);
        }
    }
}

void destination() {
    while (true) {
        if (promptYesNo("Have you arrived at your destination?")) {
            cout << "Leaving the train. Journey complete.\n";
            break;
        } else {
            cout << "Keep going until you arrive at your destination.\n";
        }
    }
}

void boarding(bool haveReservation) {
    if (haveReservation) {
        cout << "Looking for assigned seat...\n";
    } else {
        cout << "Looking for unassigned seat...\n";
    }
    bool discounted = promptYesNo("Is your ticket discounted?");
    ticketCheck(discounted);
    destination();
}

int main() {
    cout << "Starting Train Journey Reservation System\n";
    bool hasReservation = reservation();
    boarding(hasReservation);
    cout << "Thank you for travelling with us.\n";
    return 0;
}

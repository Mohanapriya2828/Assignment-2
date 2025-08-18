#include <iostream>
#include <string>

using namespace std;


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
    return 0;
}

#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void checkTime() {
    bool pickupWithin30 = false;
    while (!pickupWithin30) {
        cout << "Checking if pickup is within 30 minutes...\n";
        char ans;
        cout << "Is pickup within 30 mins? (y/n): ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y') {
            pickupWithin30 = true;
        } else {
            cout << "Not within 30 mins. Wait 1 minute and check again...\n";
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
}

void rideHistory(const string& methodStr, const string& taxiID) {
    assignTaxi(methodStr, taxiID);
    cout << "Ride Completed and Stored in History.\n";
}
void rideFlow() {
    string bookingMethod = booking();
    checkTime();
    string taxiID = findingTaxi();
    rideHistory(bookingMethod, taxiID);
}

int main() {
    rideFlow();
    return 0;
}

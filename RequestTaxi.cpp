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

string findingTaxi() {
    cout << "Finding taxi within 10 km of pickup location...\n";
    createCSV(availableFile, "TaxiID,Pickup,Drop");

    {
        ifstream checkFile(availableFile);
        checkFile.seekg(0, ios::end);
        if (checkFile.tellg() < 30) {
            ofstream file(availableFile, ios::app);
            file << "TX001,Available,Available\n";
            file.close();
        }
    }

    bool taxiFound = false;
    string assignedTaxiID = "TX001";

    while (!taxiFound) {
        char ans;
        cout << "Taxi found? (y/n): ";
        cin >> ans;

        if (ans == 'y' || ans == 'Y') {
            taxiFound = true;
            {
                ifstream inFile(availableFile);
                ofstream outFile("temp.csv");
                string header, line;
                getline(inFile, header);
                outFile << header << "\n";
                while (getline(inFile, line)) {
                    if (line.find(assignedTaxiID) != string::npos) {
                        outFile << assignedTaxiID << ",Picked,Dropped\n";
                    } else {
                        outFile << line << "\n";
                    }
                }
            }
            this_thread::sleep_for(chrono::milliseconds(100));
            fs::remove(availableFile);
            fs::rename("temp.csv", availableFile);
        } else {
            cout << "No taxi yet. Wait 1 minute and check again...\n";
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
    return assignedTaxiID;
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

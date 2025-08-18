#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

const string incomeFile = "Income.csv";
const string availableFile = "Available.csv";
const string orderHistoryFile = "OrderHistory.csv";

void createCSV(const string& filename, const string& header) {
    if (!fs::exists(filename)) {
        ofstream file(filename);
        file << header << "\n";
        file.close();
    }
}

void writeCSV(const string& filename, const string& line) {
    ofstream file(filename, ios::app);
    file << line << "\n";
    file.close();
}

string onlineBooking() {
    cout << " Request sent to Software Server...\n";
    return "Software";
}

string phoneBooking() {
    cout << "Request sent to Call Centre Server...\n";
    return "Phone";
}

string booking() {
    char method;
    cout << "Order placed by (P)hone or (S)oftware? ";
    cin >> method;

    string methodStr;
    if (method == 'P' || method == 'p') {
        methodStr = phoneBooking();
    } else if (method == 'S' || method == 's') {
        methodStr = onlineBooking();
    } else {
        cout << "Invalid option. \n";
        exit(0);
    }

    createCSV(incomeFile, "Method,Status");
    writeCSV(incomeFile, methodStr + ",Requested");
    return methodStr;
}

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

void assignTaxi(const string& methodStr, const string& taxiID) {
    cout << "Assigning passenger to driver...\n";
    cout << "Passenger reached drop point.\n";
    createCSV(orderHistoryFile, "Method,TaxiID,Status");
    writeCSV(orderHistoryFile, methodStr + "," + taxiID + ",Passenger Dropped");
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

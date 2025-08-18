#include <iostream>
#include <string>
using namespace std;

char getYesNoInput(string prompt) {
    char choice;
    while (true) {
        cout << prompt;
        cin >> choice;
        choice = tolower(choice);
        if (choice == 'y' || choice == 'n') return choice;
        cout << "Invalid input! Please enter y or n.\n";
    }
}

void foundCrossing();
void foundTunnel();
void findingPath();

void findingPath() {
    char choice = getYesNoInput("Did you find a footbridge? (y/n): ");
    if (choice == 'y') {
        cout << "Use the footbridge.\n";
        return;
    }
    foundTunnel();
}

void foundTunnel() {
    char choice = getYesNoInput("Did you find a tunnel? (y/n): ");
    if (choice == 'y') {
        cout << "Use the tunnel.\n";
        return;
    }
    foundCrossing();
}

void foundCrossing() {
    char choice = getYesNoInput("Did you find a crossing? (y/n): ");
    if (choice == 'y') {
        trafficLight();
    } else {
        cout << "Walk away...\n";
        findingPath();
    }
}

int main() {
    findingPath();
    return 0;
}
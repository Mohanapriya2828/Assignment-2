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

void crossing();
void trafficColors();
void trafficLight();
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

void trafficLight() {
    char choice = getYesNoInput("Is there a traffic light? (y/n): ");
    if (choice == 'y') {
        trafficColors();
    } else {
        crossing();
    }
}

void trafficColors() {
    string color;
    cout << "Enter traffic light color (red/green): ";
    cin >> color;

    if (color == "red") {
        crossing();
    } else if (color == "green") {
        crossing();
    } else {
        cout << "Invalid color! Try again.\n";
        trafficColors();
    }
}

void crossing() {
    cout << "Look left.\n";
    char left = getYesNoInput("Is a car approaching from the left? (y/n): ");
    if (left == 'y') {
        crossing();
        return;
    }

    cout << "Look right.\n";
    char right = getYesNoInput("Is a car approaching from the right? (y/n): ");
    if (right == 'y') {
        crossing();
        return;
    }

    cout << "Cross the traffic safely!\n";
}


int main() {
    findingPath();
    return 0;
}
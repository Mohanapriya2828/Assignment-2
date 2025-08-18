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
void findingPath();

void findingPath() {
    char choice = getYesNoInput("Did you find a footbridge? (y/n): ");
    if (choice == 'y') {
        cout << "Use the footbridge.\n";
        return;
    }
    foundTunnel();
}

int main() {
    findingPath();
    return 0;
}
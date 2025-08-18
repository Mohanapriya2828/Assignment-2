#include <iostream>
#include <string>
using namespace std;


void updateCarLibrary() {
    cout << "Car library updated.\n";
}

void answerQueries() {
    cout << "Queries answered.\n";
}

void showDashboard() {
    cout << "Displaying dashboard...\n";
}

void logout() {
    cout << "Logout successful.\n";
}

void userIdentification() {
    cout << "User Identification\n";
}

char getYN(string prompt) {
    char choice;
    while (true) {
        cout << prompt << " (Y/N): ";
        cin >> choice;
        choice = toupper(choice);
        if (choice == 'Y' || choice == 'N') {
            return choice;
        } else {
            cout << "Invalid input. Please enter Y or N only.\n";
        }
    }
}

int main() {
   

    userIdentification();

    char isAdmin = getYN("Are you an admin?");
    if (isAdmin == 'Y') {
        showDashboard();
        char action;
        do {
            cout << "Choose function: (U)pdate Car Library, (A)nswer Queries, (L)ogout: ";
            cin >> action;
            action = toupper(action);
            if (action == 'U') {
                updateCarLibrary();
            } else if (action == 'A') {
                answerQueries();
            } else if (action == 'L') {
                logout();
            } else {
                cout << "Invalid choice. Try again.\n";
            }
        } while (action != 'L');
    } else {
        char isRegistered = getYN("Are you a registered user?");
        if (isRegistered == 'Y') {
            if (loginUser()) {
                showDashboard();
                logout();
            }
        } else {
            if (registerUser()) {
                if (loginUser()) {
                    showDashboard();
                    logout();
                }
            }
        }
    }


    return 0;
}

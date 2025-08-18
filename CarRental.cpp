#include <iostream>
#include <string>
using namespace std;
struct User {
    string username;
    string password;
    string role; 
};

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
vector<User> loadUsers(const string& filename) {
    vector<User> users;
    ifstream file(filename);
    if (!file.is_open()) return users;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string u, p, r;
        getline(ss, u, ',');
        getline(ss, p, ',');
        getline(ss, r, ',');
        if (!u.empty())
            users.push_back({u, p, r});
    }
    return users;
}

void saveUsers(const string& filename, const vector<User>& users) {
    ofstream file(filename, ios::trunc);
    for (auto& user : users) {
        file << user.username << "," << user.password << "," << user.role << "\n";
    }
}

bool userExists(const vector<User>& users, const string& username) {
    for (auto& u : users) {
        if (u.username == username) return true;
    }
    return false;
}

User* findUser(vector<User>& users, const string& username) {
    for (auto& u : users) {
        if (u.username == username) return &u;
    }
    return nullptr;
}

bool registerUser() {
    userIdentification();
    cout << "Registering new user...\n";
   
    return true; 
}


bool loginUser() {
    cout << "Login screen.\n";
    string user, pass;
    cout << "Enter username: ";
    cin >> user;
    cout << "Enter password: ";
    cin >> pass;

    
    bool correct = (pass == "password"); 

    if (!correct) {
        cout << "Incorrect password.\n";
        char reset = getYN("Forgot password?");
        if (reset == 'Y') {
            cout << "Requesting new password...\n";
            
            cout << "New password set.\n";
            return true; 
        } else {
            cout << "Returning to login.\n";
            return false;
        }
    }
    cout << "Login successful.\n";
    return true;
}


void selectVehicleAndPay() {
    cout << "Selecting vehicle...\n";
    
    char found = getYN("Did you find the desired vehicle?");
    if (found == 'Y') {
        cout << "Proceeding to payment...\n";
        
        cout << "Payment successful! Vehicle rented.\n";
    } else {
        cout << "Returning to dashboard.\n";
        showDashboard();
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
                selectVehicleAndPay();
                logout();
            }
        } else {
            if (registerUser()) {
                if (loginUser()) {
                    showDashboard();
                    selectVehicleAndPay();
                    logout();
                }
            }
        }
    }


    return 0;
}
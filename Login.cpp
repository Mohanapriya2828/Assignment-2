#include <iostream>
#include <string>
using namespace std;
 
 
bool checkAttempts(int attempts) {
    if (attempts >= 5) {
        cout << "Account locked due to 5 unsuccessful attempts.\n";
        cout << "Alert: Please contact support.\n";
        return true;
    }
    return false;
}
 
bool login() {
    const string correctUsername = "user";  // Predefined username
    const string correctPassword = "8765";   // Predefined password
 
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
 
    if (username == correctUsername && password == correctPassword) {
        cout << "Access granted.\n";
        return true;
    } else {
        cout << "Invalid credentials.\n";
        return false;
    }
} 

int main() {
    int attempts = 0;
    bool access = false;
 
    while (!access) {
        if(checkAttempts(attempts)) {
            break;
        }
 
        access = login();
 
        if (!access) {
            attempts++;
        }
    }
 
    return 0;
}
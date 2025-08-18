#include <iostream>
using namespace std;

int main() {
    cout << "Define job description\n";
    cout << "Send crew request to HR\n";

    char isRegularHiring;
    cout << " Is this a regular hiring process? (y/n): ";
    cin >> isRegularHiring;

    if (isRegularHiring == 'n' || isRegularHiring == 'N') {
        cout << "Special hiring process\n";
        cout << "Post job internally\n";
        return 0;
    }
}
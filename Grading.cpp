#include <iostream>
using namespace std;

int getScore() {
    int s;
    cout << "Enter score (0 - 100): ";
    cin >> s;


    while (s < 0 || s > 100) {
        cout << "Invalid score! Please enter again: ";
        cin >> s;
    }
    return s;
}


void checkScore(int s) {
    if (s >= 80) {
        cout << "Grade: A\n";
    } else if (s >= 60) {
        cout << "Grade: B\n";
    } else if (s >= 50) {
        cout << "Grade: C\n";
    } else {
        cout << "Grade: Fail\n";
    }
}

int main() {
    int score = getScore(); 
    checkScore(score); 
    return 0; 
}
#include <iostream>
#include <cctype>   
using namespace std;

bool CheckRaining() {
    char rain;
    cout << "\nIs it raining? (y/n): ";
    cin >> rain;
    rain = tolower(rain);

    if (rain == 'y') return true;
    if (rain == 'n') return false;

    cout << "Invalid input! Please enter y/n." << endl;
    return CheckRaining();
}

bool CheckUmbrella() {
    char umbrella;
    cout << "Do you have an umbrella? (y/n): ";
    cin >> umbrella;
    umbrella = tolower(umbrella); 

    if (umbrella == 'y') return true;
    if (umbrella == 'n') return false;

    cout << "Invalid input! Please enter y/n." << endl;
    return CheckUmbrella(); 
}

int main() {
    if (CheckRaining()) {           
        if (CheckUmbrella()) {       
            cout << "Bring Umbrella" << endl;
        } else {
            cout << "No umbrella found... checking again." << endl;
            main();                
        }
    } else {
        cout << "Don't Bring Umbrella" << endl;
    }

    return 0;
}

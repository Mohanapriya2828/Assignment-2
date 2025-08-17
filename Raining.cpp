#include <iostream>
#include <cctype>   
using namespace std;


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

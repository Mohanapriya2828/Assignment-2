#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Item {
    string name;
    bool inWarehouse;
    bool requiresSeller; 
};


bool orderProcessing(vector<Item>& items) {
    for (size_t i = 0; i < items.size(); ++i) {
        cout << "Processing '" << items[i].name << "'...\n";
        if (items[i].inWarehouse) {
            cout << "'" << items[i].name << "' is packed with other orders in warehouse.\n";
        } else {
            bool res = contactSeller(items[i].name);
            if (!res) {
                cout << "Cannot proceed without seller shipping the item. Returning to order processing.\n";
                return false; // Item cannot be fulfilled
            }
        }
    }
    return true; 
}



int main() {
    cout << "Order placed.\n";

    
    vector<Item> order = {
        {"Laptop", true},
        {"Phone", false}
    };

    cout << "Order processing...\n";
    bool allProcessed = orderProcessing(order);

    
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Item {
    string name;
    bool inWarehouse;
    bool requiresSeller; 
};


bool contactSeller(const string& itemName) {
    cout << "Contact seller to ship '" << itemName << "' (y/n): ";
    char response;
    cin >> response;
    if (response == 'y' || response == 'Y') {
        cout << "Seller ships the goods for '" << itemName << "'.\n";
        return true;
    } else {
        cout << "Invalid! Seller did not ship the goods for '" << itemName << "'.\n";
        return false;
    }
}


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


void delivery() {
    cout << "Send warehouse goods to customer...\n";
    cout << "Did customer collect goods? (y/n): ";
    char collected;
    cin >> collected;

    if (collected == 'y' || collected == 'Y') {
        cout << "Seller confirms customer received the order.\n";
    } else {
        cout << "Customer did not collect the goods. Ending process.\n";
    }
}

int main() {
    cout << "Order placed.\n";

    
    vector<Item> order = {
        {"Laptop", true},
        {"Phone", false}
    };

    cout << "Order processing...\n";
    bool allProcessed = orderProcessing(order);

    if (allProcessed) {
        cout << "Proceeding to delivery...\n";
        delivery();
    } else {
        cout << "Order processing incomplete. Exiting.\n";
    }

    return 0;
}

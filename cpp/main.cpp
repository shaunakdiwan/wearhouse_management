#include <iostream>
#include <string>

#include "linkedlist.h"
#include "queue.h"
#include "stack.h"

using namespace std;

// Display the menu options
void displayMenu() {
    cout << "\n=== Warehouse Management System ===\n";
    cout << "1. Add Part to Inventory\n";
    cout << "2. Delete Part from Inventory\n";
    cout << "3. Search Part in Inventory\n";
    cout << "4. Display Inventory\n";
    cout << "5. Place Order\n";
    cout << "6. Process Next Order (Not integrated yet)\n";
    cout << "7. Undo Last Order (Not integrated yet)\n";
    cout << "8. Display Order Queue\n";
    cout << "9. Display Order History\n";
    cout << "10. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, qty;
                float price;
                string name;
                cout << "Enter Part ID: ";
                cin >> id;
                cout << "Enter Part Name: ";
                cin.ignore(); // clear newline
                getline(cin, name);
                cout << "Enter Quantity: ";
                cin >> qty;
                cout << "Enter Price: ";
                cin >> price;
                insertPart(id, name, qty, price);
                cout << "Part added successfully.\n";
                break;
            }
            case 2: {
                int id;
                cout << "Enter Part ID to delete: ";
                cin >> id;
                deletePart(id);
                break;
            }
            case 3: {
                int id;
                cout << "Enter Part ID to search: ";
                cin >> id;
                Node* found = searchPart(id);
                if (found != nullptr) {
                    cout << "Found - ID: " << found->id << " | Name: " << found->name 
                         << " | Qty: " << found->quantity << " | Price: $" << found->price << "\n";
                } else {
                    cout << "Part not found.\n";
                }
                break;
            }
            case 4:
                displayAll();
                break;
            case 5: {
                Order newOrder;
                cout << "Enter Order ID: ";
                cin >> newOrder.orderId;
                cout << "Enter Part ID: ";
                cin >> newOrder.partId;
                cout << "Enter Quantity Requested: ";
                cin >> newOrder.qtyRequested;
                enqueueOrder(newOrder);
                break;
            }
            case 6: {
                // Test dequeue alone for Part 1
                Order o = dequeueOrder();
                if (o.orderId != -1) {
                    cout << "Dequeued Order ID: " << o.orderId << "\n";
                    // Manually test pushing to stack for Part 1 basic testing
                    Action a = {o.orderId, o.partId, o.qtyRequested};
                    pushAction(a);
                    cout << "Pushed to history stack.\n";
                }
                break;
            }
            case 7: {
                // Test pop alone for Part 1
                Action a = popAction();
                if (a.orderId != -1) {
                    cout << "Popped Order ID: " << a.orderId << " from history.\n";
                }
                break;
            }
            case 8:
                displayQueue();
                break;
            case 9:
                displayStack();
                break;
            case 10:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 10);

    return 0;
}

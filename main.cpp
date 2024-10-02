#include <iostream>
#include "Restaurant.h"

int main() {
    Restaurant myRestaurant;

    // Main loop for user interaction
    int choice;
    do {
        std::cout << "1. Place Customer Order\n";
        std::cout << "2. Manage Staff\n";
        std::cout << "3. Check Inventory\n";
        std::cout << "4. View Daily Performance\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Place customer order logic
                myRestaurant.placeOrder();
                break;
            case 2:
                // Staff management logic
                myRestaurant.manageStaff();
                break;
            case 3:
                // Inventory check logic
                myRestaurant.checkInventory();
                break;
            case 4:
                // View daily performance logic
                myRestaurant.viewPerformance();
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid option. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

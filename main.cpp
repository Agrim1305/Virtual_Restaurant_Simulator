#include "Restaurant.h"
#include "Customer.h"
#include "Menu.h"
#include <iostream>
#include <limits>

// Function to display the main menu
void display_menu() {
    std::cout << "==== Virtual Restaurant Simulator ====\n";
    std::cout << "1. Add Customer and Seat Them\n";
    std::cout << "2. Place Customer Order\n";
    std::cout << "3. Serve Customer Order\n";
    std::cout << "4. Restock Inventory\n";
    std::cout << "5. View Inventory\n";
    std::cout << "6. Track Performance\n";
    std::cout << "0. Exit\n";
    std::cout << "Select an option: ";
}

int main() {
    Restaurant myRestaurant;

    // Add items to the menu
    myRestaurant.get_menu().add_item(MenuItem("Pasta", 12.99, 15));
    myRestaurant.get_menu().add_item(MenuItem("Burger", 8.99, 10));
    myRestaurant.get_menu().add_item(MenuItem("Salad", 6.99, 5));

    // Add employees to the restaurant
    Chef chef1("Gordon Ramsay", 101);
    Waiter waiter1("John Smith", 201);
    Manager manager1("Lisa Johnson", 301);

    myRestaurant.add_chef(chef1);
    myRestaurant.add_waiter(waiter1);
    myRestaurant.set_manager(&manager1);

    // Create a test customer
    Customer customer("John Doe", 1);

    // Menu options interaction loop
    int option;
    do {
        display_menu();
        std::cin >> option;

        switch (option) {
            case 1:  // Add customer and seat them
                std::cout << "Seating customer...\n";
                myRestaurant.seat_customer(customer);
                break;

            case 2:  // Place customer order
                std::cout << "Processing customer order...\n";
                myRestaurant.process_order(customer);
                
                // Show the total bill after the order is finalized
                std::cout << "Total bill: $" << customer.pay_bill() << std::endl;
                break;

            case 3:  // Serve customer order
                std::cout << "Serving customer order...\n";
                myRestaurant.serve_order(customer);
                break;

            case 4:  // Restock inventory
            {
                std::string ingredient;
                int quantity;
                std::cout << "Enter ingredient to restock: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, ingredient);
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                myRestaurant.get_inventory().restock(ingredient, quantity);
                break;
            }

            case 5:  // View inventory
                std::cout << "\nCurrent Inventory:\n";
                myRestaurant.get_inventory().display_inventory();
                break;

            case 6:  // Track performance
                std::cout << "Tracking performance...\n";
                myRestaurant.track_performance();
                break;

            case 0:  // Exit
                std::cout << "Exiting program...\n";
                break;

            default:  // Invalid option
                std::cout << "Invalid option. Please try again.\n";
                break;
        }

    } while (option != 0);

    return 0;
}

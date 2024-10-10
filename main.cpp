#include "Restaurant.h"
#include "Customer.h"
#include "Menu.h"
#include "Chef.h"
#include "Waiter.h"
#include "Manager.h"
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
    myRestaurant.get_menu().add_item(MenuItem("Pasta", 12.99, 15, "Pasta", 1));
    myRestaurant.get_menu().add_item(MenuItem("Burger", 8.99, 10, "Beef Patty", 1));
    myRestaurant.get_menu().add_item(MenuItem("Salad", 6.99, 5, "Salad Greens", 1));

    // Create employees and add them to the restaurant
    Chef* chef = new Chef("Gordon Ramsay", 101);
    Waiter* waiter = new Waiter("John Smith", 201);
    Manager* manager = new Manager("Lisa Johnson", 301);

    myRestaurant.add_employee(chef);
    myRestaurant.add_employee(waiter);
    myRestaurant.add_employee(manager);

    // Create a test customer
    Customer customer("John Doe", 1);

    int option;
    do {
        display_menu();
        std::cin >> option;

        switch (option) {
            case 1:  // Seat customer
                std::cout << "Seating customer...\n";
                myRestaurant.seat_customer(customer);
                break;

            case 2:  // Place customer order
                std::cout << "Processing customer order...\n";
                myRestaurant.process_order(customer);
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

            default:
                std::cout << "Invalid option. Please try again.\n";
                break;
        }

        // Display the customer information (using operator overloading)
        std::cout << customer;

    } while (option != 0);

    // Clean up dynamically allocated employees
    delete chef;
    delete waiter;
    delete manager;

    return 0;
}

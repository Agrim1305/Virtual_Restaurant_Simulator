#include "Restaurant.h"
#include "Customer.h"  // Include Customer class
#include <iostream>

// Default constructor to initialize the restaurant
Restaurant::Restaurant() {
    // Any initialization of member variables, if needed, can be done here.
}

// Get a reference to the restaurant's menu
Menu& Restaurant::get_menu() {
    return menu;
}

// Get a reference to the restaurant's inventory
Inventory& Restaurant::get_inventory() {
    return inventory;
}

// Add an employee to the restaurant (Chef, Waiter, Manager)
void Restaurant::add_employee(Employee* employee) {
    employees.push_back(employee);
}

// Process the customer's order
void Restaurant::process_order(Customer& customer) {
    customer.place_order(menu);  // Allow the customer to place their order

    // For each item in the customer's order, use ingredients from the inventory
    for (const auto& item : customer.get_order().get_items()) {
        if (inventory.check_stock(item)) {
            inventory.use_ingredient(item);  // Use ingredients from the inventory
        } else {
            std::cout << "Not enough ingredients to prepare " << item.get_name() << "!\n";
        }
    }

    std::cout << "Order has been processed.\n";
}

// Seat the customer in the restaurant
void Restaurant::seat_customer(Customer& customer) {
    std::cout << "Customer has been seated.\n";
}

// Serve the customer's order and prompt to complete the order
void Restaurant::serve_order(Customer& customer) {
    std::cout << "Serving the customer order...\n";
    std::cout << customer.get_order();  // Display the current order

    // Ask the user if they want to mark the order as completed
    char choice;
    std::cout << "Do you want to complete the order? (y/n): ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        // If yes, reset the order for a new one
        customer.complete_order();  // Complete and reset the order
        std::cout << "Order completed. Ready for a new order.\n";
    } else {
        std::cout << "Order not completed. You can still modify it.\n";
    }
}

// Track the performance of employees in the restaurant
void Restaurant::track_performance() {
    std::cout << "Tracking employee performance...\n";
    for (const auto& employee : employees) {
        employee->perform_task();  // Perform task based on the type of employee (Chef, Waiter, Manager)
    }
}

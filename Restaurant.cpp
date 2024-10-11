#include "Restaurant.h"
#include <iostream>

// Constructor for the Restaurant class
Restaurant::Restaurant() {}

Menu& Restaurant::get_menu() {
    return menu;
}

 // Method to return a reference to the restaurant's inventory
Inventory& Restaurant::get_inventory() {
    return inventory;
}

// Adds a new employee to the restaurant's list of employees
void Restaurant::add_employee(Employee* employee) {
    employees.push_back(employee);
}

// Processes the customer's order based upon the menu and inventory
// For each item in the order, checks if there are enough ingredients in stock
// If ingredients are available, it uses the required amount from the inventory
void Restaurant::process_order(Customer& customer) {
    customer.place_order(menu);
    for (const auto& item : customer.get_order().get_items()) {
        if (inventory.check_stock(item.get_ingredient())) {
            inventory.use_ingredient(item.get_ingredient(), 1); // Use 1 unit of the ingredient
        } else {
            std::cout << "Not enough ingredients to prepare " << item.get_name() << "!\n";
        }
    }
    std::cout << "Order has been processed.\n";
}

// Seats a customer in the restaurant
void Restaurant::seat_customer(Customer& customer) {
    std::cout << "Customer has been seated.\n";
}

// Serves a customer's order and saves the order details to a file
void Restaurant::serve_order(Customer& customer, const std::string& filename) {
    std::cout << "Serving customer order...\n";
    customer.complete_order();
    customer.save_order_to_file(filename);

    std::cout << "Customer " << customer.get_name() << "'s order has been served.\n";
    std::cout << "Table " << customer.get_table_number() << " is now available.\n";
}

// Tracks the performance of all employees
void Restaurant::track_performance() {
    std::cout << "Tracking performance of employees...\n";
    for (const auto& employee : employees) {
        employee->perform_task();
    }
}

// Displays the Current Menu 
void Restaurant::view_menu() {
    std::cout << "Current Menu:\n";
    const auto& items = menu.get_items();
    for (const auto& item : items) {
        std::cout << item.get_name() << " - $" << item.get_price() 
                  << " (Prep time: " << item.get_prep_time() << " mins)\n";
    }
}

// Implementation of add_menu_item method
void Restaurant::add_menu_item(const MenuItem& item) {
    menu.add_item(item);
    
    // Automatically restock the associated ingredient when a menu item is added
    if (!inventory.check_stock(item.get_ingredient())) {
        inventory.restock(item.get_ingredient(), 10);  // Add 10 units of the ingredient
    }
}

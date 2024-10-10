#include "Restaurant.h"
#include <iostream>

Restaurant::Restaurant() {}

Menu& Restaurant::get_menu() {
    return menu;
}

Inventory& Restaurant::get_inventory() {
    return inventory;
}

void Restaurant::add_employee(Employee* employee) {
    employees.push_back(employee);
}

void Restaurant::process_order(Customer& customer) {
    customer.place_order(menu);
    for (const auto& item : customer.get_order().get_items()) {
        if (inventory.check_stock(item.get_ingredient())) {
            inventory.use_ingredient(item.get_ingredient(), 1);
        } else {
            std::cout << "Not enough ingredients to prepare " << item.get_name() << "!\n";
        }
    }
    std::cout << "Order has been processed.\n";
}

void Restaurant::seat_customer(Customer& customer) {
    std::cout << "Customer has been seated.\n";
}

void Restaurant::serve_order(Customer& customer) {
    std::cout << "Serving customer order...\n";
    customer.complete_order();
    std::cout << "Customer " << customer.get_name() << "'s order has been served.\n";
    std::cout << "Table " << customer.get_table_number() << " is now available.\n";
}

void Restaurant::track_performance() {
    std::cout << "Tracking performance of employees...\n";
    for (const auto& employee : employees) {
        employee->perform_task();
    }
}

void Restaurant::view_menu() {
    std::cout << "Current Menu:\n";
    const auto& items = menu.get_items();
    for (const auto& item : items) {
        std::cout << item.get_name() << " - $" << item.get_price() 
                  << " (Prep time: " << item.get_prep_time() << " mins)\n";
    }
}

// New function to add menu items and automatically add related ingredients to inventory
void Restaurant::add_menu_item(const MenuItem& item) {
    menu.add_item(item);
    
    // Automatically add the associated ingredient to the inventory with an initial stock
    if (!inventory.check_stock(item.get_ingredient())) {
        inventory.restock(item.get_ingredient(), 10);  // Add 10 units of each new ingredient
    }
}

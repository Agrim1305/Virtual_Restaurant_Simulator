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

    // For each item in the customer's order, use the ingredients
    for (const auto& item : customer.get_order().get_items()) {
        if (inventory.check_stock(item)) {
            inventory.use_ingredient(item);  // Reduce the ingredient from the inventory
        } else {
            std::cout << "Not enough ingredients to prepare " << item.get_name() << "!" << std::endl;
        }
    }

    std::cout << "Order has been processed." << std::endl;
}

void Restaurant::seat_customer(Customer& customer) {
    std::cout << "Customer has been seated.\n";
}

void Restaurant::serve_order(Customer& customer) {
    std::cout << "Serving the customer order...\n";
}

void Restaurant::track_performance() {
    std::cout << "Tracking employee performance...\n";
    for (const auto& employee : employees) {
        employee->perform_task();  // Call the overridden task using polymorphism
    }
}

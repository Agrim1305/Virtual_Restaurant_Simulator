#include "Restaurant.h"
#include <iostream>

Restaurant::Restaurant() {
    // Initialize with some tables
    for (int i = 1; i <= 10; ++i) {
        tables.push_back(Table(i));
    }
}

Menu& Restaurant::get_menu() {
    return menu;
}

Inventory& Restaurant::get_inventory() {
    return inventory;
}

void Restaurant::add_chef(const Chef& chef) {
    chefs.push_back(chef);
}

void Restaurant::add_waiter(const Waiter& waiter) {
    waiters.push_back(waiter);
}

void Restaurant::set_manager(Manager* manager) {
    this->manager = manager;
}

void Restaurant::process_order(Customer& customer) {
    customer.place_order(menu);

    // Assign a chef to prepare the order
    if (!chefs.empty()) {
        chefs[0].prepare_order();  // First chef in the vector prepares the order
    } else {
        std::cout << "No chefs available to prepare the order!" << std::endl;
    }
}

void Restaurant::serve_order(Customer& customer) {
    if (!waiters.empty()) {
        waiters[0].serve_order();  // First waiter serves the order
    } else {
        std::cout << "No waiters available to serve the order!" << std::endl;
    }
}

void Restaurant::seat_customer(Customer& customer) {
    for (auto& table : tables) {
        if (!table.get_occupied_status()) {
            table.occupy(customer);
            std::cout << "Customer has been seated at table " << table.get_number() << std::endl;
            return;
        }
    }
    std::cout << "No tables available." << std::endl;
}

void Restaurant::track_performance() {
    if (manager != nullptr) {
        manager->perform_task();  // Manager oversees performance
    }
}

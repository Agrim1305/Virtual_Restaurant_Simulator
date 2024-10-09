#include "Restaurant.h"
#include <iostream>

Menu& Restaurant::get_menu() {
    return menu;
}

void Restaurant::process_order(Customer& customer) {
    customer.place_order(menu);
    std::cout << "Order has been placed by customer." << std::endl;
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
    std::cout << "Tracking restaurant performance..." << std::endl;
    // Implement performance tracking here.
}

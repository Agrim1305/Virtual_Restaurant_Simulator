#include "Order.h"
#include <iostream>

void Order::add_items_from_menu(const Menu& menu) {
    int choice;
    do {
        menu.display_menu();
        std::cout << "Select items to order (enter 0 to finish): ";
        std::cin >> choice;

        // Validate the choice and add item to the order
        if (choice > 0 && static_cast<size_t>(choice) <= menu.get_items().size()) {
            items.push_back(menu.get_items()[choice - 1]);
            std::cout << "Item added to order.\n";
        } else if (choice != 0) {
            std::cout << "Invalid selection. Please try again.\n";
        }
    } while (choice != 0);

    // Display the total after order is complete
    float total = calculate_total();
    std::cout << "Order complete. Total Bill: $" << total << "\n";
}

const std::vector<MenuItem>& Order::get_items() const {
    return items;
}

// Calculate the total price of the order
float Order::calculate_total() const {
    float total = 0;
    for (const auto& item : items) {
        total += item.get_price();
    }
    return total;
}

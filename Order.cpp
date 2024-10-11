#include "Order.h"
#include "Menu.h"
#include <iostream>

// Adds items to the order from the provided menu
void Order::add_items_from_menu(const Menu& menu) {
    int choice;
    do {
        menu.display_menu();
        std::cout << "Select items to order (enter 0 to finish): ";
        std::cin >> choice;

        // Fix the signed/unsigned comparison
        if (choice > 0 && static_cast<size_t>(choice) <= menu.get_items().size()) {
            items.push_back(menu.get_items()[choice - 1]);
            std::cout << "Item added to order.\n";
        } else if (choice != 0) {
            std::cout << "Invalid selection. Please try again.\n";
        }
    } while (choice != 0);
}

const std::vector<MenuItem>& Order::get_items() const {
    return items;
}

// Calculates the total cost of all items in the order
float Order::calculate_total() const {
    float total = 0;
    for (const auto& item : items) {
        total += item.get_price(); // Adds the price of each item in the total
    }
    return total;
}

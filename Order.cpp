#include "Order.h"
#include <iostream>

void Order::add_item(const MenuItem& item) {
    items.push_back(item);
}

float Order::calculate_total() const {  // Ensure this method is const
    float total_cost = 0;
    for (const auto& item : items) {
        total_cost += item.get_price();
    }
    return total_cost;
}

void Order::display_order() const {
    for (const auto& item : items) {
        std::cout << item.get_name() << " - $" << item.get_price() << std::endl;
    }
    std::cout << "Total cost: $" << calculate_total() << std::endl;
}

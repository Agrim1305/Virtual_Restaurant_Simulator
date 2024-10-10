#include "Order.h"
#include <iostream>

void Order::add_item(const MenuItem& item) {
    items.push_back(item);
}

float Order::calculate_total() const {
    float total = 0;
    for (const auto& item : items) {
        total += item.get_price();
    }
    return total;
}

const std::vector<MenuItem>& Order::get_items() const {
    return items;
}

std::ostream& operator<<(std::ostream& os, const Order& order) {
    for (const auto& item : order.items) {
        os << "- " << item.get_name() << " : $" << item.get_price() << "\n";
    }
    os << "Total: $" << order.calculate_total() << "\n";
    return os;
}

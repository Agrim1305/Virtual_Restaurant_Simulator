#include "Order.h"
#include <iostream>

void Order::add_item(const MenuItem& item) {
    items.push_back(item);
}

void Order::display_order() const {
    for (const auto& item : items) {
        std::cout << item.get_name() << " - $" << item.get_price() << '\n';
    }
}

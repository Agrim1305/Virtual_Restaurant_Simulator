#include "Order.h"

void Order::addItem(const MenuItem& item) {
    items.push_back(item);
}

float Order::calculateTotal() const {
    float total = 0;
    for (const auto& item : items) {
        total += item.getPrice();
    }
    return total;
}

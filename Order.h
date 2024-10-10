#ifndef ORDER_H
#define ORDER_H

#include "MenuItem.h"
#include <vector>
#include <iostream>

class Order {
    std::vector<MenuItem> items;

public:
    void add_item(const MenuItem& item);
    float calculate_total() const;
    const std::vector<MenuItem>& get_items() const;

    // Overloading << operator
    friend std::ostream& operator<<(std::ostream& os, const Order& order);
};

#endif

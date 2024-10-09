#ifndef ORDER_H
#define ORDER_H

#include "MenuItem.h"
#include <vector>

class Order {
    std::vector<MenuItem> items;
    float total_cost;

public:
    void add_item(const MenuItem& item);
    float calculate_total() const;  // Mark this method as const
    void display_order() const;
};

#endif

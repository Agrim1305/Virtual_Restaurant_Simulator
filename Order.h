#ifndef ORDER_H
#define ORDER_H

#include "MenuItem.h"
#include <vector>

class Order {
    std::vector<MenuItem> items;
    float total_cost;

public:
    void add_item(const MenuItem& item);
    float calculate_total() const;
    void display_order() const;
    
    // Add get_items method to return the list of items
    std::vector<MenuItem> get_items() const;
};

#endif

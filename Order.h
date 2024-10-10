#ifndef ORDER_H
#define ORDER_H

#include "Menu.h"  // Include Menu here to use the Menu type
#include "MenuItem.h"
#include <vector>

class Order {
private:
    std::vector<MenuItem> items;  // Stores items in the order

public:
    void add_items_from_menu(const Menu& menu);  // Adds items from the menu
    const std::vector<MenuItem>& get_items() const;
    float calculate_total() const;
};

#endif

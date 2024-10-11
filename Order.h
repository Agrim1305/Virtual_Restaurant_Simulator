#ifndef ORDER_H
#define ORDER_H

#include "Menu.h"  // Include Menu here to use the Menu type
#include "MenuItem.h"
#include <vector>
#include <fstream>  // For file I/O operations

class Order {
private:
    std::vector<MenuItem> items;  // Stores items in the order

public:
    void add_items_from_menu(const Menu& menu);  // Adds items from the menu
    const std::vector<MenuItem>& get_items() const;
    float calculate_total() const;

    // Declaration of the save_to_file method
    void save_to_file(std::ofstream& file) const;  // Note the const qualifier
};

#endif

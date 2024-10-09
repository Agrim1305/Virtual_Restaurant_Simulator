#ifndef MENU_H
#define MENU_H

#include "MenuItem.h"
#include <vector>

class Menu {
    std::vector<MenuItem> items;

public:
    void add_item(const MenuItem& item);
    void remove_item(const std::string& item_name);
    void display_menu() const;
    MenuItem get_item(int index) const;  // Add this method to get a menu item by index
};

#endif

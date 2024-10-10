#ifndef MENU_H
#define MENU_H

#include "MenuItem.h"
#include <vector>

class Menu {
    std::vector<MenuItem> items;

public:
    void add_item(const MenuItem& item);  // Declaration
    void display_menu() const;
    MenuItem get_item(int index) const;
    int get_items_size() const;
};

#endif

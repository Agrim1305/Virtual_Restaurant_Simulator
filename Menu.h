#ifndef MENU_H
#define MENU_H

#include "MenuItem.h"
#include <vector>
#include <iostream>

class Menu {
private:
    std::vector<MenuItem> items;

public:
    void add_item(const MenuItem& item);
    void display_menu() const;
    MenuItem get_item(int index) const;
    int get_items_size() const;
};

#endif

#ifndef MENU_H
#define MENU_H

#include <vector>
#include "MenuItem.h"

class Menu {
private:
    std::vector<MenuItem> items;

public:
    void add_item(const MenuItem& item);
    void display_menu() const;
};

#endif

#ifndef MENU_H
#define MENU_H

#include "MenuItem.h"
#include <vector>

class Menu {
private:
    std::vector<MenuItem> items;

public:
    void add_item(const MenuItem& item);
    const std::vector<MenuItem>& get_items() const;
};

#endif

#ifndef MENU_H
#define MENU_H

#include <vector>
#include "MenuItem.h"

class Menu {
private:
    std::vector<MenuItem> items;
public:
    void addItem(const MenuItem& item);
    void displayMenu() const;
};

#endif

#ifndef INVENTORY_H
#define INVENTORY_H

#include "MenuItem.h"
#include <vector>
#include <string>

class Inventory {
    std::vector<std::pair<std::string, int>> ingredients;

public:
    bool check_stock(const MenuItem& item);
    void restock(const std::string& ingredient, int amount);
    void notify_low_stock();
};

#endif

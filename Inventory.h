#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include "MenuItem.h"

class Inventory {
    std::vector<std::pair<std::string, int>> ingredients;  // Ingredients with their quantities

public:
    Inventory();

    void add_ingredient(const std::string& ingredient, int quantity);
    bool check_stock(const MenuItem& item);  // Check if there are enough ingredients
    void use_ingredient(const MenuItem& item);  // Use ingredients when an item is ordered
    void restock(const std::string& ingredient, int amount);
    void display_inventory() const;
    void notify_low_stock();  // Notify when ingredients are low (less than 5 units)
};

#endif

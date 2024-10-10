#ifndef INVENTORY_H
#define INVENTORY_H

#include "Ingredient.h"
#include <map>
#include <string>
#include <iostream>

class Inventory {
private:
    std::map<std::string, Ingredient> stock;

public:
    void restock(const std::string& ingredient, int quantity);
    bool check_stock(const std::string& ingredient) const;
    void use_ingredient(const std::string& ingredient, int amount);
    void display_inventory() const;  // Function to display the inventory
};

#endif

#ifndef INVENTORY_H
#define INVENTORY_H

#include "Ingredient.h"
#include <map>
#include <string>
#include <iostream>
#include <fstream>  // For file I/O

class Inventory {
private:
    std::map<std::string, Ingredient> stock;

public:
    void restock(const std::string& ingredient, int quantity);
    bool check_stock(const std::string& ingredient) const;
    void use_ingredient(const std::string& ingredient, int amount);
    void display_inventory() const;
    
    // New file I/O methods
    void save_to_file(const std::string& filename) const;   // Save inventory to a file
    void load_from_file(const std::string& filename);       // Load inventory from a file
};

#endif

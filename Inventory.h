#ifndef INVENTORY_H
#define INVENTORY_H

#include "Ingredient.h"
#include <map>
#include <string>
#include <iostream>
#include <fstream>  // For file I/O

// Declaration of the Inventory class to manage the stock of ingredients
class Inventory {
private:
    // Map to store ingredients with their names as keys and Ingredient objects as values
    std::map<std::string, Ingredient> stock;

public:
    // Method to restock a specified quantity of an ingredient
    void restock(const std::string& ingredient, int quantity);

     // Method to check if a specified ingredient is in stock and available
    bool check_stock(const std::string& ingredient) const;

    // Method to use a specified amount of an ingredient from the stock
    void use_ingredient(const std::string& ingredient, int amount);

    // Method to display the current inventory and the quantity of each ingredient
    void display_inventory() const;
    
    // New file I/O methods
    void save_to_file(const std::string& filename) const;   // Save inventory to a file
    void load_from_file(const std::string& filename);       // Load inventory from a file
};

#endif

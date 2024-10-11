#ifndef INVENTORY_H
#define INVENTORY_H

#include "Ingredient.h"
#include <map>
#include <string>

class Inventory {
private:
    std::map<std::string, Ingredient> stock;  // Map to store ingredient names and their quantities

public:
    // Restock the inventory with a specified quantity of an ingredient
    void restock(const std::string& ingredient_name, int quantity, bool silent = false);

    // Check if an ingredient is in stock
    bool check_stock(const std::string& ingredient_name) const;

    // Use a specified amount of an ingredient
    void use_ingredient(const std::string& ingredient_name, int amount);

    // Display current inventory and the quantity of each ingredient
    void display_inventory() const;

    // Save inventory to a file
    void save_to_file(const std::string& filename) const;

    // Load inventory from a file
    void load_from_file(const std::string& filename);

    // Check if an ingredient exists in the inventory
    bool ingredient_exists(const std::string& ingredient_name) const;

    // Add this method to return the stock map
    const std::map<std::string, Ingredient>& get_stock() const {
        return stock;
    }
};

#endif

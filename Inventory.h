#ifndef INVENTORY_H
#define INVENTORY_H
#include "Ingredient.h"
#include "MenuItem.h"
#include <vector>
#include <string>

class Inventory {
    std::vector<Ingredient> ingredients;  // Use vector of Ingredient objects

public:
    Inventory();

    // Adds a new ingredient with its initial quantity
    void add_ingredient(const std::string& ingredient, int quantity);

    // Checks if there are enough ingredients to prepare a menu item
    bool check_stock(const MenuItem& item);

    // Decreases the ingredient stock based on the menu item's preparation needs
    void use_ingredients(const MenuItem& item);

    // Restocks a specified ingredient
    void restock(const std::string& ingredient, int amount);

    // Checks for ingredients running low (threshold)
    void notify_low_stock(int threshold = 5);

    // Displays the current inventory status
    void display_inventory() const;

private:
    Ingredient* find_ingredient(const std::string& name);  // Helper to find an ingredient by name
};

#endif

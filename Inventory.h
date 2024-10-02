#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
struct Ingredient {
    std::string name;
    int quantity;

    Ingredient(const std::string& n, int q) : name(n), quantity(q) {}
};

class Inventory {
private:
    std::vector<Ingredient> ingredients;

public:
    // Constructor
    Inventory();

    // Function to add initial stock
    void addIngredient(const std::string& ingredient, int quantity);

    // Function to check if enough stock is available for a menu item
    bool checkStock(const std::string& ingredient, int quantity) const;

    // Function to restock ingredients
    void restock(const std::string& ingredient, int quantity);

    // Function to notify low stock levels
    void notifyLowStock() const;

    // Function to display current inventory
    void displayInventory() const;
};

#endif

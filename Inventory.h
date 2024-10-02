#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include <utility>  // For std::pair

class Inventory {
private:
    // Vector of ingredients (string) and their quantities (int)
    std::vector<std::pair<std::string, int>> ingredients;

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

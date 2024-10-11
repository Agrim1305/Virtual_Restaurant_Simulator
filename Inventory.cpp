#include "Inventory.h"
#include <iostream>
#include <fstream>

// Restock the inventory with a specified quantity of an ingredient
// If the ingredient is already in stock, update its quantity; otherwise, add a new ingredient
void Inventory::restock(const std::string& ingredient_name, int quantity, bool silent) {
    if (stock.find(ingredient_name) != stock.end()) {
        stock[ingredient_name].restock(quantity);
    } else {
        stock[ingredient_name] = Ingredient(ingredient_name, quantity);
    }

    // Only print the restock message if silent mode is off
    if (!silent) {
        std::cout << "Restocked " << ingredient_name << " with " << quantity << " units.\n";
    }
}

// Check if an ingredient is in stock and if its quantity is greater than zero
bool Inventory::check_stock(const std::string& ingredient_name) const {
    auto it = stock.find(ingredient_name);
    return (it != stock.end() && it->second.get_quantity() > 0);
}

// Use a specified amount of an ingredient from the inventory
void Inventory::use_ingredient(const std::string& ingredient_name, int amount) {
    if (stock.find(ingredient_name) == stock.end()) {
        throw std::out_of_range("Ingredient not found.");
    }
    stock[ingredient_name].use(amount);

    // Check if the remaining quantity is low and display a warning message if necessary
    if (stock[ingredient_name].get_quantity() <= 5) {
        std::cout << "Warning: Only " << stock[ingredient_name].get_quantity() 
                  << " units of " << ingredient_name << " left. Please restock.\n";
    }
}

// Display current inventory and the quantity of each ingredient
void Inventory::display_inventory() const {
    std::cout << "Current Inventory:\n";
    if (stock.empty()) {
        std::cout << "No ingredients in the inventory.\n";
    } else {
        for (const auto& item : stock) {
            std::cout << item.first << ": " << item.second.get_quantity() << " units\n";
        }
    }
}

// Save inventory to a file
void Inventory::save_to_file(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for saving inventory!\n";
        return;
    }

    for (const auto& item : stock) {
        file << item.first << "," << item.second.get_quantity() << "\n";
    }

    file.close();
    std::cout << "Inventory saved to " << filename << ".\n";
}

// Load inventory from a file
void Inventory::load_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for loading inventory!\n";
        return;
    }

    stock.clear();  // Clear current stock before loading

    std::string ingredient;
    int quantity;
    char separator;  // For handling the comma separator

    while (file >> ingredient >> separator >> quantity) {
        stock[ingredient] = Ingredient(ingredient, quantity);
    }

    file.close();
    std::cout << "Inventory loaded from " << filename << ".\n";
}

#include "Inventory.h"

// Restock an ingredient in the inventory
void Inventory::restock(const std::string& ingredient_name, int quantity) {
    if (stock.find(ingredient_name) != stock.end()) {
        stock[ingredient_name].restock(quantity);
    } else {
        // Add new ingredient if it's not already in stock
        stock[ingredient_name] = Ingredient(ingredient_name, quantity);
    }

    std::cout << "Restocked " << ingredient_name << " with " << quantity << " units.\n";
}

// Check if the ingredient is in stock and has sufficient quantity
bool Inventory::check_stock(const std::string& ingredient_name) const {
    auto it = stock.find(ingredient_name);
    return (it != stock.end() && it->second.get_quantity() > 0);
}

// Use an ingredient from the inventory
void Inventory::use_ingredient(const std::string& ingredient_name, int amount) {
    if (stock.find(ingredient_name) == stock.end()) {
        throw std::out_of_range("Ingredient " + ingredient_name + " not found in inventory.");
    }

    stock[ingredient_name].use(amount);
    std::cout << "Used " << amount << " units of " << ingredient_name << ". Remaining: " 
              << stock[ingredient_name].get_quantity() << "\n";

    if (stock[ingredient_name].get_quantity() < 5) {
        std::cout << "Warning: Low stock on " << ingredient_name << "!\n";
    }
}

// Display the current inventory
void Inventory::display_inventory() const {
    std::cout << "Current Inventory:\n";
    for (const auto& item : stock) {
        std::cout << item.first << ": " << item.second.get_quantity() << " units\n";
    }
}

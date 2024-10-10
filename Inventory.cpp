#include "Inventory.h"
#include <iostream>

Inventory::Inventory() {
    // Initialize inventory with some default quantities
    ingredients.push_back({"Pasta", 10});
    ingredients.push_back({"Burger Bun", 15});
    ingredients.push_back({"Lettuce", 8});
    ingredients.push_back({"Tomato", 10});
    ingredients.push_back({"Beef Patty", 10});
    ingredients.push_back({"Salad Greens", 12});
}

// Add a new ingredient to the inventory
void Inventory::add_ingredient(const std::string& ingredient, int quantity) {
    ingredients.push_back({ingredient, quantity});
}

// Check if enough ingredients are available for a menu item
bool Inventory::check_stock(const MenuItem& item) {
    for (auto& ingredient : ingredients) {
        if (ingredient.first == item.get_ingredient() && ingredient.second >= item.get_ingredient_quantity()) {
            return true;
        }
    }
    return false;
}

// Use ingredients when preparing a menu item
void Inventory::use_ingredient(const MenuItem& item) {
    for (auto& ingredient : ingredients) {
        if (ingredient.first == item.get_ingredient()) {
            if (ingredient.second >= item.get_ingredient_quantity()) {
                ingredient.second -= item.get_ingredient_quantity();
                std::cout << "Used " << item.get_ingredient_quantity() << " units of " << item.get_ingredient() 
                          << ". Remaining: " << ingredient.second << std::endl;

                if (ingredient.second < 5) {
                    std::cout << "Warning: " << ingredient.first << " is low in stock!" << std::endl;
                }
            } else {
                std::cout << "Not enough stock of " << item.get_ingredient() << "!" << std::endl;
            }
        }
    }
}

// Restock ingredients
void Inventory::restock(const std::string& ingredient, int amount) {
    for (auto& item : ingredients) {
        if (item.first == ingredient) {
            item.second += amount;
            std::cout << ingredient << " restocked. New quantity: " << item.second << std::endl;
            return;
        }
    }
}

// Display the current inventory
void Inventory::display_inventory() const {
    std::cout << "Current Inventory:\n";
    for (const auto& ingredient : ingredients) {
        std::cout << ingredient.first << ": " << ingredient.second << " units remaining." << std::endl;
    }
}

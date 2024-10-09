#include "Inventory.h"
#include <iostream>

// Constructor initializes with some ingredients and quantities
Inventory::Inventory() {
    // Initialize with some default ingredients and quantities
    ingredients.push_back(Ingredient("Pasta", 10));
    ingredients.push_back(Ingredient("Burger Bun", 15));
    ingredients.push_back(Ingredient("Lettuce", 8));
    ingredients.push_back(Ingredient("Tomato", 10));
    ingredients.push_back(Ingredient("Beef Patty", 10));
    ingredients.push_back(Ingredient("Salad Greens", 12));
}

// Add a new ingredient to the inventory
void Inventory::add_ingredient(const std::string& ingredient, int quantity) {
    ingredients.push_back(Ingredient(ingredient, quantity));
}

// Check if enough ingredients are available for a menu item
bool Inventory::check_stock(const MenuItem& item) {
    std::string name = item.get_name();
    Ingredient* ingredient = find_ingredient(name);
    
    if (ingredient != nullptr && ingredient->get_quantity() > 0) {
        return true;
    }
    return false;
}

// Use ingredients when preparing a menu item
void Inventory::use_ingredients(const MenuItem& item) {
    std::string name = item.get_name();
    Ingredient* ingredient = find_ingredient(name);
    
    if (ingredient != nullptr && ingredient->get_quantity() > 0) {
        ingredient->use(1);
        std::cout << "Used one unit of " << name << ". Remaining: " 
                  << ingredient->get_quantity() << std::endl;
    } else {
        std::cout << "Out of stock for " << name << "!" << std::endl;
    }
}

// Restock ingredients
void Inventory::restock(const std::string& ingredient_name, int amount) {
    Ingredient* ingredient = find_ingredient(ingredient_name);
    
    if (ingredient != nullptr) {
        ingredient->restock(amount);
        std::cout << ingredient_name << " restocked. New quantity: " 
                  << ingredient->get_quantity() << std::endl;
    } else {
        std::cout << "Ingredient " << ingredient_name << " not found!" << std::endl;
    }
}

// Notify if stock of any ingredient is low
void Inventory::notify_low_stock(int threshold) {
    for (const auto& ingredient : ingredients) {
        if (ingredient.get_quantity() < threshold) {
            std::cout << "Warning: Low stock on " << ingredient.get_name() 
                      << " (only " << ingredient.get_quantity() << " left)" << std::endl;
        }
    }
}

// Display the current status of the inventory
void Inventory::display_inventory() const {
    std::cout << "Current Inventory Status:" << std::endl;
    for (const auto& ingredient : ingredients) {
        std::cout << ingredient.get_name() << ": " 
                  << ingredient.get_quantity() << " units remaining." << std::endl;
    }
}

// Helper function to find an ingredient by name
Ingredient* Inventory::find_ingredient(const std::string& name) {
    for (auto& ingredient : ingredients) {
        if (ingredient.get_name() == name) {
            return &ingredient;
        }
    }
    return nullptr;  // Return nullptr if ingredient is not found
}

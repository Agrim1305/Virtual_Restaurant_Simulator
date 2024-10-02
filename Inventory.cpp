#include "Inventory.h"
#include <iostream>

// Constructor to initialize the inventory
Inventory::Inventory() {
    // Initialize with some common ingredients (optional)
    ingredients.push_back({"Tomato", 50});
    ingredients.push_back({"Cheese", 30});
    ingredients.push_back({"Flour", 40});
}

// Function to add a new ingredient or update an existing one
void Inventory::addIngredient(const std::string& ingredient, int quantity) {
    for (auto& item : ingredients) {
        if (item.first == ingredient) {
            item.second += quantity;  // Update quantity if ingredient already exists
            return;
        }
    }
    // If the ingredient is not found, add it to the list
    ingredients.push_back({ingredient, quantity});
}

// Function to check if enough stock is available
bool Inventory::checkStock(const std::string& ingredient, int quantity) const {
    for (const auto& item : ingredients) {
        if (item.first == ingredient) {
            return item.second >= quantity;  // Return true if enough stock is available
        }
    }
    return false;  // Ingredient not found or insufficient stock
}

// Function to restock an ingredient
void Inventory::restock(const std::string& ingredient, int quantity) {
    for (auto& item : ingredients) {
        if (item.first == ingredient) {
            item.second += quantity;  // Add the restocked amount to the existing stock
            std::cout << "Restocked " << ingredient << " by " << quantity << " units.\n";
            return;
        }
    }
    // If the ingredient does not exist, add it to the inventory
    ingredients.push_back({ingredient, quantity});
    std::cout << "Added " << ingredient << " to the inventory with " << quantity << " units.\n";
}

// Function to notify if any stock is low
void Inventory::notifyLowStock() const {
    for (const auto& item : ingredients) {
        if (item.second < 10) {  // Notify if stock is below a threshold (e.g., 10 units)
            std::cout << "Warning: Low stock of " << item.first << " (" << item.second << " units remaining).\n";
        }
    }
}

// Function to display the current inventory
void Inventory::displayInventory() const {
    std::cout << "Current Inventory:\n";
    for (const auto& item : ingredients) {
        std::cout << "- " << item.first << ": " << item.second << " units\n";
    }
}

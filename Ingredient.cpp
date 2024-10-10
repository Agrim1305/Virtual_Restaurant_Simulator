#include "Ingredient.h"
#include <iostream>

// Constructor to initialize ingredient with name and quantity
Ingredient::Ingredient(const std::string& name, int quantity) 
    : name(name), quantity(quantity) {
    if (name.empty()) {
        throw std::length_error("Ingredient name cannot be empty.");
    }
    if (quantity < 0) {
        throw std::invalid_argument("Quantity cannot be negative.");
    }
}

// Get the current quantity of the ingredient
int Ingredient::get_quantity() const {
    return quantity;
}

// Restock the ingredient (increase quantity)
void Ingredient::restock(int amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Restock amount must be positive.");
    }
    quantity += amount;
}

// Use the ingredient (reduce quantity)
void Ingredient::use(int amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Usage amount must be positive.");
    }
    if (amount > quantity) {
        throw std::out_of_range("Not enough ingredient in stock.");
    }
    quantity -= amount;
}

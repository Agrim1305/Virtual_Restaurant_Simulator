#include "Ingredient.h"
#include <iostream>

// Initializes the ingredient's name and quantity using the provided arguments
Ingredient::Ingredient(const std::string& name, int quantity)
    : name(name), quantity(quantity) {
    if (name.empty()) {
        throw std::length_error("Ingredient name cannot be empty.");
    }
    if (quantity < 0) {
        throw std::invalid_argument("Quantity cannot be negative.");
    }
}

// Method to return the ingredient's name
std::string Ingredient::get_name() const {
    return name;
}

// Method to return the current quantity of the ingredient
int Ingredient::get_quantity() const {
    return quantity;
}

// Method to update the quantity of the ingredient, with a maximum limit of 15 units
void Ingredient::set_quantity(int new_quantity) {
    if (new_quantity < 0) {
        throw std::invalid_argument("Quantity cannot be negative.");
    }
    if (new_quantity > 15) {
        std::cout << "Warning: Stock for " << name << " capped at 15 units. Setting to 15 units.\n";
        quantity = 15;
    } else {
        quantity = new_quantity;
    }
}

// Method to restock the ingredient by adding a specified amount
void Ingredient::restock(int amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Restock amount must be positive.");
    }
    set_quantity(quantity + amount);
}

// Method to use a specified amount of the ingredient
void Ingredient::use(int amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Usage amount must be positive.");
    }
    if (amount > quantity) {
        throw std::out_of_range("Not enough ingredient in stock.");
    }
    quantity -= amount;
}

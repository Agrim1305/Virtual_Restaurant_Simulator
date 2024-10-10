#include "Ingredient.h"

Ingredient::Ingredient(const std::string& name, int quantity)
    : name(name), quantity(quantity) {
    if (name.empty()) {
        throw std::length_error("Ingredient name cannot be empty.");
    }
    if (quantity < 0) {
        throw std::invalid_argument("Quantity cannot be negative.");
    }
}

std::string Ingredient::get_name() const {
    return name;
}

int Ingredient::get_quantity() const {
    return quantity;
}

void Ingredient::set_quantity(int new_quantity) {
    if (new_quantity < 0) {
        throw std::invalid_argument("Quantity cannot be negative.");
    }
    quantity = new_quantity;
}

void Ingredient::use(int amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Usage amount must be positive.");
    }
    if (amount > quantity) {
        throw std::out_of_range("Not enough ingredient in stock.");
    }
    quantity -= amount;
}

void Ingredient::restock(int amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Restock amount must be positive.");
    }
    quantity += amount;
}

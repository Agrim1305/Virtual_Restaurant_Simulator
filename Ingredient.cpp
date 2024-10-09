#include "Ingredient.h"

Ingredient::Ingredient(const std::string& name, int quantity) 
    : name(name), quantity(quantity) {}

std::string Ingredient::get_name() const {
    return name;
}

int Ingredient::get_quantity() const {
    return quantity;
}

void Ingredient::use(int amount) {
    if (quantity >= amount) {
        quantity -= amount;
    }
}

void Ingredient::restock(int amount) {
    quantity += amount;
}

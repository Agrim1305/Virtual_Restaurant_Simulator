#include "MenuItem.h"
#include <iostream>
#include <stdexcept>

MenuItem::MenuItem(const std::string& name, float price, int prep_time, const std::string& main_ingredient, int quantity)
    : name(name), price(price), prep_time(prep_time), main_ingredient(main_ingredient), quantity(quantity) {
    
    // Validate strings
    if (name.empty() || main_ingredient.empty()) {
        throw std::length_error("Name or main ingredient cannot be empty.");
    }

    // Validate price and quantity
    if (price < 0 || quantity < 0) {
        throw std::invalid_argument("Price and quantity must be positive.");
    }

    std::cout << "MenuItem created: " << name << " with main ingredient: " << main_ingredient << "\n";
}

std::string MenuItem::get_name() const {
    return name;
}

float MenuItem::get_price() const {
    return price;
}

int MenuItem::get_prep_time() const {
    return prep_time;
}

std::string MenuItem::get_ingredient() const {
    return main_ingredient;
}

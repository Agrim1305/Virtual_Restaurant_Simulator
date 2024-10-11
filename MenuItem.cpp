#include "MenuItem.h"

// Initializes the menu item with a name, price, preparation time, main ingredient, and quantity
MenuItem::MenuItem(const std::string& name, float price, int prep_time, const std::string& main_ingredient, int quantity)
    : name(name), price(price), prep_time(prep_time), main_ingredient(main_ingredient), quantity(quantity) {}

//  Method to return the name of the menu item
const std::string& MenuItem::get_name() const {
    return name;
}

// Method to return the price of the menu item
float MenuItem::get_price() const {
    return price;
}

// Method to return the preparation time (in minutes) for the menu item
int MenuItem::get_prep_time() const {
    return prep_time;
}

// Method to return the main ingredient of the menu item
const std::string& MenuItem::get_ingredient() const {
    return main_ingredient;
}

// Implement the get_quantity method
int MenuItem::get_quantity() const {
    return quantity;
}

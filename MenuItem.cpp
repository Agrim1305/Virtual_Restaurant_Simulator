#include "MenuItem.h"

MenuItem::MenuItem(const std::string& name, float price, int prep_time, const std::string& main_ingredient, int quantity)
    : name(name), price(price), prep_time(prep_time), main_ingredient(main_ingredient), quantity(quantity) {}

const std::string& MenuItem::get_name() const {
    return name;
}

float MenuItem::get_price() const {
    return price;
}

int MenuItem::get_prep_time() const {
    return prep_time;
}

const std::string& MenuItem::get_ingredient() const {
    return main_ingredient;
}

// Implement the get_quantity method
int MenuItem::get_quantity() const {
    return quantity;
}

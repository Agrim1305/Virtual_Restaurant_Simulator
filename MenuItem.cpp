#include "MenuItem.h"

MenuItem::MenuItem(std::string name, float price, int prep_time, std::string ingredient, int ingredient_quantity)
    : name(name), price(price), prep_time(prep_time), ingredient(ingredient), ingredient_quantity(ingredient_quantity) {}

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
    return ingredient;
}

int MenuItem::get_ingredient_quantity() const {
    return ingredient_quantity;
}

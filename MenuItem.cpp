#include "MenuItem.h"

MenuItem::MenuItem(std::string name, float price, int prep_time)
    : name(name), price(price), prep_time(prep_time) {}

std::string MenuItem::get_name() const {
    return name;
}

float MenuItem::get_price() const {
    return price;
}

int MenuItem::get_prep_time() const {
    return prep_time;
}

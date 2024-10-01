#include "MenuItem.h"

MenuItem::MenuItem(std::string name, float price) : name(name), price(price) {}

std::string MenuItem::get_name() const {
    return name;
}

float MenuItem::get_price() const {
    return price;
}

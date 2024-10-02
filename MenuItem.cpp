#include "MenuItem.h"

std::string MenuItem::getName() const {
    return name;
}

float MenuItem::getPrice() const {
    return price;
}

int MenuItem::getPrepTime() const {
    return prep_time;
}

#include "Menu.h"

void Menu::add_item(const MenuItem& item) {
    items.push_back(item);
}

const std::vector<MenuItem>& Menu::get_items() const {
    return items;
}

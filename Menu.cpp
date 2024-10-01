#include "Menu.h"
#include <iostream>

void Menu::add_item(const MenuItem& item) {
    items.push_back(item);
}

void Menu::display_menu() const {
    for (const auto& item : items) {
        std::cout << item.get_name() << " - $" << item.get_price() << '\n';
    }
}

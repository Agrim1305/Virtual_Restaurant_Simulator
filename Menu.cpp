#include "Menu.h"
#include <iostream>
#include <algorithm>

void Menu::add_item(const MenuItem& item) {
    items.push_back(item);
}

void Menu::remove_item(const std::string& item_name) {
    items.erase(std::remove_if(items.begin(), items.end(),
        [&item_name](MenuItem& item) {
            return item.get_name() == item_name;
        }), items.end());
}

void Menu::display_menu() const {
    for (int i = 0; i < items.size(); i++) {
        std::cout << i + 1 << ". " << items[i].get_name() << " - $" 
                  << items[i].get_price() << " (Prep time: " 
                  << items[i].get_prep_time() << " mins)" << std::endl;
    }
}

MenuItem Menu::get_item(int index) const {
    if (index >= 0 && index < items.size()) {
        return items[index];
    }
    throw std::out_of_range("Invalid index");
}

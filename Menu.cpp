#include "Menu.h"
#include <stdexcept>

void Menu::add_item(const MenuItem& item) {
    items.push_back(item);
}

void Menu::display_menu() const {
    for (int i = 0; i < static_cast<int>(items.size()); i++) {
        std::cout << i + 1 << ". " << items[i].get_name() << " - $" << items[i].get_price()
                  << " (Prep time: " << items[i].get_prep_time() << " mins)" << std::endl;
    }
}

MenuItem Menu::get_item(int index) const {
    if (index >= 0 && index < static_cast<int>(items.size())) {
        return items[index];
    } else {
        throw std::out_of_range("Invalid item selection.");
    }
}

int Menu::get_items_size() const {
    return items.size();
}

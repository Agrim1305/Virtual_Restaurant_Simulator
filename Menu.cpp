#include "Menu.h"
#include <iostream>
#include <stdexcept>

// Add a menu item to the menu
void Menu::add_item(const MenuItem& item) {
    items.push_back(item);  // Add the item to the items vector
}

// Display the menu to the customer
void Menu::display_menu() const {
    for (int i = 0; i < static_cast<int>(items.size()); i++) {  // Cast to fix signedness issue
        std::cout << i + 1 << ". " << items[i].get_name() << " - $" << items[i].get_price()
                  << " (Prep time: " << items[i].get_prep_time() << " mins)" << std::endl;
    }
}

// Retrieve a menu item by index
MenuItem Menu::get_item(int index) const {
    if (index >= 0 && index < static_cast<int>(items.size())) {  // Cast to fix signedness issue
        return items[index];
    } else {
        throw std::out_of_range("Invalid item selection.");
    }
}

// Get the number of items in the menu
int Menu::get_items_size() const {
    return items.size();
}

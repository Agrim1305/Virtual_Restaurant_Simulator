#include "Menu.h"
#include <iostream>

void Menu::addItem(const MenuItem& item) {
    items.push_back(item);
}

void Menu::displayMenu() const {
    for (const auto& item : items) {
        std::cout << "Item: " << item.getName() << ", Price: " << item.getPrice() << ", Prep Time: " << item.getPrepTime() << " mins\n";
    }
}

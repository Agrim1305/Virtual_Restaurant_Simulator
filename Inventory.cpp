#include "Inventory.h"
#include <iostream>

bool Inventory::check_stock(const MenuItem& item) {
    // Logic to check if stock is available
    return true;
}

void Inventory::restock(const std::string& ingredient, int amount) {
    std::cout << "Restocking " << ingredient << " by " << amount << std::endl;
}

void Inventory::notify_low_stock() {
    std::cout << "Warning: Low stock for some ingredients!" << std::endl;
}

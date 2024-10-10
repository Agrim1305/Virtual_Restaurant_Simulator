#include "Inventory.h"

void Inventory::restock(const std::string& ingredient_name, int quantity) {
    if (stock.find(ingredient_name) != stock.end()) {
        stock[ingredient_name].restock(quantity);
    } else {
        stock[ingredient_name] = Ingredient(ingredient_name, quantity);
    }
    std::cout << "Restocked " << ingredient_name << " with " << quantity << " units.\n";
}

bool Inventory::check_stock(const std::string& ingredient_name) const {
    auto it = stock.find(ingredient_name);
    return (it != stock.end() && it->second.get_quantity() > 0);
}

void Inventory::use_ingredient(const std::string& ingredient_name, int amount) {
    if (stock.find(ingredient_name) == stock.end()) {
        throw std::out_of_range("Ingredient not found.");
    }
    stock[ingredient_name].use(amount);
}

void Inventory::display_inventory() const {
    std::cout << "Current Inventory:\n";
    for (const auto& item : stock) {
        std::cout << item.first << ": " << item.second.get_quantity() << " units\n";
    }
}

#include "Customer.h"
#include <iostream>

Customer::Customer(std::string name) : name(name) {}

void Customer::place_order(Menu& menu) {
    int choice;
    menu.display_menu();
    std::cout << "Choose an item by entering its index: ";
    std::cin >> choice;
    // Simplified for now: handle placing the order here
}

Order Customer::get_order() const {
    return order;
}

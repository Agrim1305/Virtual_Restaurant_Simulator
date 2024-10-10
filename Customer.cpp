#include "Customer.h"
#include "Menu.h"
#include <iostream>

Customer::Customer(const std::string& name, int table_number)
    : name(name), table_number(table_number) {}

void Customer::place_order(const Menu& menu) {
    int choice;
    menu.display_menu();  // Display the menu to the customer
    std::cout << "Select items to order (enter 0 to finish): ";

    while (std::cin >> choice && choice != 0) {
        // Ensure the choice is within the valid range of menu items
        if (choice >= 1 && choice <= menu.get_items_size()) {
            // Add the selected item to the customer's order
            order.add_item(menu.get_item(choice - 1));  // 1-based to 0-based index
            std::cout << "Item added to order.\n";
        } else {
            std::cout << "Invalid selection. Please try again.\n";
        }
        std::cout << "Select items to order (enter 0 to finish): ";
    }
}

Order Customer::get_order() const {
    return order;
}

float Customer::pay_bill() const {
    return order.calculate_total();
}

// Overloading the << operator for Customer class
std::ostream& operator<<(std::ostream& os, const Customer& customer) {
    os << "Customer Name: " << customer.name << "\n";
    os << "Table Number: " << customer.table_number << "\n";
    os << customer.get_order();  // Use the overloaded << operator from Order class
    return os;
}

#include "Customer.h"
#include <iostream>

Customer::Customer(const std::string& name, int table_number)
    : name(name), table_number(table_number), order_completed(false) {}

std::string Customer::get_name() const {
    return name;
}

int Customer::get_table_number() const {
    return table_number;
}

void Customer::place_order(const Menu& menu) {
    int choice;
    std::cout << "Select items to order (enter 0 to finish): \n";
    for (size_t i = 0; i < menu.get_items().size(); ++i) {
        std::cout << i + 1 << ". " << menu.get_items()[i].get_name() 
                  << " - $" << menu.get_items()[i].get_price() << "\n";
    }

    while (true) {
        std::cin >> choice;
        if (choice == 0) break;

        // Cast menu.get_items().size() to int to fix warning
        if (choice > 0 && choice <= static_cast<int>(menu.get_items().size())) {
            order.add_item(menu.get_items()[choice - 1]);
            std::cout << "Item added to order.\n";
        } else {
            std::cout << "Invalid selection. Please try again.\n";
        }
    }
}

const Order& Customer::get_order() const {
    return order;
}

bool Customer::is_order_completed() const {
    return order_completed;
}

void Customer::complete_order() {
    order_completed = true;
}

std::ostream& operator<<(std::ostream& os, const Customer& customer) {
    os << "Customer Name: " << customer.name << "\n";
    os << "Table Number: " << customer.table_number << "\n";
    os << "Order Summary:\n";
    os << customer.order;
    return os;
}

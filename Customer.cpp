#include "Customer.h"
#include "Menu.h"

Customer::Customer(const std::string& name, int table_number)
    : name(name), table_number(table_number), order_completed(false) {}

void Customer::place_order(const Menu& menu) {
    int choice;
    menu.display_menu();
    std::cout << "Select items to order (enter 0 to finish): ";

    while (std::cin >> choice && choice != 0) {
        if (choice >= 1 && choice <= menu.get_items_size()) {
            order.add_item(menu.get_item(choice - 1));
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

void Customer::complete_order() {
    order = Order();  // Reset the order
    order_completed = true;
}

bool Customer::is_order_completed() const {
    return order_completed;
}

std::ostream& operator<<(std::ostream& os, const Customer& customer) {
    os << "Customer Name: " << customer.name << "\n";
    os << "Table Number: " << customer.table_number << "\n";
    os << customer.get_order();
    return os;
}

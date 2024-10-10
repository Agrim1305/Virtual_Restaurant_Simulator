#include "Customer.h"

Customer::Customer(const std::string& name, int table_number)
    : name(name), table_number(table_number) {}

const std::string& Customer::get_name() const {
    return name;
}

int Customer::get_table_number() const {
    return table_number;
}

Order& Customer::get_order() {
    return order;
}

void Customer::place_order(const Menu& menu) {
    order.add_items_from_menu(menu);  // Make sure this method is correctly implemented in Order
}

void Customer::complete_order() {
    std::cout << "Order for customer " << name << " is complete.\n";
}

void Customer::save_order_to_file(const std::string& filename) const {
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening file to save order!\n";
        return;
    }

    file << "Customer Name: " << name << "\n";
    file << "Table Number: " << table_number << "\n";
    file << "Order Summary:\n";

    const auto& items = order.get_items();
    for (const auto& item : items) {
        file << "- " << item.get_name() << " : $" << item.get_price() << "\n";
    }

    file << "Total: $" << order.calculate_total() << "\n";
    file << "-----------------------------------\n";

    file.close();
    std::cout << "Order saved to " << filename << ".\n";
}

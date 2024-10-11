#include "Customer.h"
#include <iostream>
#include <fstream>

// Initializes the customer's name and the table number they are seated at
Customer::Customer(const std::string& name, int table_number)
    : name(name), table_number(table_number) {}

// Method to return the customer's name
const std::string& Customer::get_name() const {
    return name;
}

// Method to return the table number associated with the customer
int Customer::get_table_number() const {
    return table_number;
}

// Provides access to the customer's current order
Order& Customer::get_order() {
    return order;
}

// Places an order by adding items from the provided menu
// Calls 'add_items_from_menu' from the 'Order' class, and prints the total
void Customer::place_order(const Menu& menu) {
    order.add_items_from_menu(menu);  // Assumes this method is implemented correctly in Order
}

// Outputs a message indicating that the order is complete for this customer
void Customer::complete_order() {
    std::cout << "Order for customer " << name << " is complete.\n";
}

// Saves the current order to a specified file
void Customer::save_order_to_file(const std::string& filename) const {
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {  // Check if file opened successfully
        std::cerr << "Error opening file to save order!\n";
        return;
    }

    // Write customer details and order summary to the file
    file << "Customer Name: " << name << "\n";
    file << "Table Number: " << table_number << "\n";
    file << "Order Summary:\n";

    // Get the ordered items and write each to the file
    const auto& items = order.get_items();
    for (const auto& item : items) {
        file << "- " << item.get_name() << " : $" << item.get_price() << "\n";
    }

    // Write the total order amount to the file
    file << "Total: $" << order.calculate_total() << "\n";
    file << "-----------------------------------\n";

    file.close();  // Close the file after writing
    std::cout << "Order saved to " << filename << ".\n";  // Output confirmation message
}

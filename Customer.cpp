#include "Customer.h"
#include <regex>

// Flag to track if a customer is currently being served
bool customer_in_process = false;

// Initializes the customer's name and the table number they are seated at
Customer::Customer(const std::string& name_input, int table_number)
    : name(trim(name_input)), table_number(table_number) {
    // Enforce that the customer's name contains only letters (no numbers or special characters)
    std::regex name_pattern("^[A-Za-z]+$");
    if (!std::regex_match(name, name_pattern)) {
        throw std::invalid_argument("Customer name can only contain letters.");
    }
    // Ensure only one customer is processed at a time
    if (customer_in_process) {
        throw std::runtime_error("Another customer is currently being served. Please wait.");
    }
    customer_in_process = true;
}

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
void Customer::place_order(const Menu& menu) {
    order.add_items_from_menu(menu);
}

// Outputs a message indicating that the order is complete for this customer
void Customer::complete_order() {
    std::cout << "Order for customer " << name << " is complete.\n";
    customer_in_process = false;  // Allow another customer after the current one is completed
}

// Saves the current order to a specified file
void Customer::save_order_to_file(const std::string& filename) const {
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening file to save order!\n";
        return;
    }
    file << "Customer Name: " << name << "\n";
    file << "Table Number: " << table_number << "\n";
    order.save_to_file(file);  // Assuming this method is implemented in the Order class
}

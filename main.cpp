#include <iostream>
#include "Menu.h"
#include "Customer.h"
#include "Order.h"

int main() {
    // Create a simple menu
    Menu menu;
    menu.add_item(MenuItem("Pizza", 12.50));
    menu.add_item(MenuItem("Burger", 8.75));
    menu.add_item(MenuItem("Pasta", 10.00));

    // Display the menu
    std::cout << "Welcome to the Restaurant Simulator!\n";
    menu.display_menu();

    // Create a customer and allow them to place an order
    Customer customer("John Doe");
    customer.place_order(menu);

    // Show the customer's order
    std::cout << "\nCustomer Order: \n";
    customer.get_order().display_order();

    return 0; // Program ran successfully
}

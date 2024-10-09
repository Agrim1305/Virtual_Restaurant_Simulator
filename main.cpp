#include "Restaurant.h"
#include "Customer.h"
#include "Menu.h"
#include <iostream>

int main() {
    Restaurant myRestaurant;

    // Access menu via the getter method
    myRestaurant.get_menu().add_item(MenuItem("Pasta", 12.99, 15));
    myRestaurant.get_menu().add_item(MenuItem("Burger", 8.99, 10));
    myRestaurant.get_menu().add_item(MenuItem("Salad", 6.99, 5));

    // Simulate customer seating and ordering
    Customer customer("John Doe", 1);
    myRestaurant.seat_customer(customer);
    myRestaurant.process_order(customer);
    customer.get_order().display_order();
    std::cout << "Total to pay: $" << customer.pay_bill() << std::endl;

    return 0;
}

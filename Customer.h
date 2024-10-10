#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Order.h"
#include <string>
#include <iostream>

class Menu;  // Forward declaration of the Menu class

class Customer {
    std::string name;
    int table_number;
    Order order;  // Customer's current order
    bool order_completed;  // New flag to track if the order is completed

public:
    Customer(const std::string& name, int table_number);

    void place_order(const Menu& menu);
    Order get_order() const;
    float pay_bill() const;

    void complete_order();  // Method to reset the order after serving
    bool is_order_completed() const;  // New method to check if the order is completed

    // Overloading << operator to display customer information
    friend std::ostream& operator<<(std::ostream& os, const Customer& customer);
};

#endif

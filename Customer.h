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

public:
    Customer(const std::string& name, int table_number);

    void place_order(const Menu& menu);
    Order get_order() const;
    float pay_bill() const;

    // New method to reset the order after serving
    void complete_order();

    // Overloading << operator to display customer information
    friend std::ostream& operator<<(std::ostream& os, const Customer& customer);
};

#endif

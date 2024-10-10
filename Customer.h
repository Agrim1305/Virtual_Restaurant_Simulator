#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Order.h"
#include <string>
#include <iostream>

class Menu;  // Forward declaration of the Menu class

class Customer {
    std::string name;
    int table_number;
    Order order;

public:
    Customer(const std::string& name, int table_number);

    void place_order(const Menu& menu);  // Reference to Menu class
    Order get_order() const;
    float pay_bill() const;

    // Overloading << operator to display customer information
    friend std::ostream& operator<<(std::ostream& os, const Customer& customer);
};

#endif

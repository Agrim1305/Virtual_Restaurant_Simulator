#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Order.h"
#include <string>

class Menu;  // Forward declaration of Menu

class Customer {
    std::string name;
    int table_number;
    Order order;

public:
    Customer(std::string name, int table_number);

    void place_order(const Menu& menu);  // Use the forward-declared Menu
    Order get_order() const;
    float pay_bill() const;
};

#endif

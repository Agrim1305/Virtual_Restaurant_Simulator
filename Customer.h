#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Order.h"
#include <string>
#include <iostream>

class Menu;  // Forward declaration

class Customer {
private:
    std::string name;
    int table_number;
    Order order;
    bool order_completed;

public:
    Customer(const std::string& name, int table_number);

    void place_order(const Menu& menu);
    Order get_order() const;
    float pay_bill() const;
    void complete_order();
    bool is_order_completed() const;

    // Overloading << operator
    friend std::ostream& operator<<(std::ostream& os, const Customer& customer);
};

#endif

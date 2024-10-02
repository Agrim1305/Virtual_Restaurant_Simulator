#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Order.h"
#include "Menu.h"  // Add this to resolve the 'Menu' declaration issue

class Customer {
private:
    std::string name;
    int table_number;
    Order order;
public:
    Customer(std::string n, int t);
    void placeOrder(Menu& menu);  // Now 'Menu' is recognized
    Order getOrder() const;
};

#endif

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Order.h"
#include "Menu.h"

class Customer {
private:
    std::string name;
    Order order;

public:
    Customer(std::string name);
    void place_order(Menu& menu);
    Order get_order() const;
};

#endif

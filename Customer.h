#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Order.h"
#include "Menu.h"  

class Customer {
private:
    std::string name;
    int table_number;
    Order order;
public:
    Customer(std::string n, int t);
    void placeOrder(Menu& menu);  
    Order getOrder() const;
};

#endif

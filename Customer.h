#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Order.h"
#include "Menu.h"  // Include the Menu class

#include <string>
#include <iostream>
#include <fstream>  // For file I/O

class Customer {
private:
    std::string name;
    int table_number;
    Order order;

public:
    Customer(const std::string& name, int table_number);
    const std::string& get_name() const;
    int get_table_number() const;
    Order& get_order();
    
    void place_order(const Menu& menu);  // Menu is now recognized
    void complete_order();

    // New method to save customer order to a file
    void save_order_to_file(const std::string& filename) const;
};

#endif

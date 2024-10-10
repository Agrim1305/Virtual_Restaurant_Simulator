#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Order.h"
#include "Menu.h"
#include <string>

class Customer {
private:
    std::string name;
    int table_number;
    Order order;
    bool order_completed;

public:
    Customer(const std::string& name, int table_number);

    std::string get_name() const;
    int get_table_number() const;
    void place_order(const Menu& menu);
    const Order& get_order() const;
    bool is_order_completed() const;
    void complete_order();

    friend std::ostream& operator<<(std::ostream& os, const Customer& customer);
};

#endif

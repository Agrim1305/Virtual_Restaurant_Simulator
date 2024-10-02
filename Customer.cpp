#include "Customer.h"
#include "Menu.h"  // Include this to resolve scope issues
#include <iostream>

Customer::Customer(std::string n, int t) : name(n), table_number(t) {}

void Customer::placeOrder(Menu& menu) {
    // Logic for placing an order can be added here
}

Order Customer::getOrder() const {
    return order;
}

#include "Customer.h"
#include "Menu.h"  
#include <iostream>

Customer::Customer(std::string n, int t) : name(n), table_number(t) {}

void Customer::placeOrder(Menu& menu) {

}

Order Customer::getOrder() const {
    return order;
}

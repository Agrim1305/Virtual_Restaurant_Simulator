#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Menu.h"
#include "Table.h"
#include "Inventory.h"
#include "Employee.h"
#include "Customer.h"
#include <vector>

class Restaurant {
    Menu menu;
    std::vector<Table> tables;
    Inventory inventory;
    std::vector<Employee*> employees;

public:
    Menu& get_menu();  // Add this method to get access to the menu

    void process_order(Customer& customer);
    void seat_customer(Customer& customer);
    void track_performance();
};

#endif

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Menu.h"
#include "Table.h"
#include "Inventory.h"
#include "Employee.h"
#include <vector>

class Restaurant {
    Menu menu;
    Inventory inventory;
    std::vector<Employee*> employees;  // Store employees as pointers for polymorphism

public:
    Restaurant();

    Menu& get_menu();
    Inventory& get_inventory();

    void add_employee(Employee* employee);  // Add employee (Chef, Waiter, Manager)
    void process_order(Customer& customer);
    void seat_customer(Customer& customer);
    void serve_order(Customer& customer);
    void track_performance();
};

#endif

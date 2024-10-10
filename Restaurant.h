#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Menu.h"
#include "Inventory.h"
#include "Employee.h"
#include "Customer.h"
#include <vector>

class Restaurant {
private:
    Menu menu;
    Inventory inventory;
    std::vector<Employee*> employees;

public:
    Restaurant();
    Menu& get_menu();
    Inventory& get_inventory();
    void add_employee(Employee* employee);
    void process_order(Customer& customer);
    void seat_customer(Customer& customer);
    void serve_order(Customer& customer);
    void track_performance();
};

#endif

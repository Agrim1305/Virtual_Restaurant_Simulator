#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Menu.h"
#include "Inventory.h"
#include "Employee.h"
#include "Customer.h"  // Include Customer class

#include <vector>

class Restaurant {
    Menu menu;  // The restaurant's menu
    Inventory inventory;  // The restaurant's inventory
    std::vector<Employee*> employees;  // List of employees (Chef, Waiter, Manager)

public:
    Restaurant();  // Default constructor

    Menu& get_menu();  // Get the menu reference
    Inventory& get_inventory();  // Get the inventory reference

    void add_employee(Employee* employee);  // Add an employee (Chef, Waiter, Manager)
    void process_order(Customer& customer);  // Process the order placed by a customer
    void seat_customer(Customer& customer);  // Seat a customer in the restaurant
    void serve_order(Customer& customer);  // Serve the customer's order
    void track_performance();  // Track the performance of employees
};

#endif

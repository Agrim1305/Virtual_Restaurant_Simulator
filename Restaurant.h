#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Menu.h"
#include "Inventory.h"
#include "Employee.h"
#include "Customer.h"
#include <vector>

// Declaration of the Restaurant class, which manages various aspects of a restaurant
class Restaurant {
private:
    Menu menu; // Menu of the restaurant
    Inventory inventory; // Inventory of ingredients for preparing food
    std::vector<Employee*> employees; // List of employees working at the restaurant

public:
    Restaurant();

    // Method to access the restaurant's menu
    Menu& get_menu();

    // Method to access the restaurant's inventory
    Inventory& get_inventory();

    // Adds an employee to the restaurant
    void add_employee(Employee* employee);

     // Processes the customer's order by checking inventory and using ingredients
    void process_order(Customer& customer);

    // Seats a customer at the restaurant
    void seat_customer(Customer& customer);

     // Serves a completed order to the customer and saves the order details to a file
    void serve_order(Customer& customer, const std::string& filename);

     // Tracks the performance of employees
    void track_performance();

     // Displays the current menu
    void view_menu();

     // New method to add a menu item
    void add_menu_item(const MenuItem& item);
};

#endif

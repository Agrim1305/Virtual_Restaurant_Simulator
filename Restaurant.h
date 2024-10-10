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
    Inventory inventory;
    std::vector<Chef> chefs;
    std::vector<Waiter> waiters;
    Manager* manager;

public:
    Restaurant();  // Constructor

    Menu& get_menu();
    Inventory& get_inventory();

    void add_chef(const Chef& chef);  // Add chef
    void add_waiter(const Waiter& waiter);  // Add waiter
    void set_manager(Manager* manager);  // Set manager

    void process_order(Customer& customer);  // Process customer order
    void seat_customer(Customer& customer);  // Seat customer
    void serve_order(Customer& customer);  // Serve order
    void track_performance();  // Track performance
};

#endif

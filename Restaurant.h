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
    std::vector<Chef> chefs;  // Store Chefs
    std::vector<Waiter> waiters;  // Store Waiters
    Manager* manager;  // One Manager

public:
    Restaurant();

    Menu& get_menu();
    Inventory& get_inventory();

    void add_chef(const Chef& chef);
    void add_waiter(const Waiter& waiter);
    void set_manager(Manager* manager);

    void process_order(Customer& customer);  // Process using chef
    void seat_customer(Customer& customer);
    void serve_order(Customer& customer);  // Serve using waiter
    void track_performance();
};

#endif

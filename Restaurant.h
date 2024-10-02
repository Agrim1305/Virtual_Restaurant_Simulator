#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Menu.h"
#include "Customer.h"
#include "Inventory.h"

class Restaurant {
private:
    Menu menu;
    Inventory inventory;
public:
    void placeOrder();
    void manageStaff();
    void checkInventory();
    void viewPerformance();
};

#endif

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Order.h"
#include "Menu.h"
#include <iostream>
using namespace std;

// Customer class
class Customer {
    string name;
    Order order;
public:
    Customer(string name) : name(name) {}
    void placeOrder(Menu& menu) {
        int choice;
        cout << "Place your order by selecting menu items: " << endl;
        menu.displayMenu();
        cout << "Enter 1 to add a sample item to the order, 0 to stop: ";
        cin >> choice;
        while (choice != 0) {
            order.addItem(MenuItem("Sample Dish", 10.0f)); // Sample for now
            cout << "Enter 1 to add more, 0 to stop: ";
            cin >> choice;
        }
    }
    void displayOrder() const { order.displayOrder(); }
};

#endif

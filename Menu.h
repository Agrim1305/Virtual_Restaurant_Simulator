#ifndef MENU_H
#define MENU_H

#include "MenuItem.h"
#include <vector>
#include <iostream>
using namespace std;

// Menu class
class Menu {
    vector<MenuItem> items;
public:
    void addItem(MenuItem item) { items.push_back(item); }
    void displayMenu() const {
        for (const auto& item : items) {
            cout << item.getName() << " - $" << item.getPrice() << endl;
        }
    }
};

#endif

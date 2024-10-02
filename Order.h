#ifndef ORDER_H
#define ORDER_H

#include "MenuItem.h"
#include <vector>
#include <iostream>
using namespace std;

// Order class
class Order {
    vector<MenuItem> items;
    float totalCost = 0;
public:
    void addItem(MenuItem item) {
        items.push_back(item);
        totalCost += item.getPrice();
    }
    void displayOrder() const {
        cout << "Order: " << endl;
        for (const auto& item : items) {
            cout << item.getName() << " - $" << item.getPrice() << endl;
        }
        cout << "Total: $" << totalCost << endl;
    }
};

#endif

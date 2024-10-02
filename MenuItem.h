#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
using namespace std;

// MenuItem class
class MenuItem {
    string name;
    float price;
public:
    MenuItem(string name, float price) : name(name), price(price) {}
    string getName() const { return name; }
    float getPrice() const { return price; }
};

#endif

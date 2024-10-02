#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

class MenuItem {
private:
    std::string name;
    float price;
    int prep_time;
public:
    MenuItem(std::string n, float p, int t) : name(n), price(p), prep_time(t) {}
    std::string getName() const;
    float getPrice() const;
    int getPrepTime() const;
};

#endif

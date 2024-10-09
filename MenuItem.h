#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

class MenuItem {
    std::string name;
    float price;
    int prep_time;

public:
    MenuItem(std::string name, float price, int prep_time);

    std::string get_name() const;
    float get_price() const;
    int get_prep_time() const;
};

#endif

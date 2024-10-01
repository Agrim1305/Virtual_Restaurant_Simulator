#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

class MenuItem {
private:
    std::string name;
    float price;

public:
    MenuItem(std::string name, float price);
    std::string get_name() const;
    float get_price() const;
};

#endif

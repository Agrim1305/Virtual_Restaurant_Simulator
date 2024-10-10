#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <stdexcept>

class MenuItem {
private:
    std::string name;
    float price;
    int prep_time;
    std::string main_ingredient;
    int quantity;

public:
    // Constructor with validation
    MenuItem(const std::string& name, float price, int prep_time, const std::string& main_ingredient, int quantity);

    std::string get_name() const;
    float get_price() const;
    int get_prep_time() const;
    std::string get_ingredient() const;
};

#endif

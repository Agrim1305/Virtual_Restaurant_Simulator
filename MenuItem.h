#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

class MenuItem {
    std::string name;
    float price;
    int prep_time;
    std::string ingredient;  // The key ingredient needed
    int ingredient_quantity; // Quantity of the ingredient used per order

public:
    MenuItem(std::string name, float price, int prep_time, std::string ingredient, int ingredient_quantity);

    std::string get_name() const;
    float get_price() const;
    int get_prep_time() const;
    std::string get_ingredient() const;  // Get ingredient name
    int get_ingredient_quantity() const;  // Get ingredient quantity used per order
};

#endif

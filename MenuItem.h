#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

class MenuItem {
private:
// Private members to store the name, price, preparation time, main ingredient, and quantity of the menu item
    std::string name;
    float price;
    int prep_time;
    std::string main_ingredient;
    int quantity;  // Add quantity attribute

public:
 // Constructor to initialize a menu item with its name, price, preparation time, main ingredient, and quantity
    MenuItem(const std::string& name, float price, int prep_time, const std::string& main_ingredient, int quantity);
    
    const std::string& get_name() const;
    float get_price() const;
    int get_prep_time() const;
    const std::string& get_ingredient() const;
    
    // Add getter for quantity
    int get_quantity() const;
};

#endif

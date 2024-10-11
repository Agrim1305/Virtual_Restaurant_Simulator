#ifndef MENU_H
#define MENU_H

#include "MenuItem.h"
#include <vector>
#include <string>  // For file operations

// Declaration of the Menu class to manage a list of menu items
class Menu {
private:
// Vector to store a list of menu items
    std::vector<MenuItem> items;

public:
  // Method to add a new item and to return a constant reference to the list of menu items
    void add_item(const MenuItem& item);
    const std::vector<MenuItem>& get_items() const;

    // New methods to save and load the menu from a file
    void save_to_file(const std::string& filename) const;
    void load_from_file(const std::string& filename);
    
    void display_menu() const;
};

#endif

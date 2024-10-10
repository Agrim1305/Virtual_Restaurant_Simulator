#ifndef MENU_H
#define MENU_H

#include "MenuItem.h"
#include <vector>
#include <string>  // For file operations

class Menu {
private:
    std::vector<MenuItem> items;

public:
    void add_item(const MenuItem& item);
    const std::vector<MenuItem>& get_items() const;

    // New methods to save and load the menu from a file
    void save_to_file(const std::string& filename) const;
    void load_from_file(const std::string& filename);
    
    void display_menu() const;
};

#endif

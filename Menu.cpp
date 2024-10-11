#include "Menu.h"
#include <fstream>  // For file operations
#include <iostream>
#include <sstream>   // For stringstream

// Adds a new item to the menu
void Menu::add_item(const MenuItem& item) {
    items.push_back(item);
}

// Method to return a constant reference to the list of menu items
const std::vector<MenuItem>& Menu::get_items() const {
    return items;
}

//  Displays the menu items along with their details: name, price, and preparation time
void Menu::display_menu() const {
    std::cout << "Available Menu Items:\n";
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << i + 1 << ". " << items[i].get_name() 
                  << " - $" << items[i].get_price()
                  << " (Prep time: " << items[i].get_prep_time() << " mins)\n";
    }
}

// Save the menu items to a file
void Menu::save_to_file(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for saving menu.\n";
        return;
    }

// Menu item details are added to the file
    for (const auto& item : items) {
        file << item.get_name() << "," << item.get_price() 
             << "," << item.get_prep_time() << "," 
             << item.get_ingredient() << "," << item.get_quantity() << "\n";  // Saves quantity now
    }

    file.close();
    std::cout << "Menu saved to " << filename << "\n";
}

// Load menu items from a file
void Menu::load_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) { // Check if the file was successfully opened
        std::cerr << "Error: Could not open file for loading menu.\n";
        return;
    }

    items.clear();  // Clear current menu before loading

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, ingredient;
        float price;
        int prep_time, quantity;

        std::getline(ss, name, ','); // Get the name of the menu item
        ss >> price; // Get the price of the menu item
        ss.ignore(); // Skips the comma
        ss >> prep_time; // Get the preparation time of the menu item
        ss.ignore();  // Skips the comma
        std::getline(ss, ingredient, ','); // Get the main ingredient of the menu item
        ss >> quantity; // Get the quantity of the ingredient used


        // Ensure that the correct number of arguments are passed to the MenuItem constructor
        items.push_back(MenuItem(name, price, prep_time, ingredient, quantity));
    }

    file.close(); 
    std::cout << "Menu loaded from " << filename << "\n";
}

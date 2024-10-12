#include "Restaurant.h"
#include "Menu.h"
#include "Inventory.h"
#include "Employee.h"
#include "Customer.h"
#include "Table.h"
#include "Chef.h"
#include "HeadChef.h"
#include "Waiter.h"
#include "Manager.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <memory>  // For smart pointers
#include <algorithm> // For std::transform

// Helper function to trim whitespace from both ends of a string
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return (first == std::string::npos || last == std::string::npos) ? "" : str.substr(first, last - first + 1);
}

// Function to display saved orders from the file
void display_saved_orders(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening orders file!\n";
        return;
    }

    std::cout << "==== Saved Orders ====\n";
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }

    file.close();
}

// Function to display the main menu of options for the Virtual Restaurant Simulator
void display_menu() {
    std::cout << "==== Virtual Restaurant Simulator ====\n";
    std::cout << "1. Add Customer and Seat Them\n";
    std::cout << "2. Place Customer Order\n";
    std::cout << "3. Serve Customer Order\n";
    std::cout << "4. Restock Inventory\n";
    std::cout << "5. View Inventory\n";
    std::cout << "6. Track Performance\n";
    std::cout << "7. View Menu\n";
    std::cout << "8. Save Inventory & Menu to File\n";
    std::cout << "9. Load Inventory & Menu from File\n";
    std::cout << "10. View Saved Orders\n";
    std::cout << "0. Exit\n";
    std::cout << "Select an option: ";
}

// Function to initialize the inventory with default items
void initialize_inventory(Restaurant& restaurant) {
    restaurant.get_inventory().restock("Pasta", 10, true);
    restaurant.get_inventory().restock("Beef Patty", 10, true);
    restaurant.get_inventory().restock("Salad Greens", 10, true);
    restaurant.get_inventory().restock("Bread", 10, true);
    restaurant.get_inventory().restock("Dough", 10, true);
    restaurant.get_inventory().restock("Rice", 10, true);
    restaurant.get_inventory().restock("Tortilla", 10, true);
    restaurant.get_inventory().restock("Cabbage", 10, true);
    restaurant.get_inventory().restock("Potatoes", 10, true);
    restaurant.get_inventory().restock("Chicken", 10, true);
    restaurant.get_inventory().restock("Chocolate", 10, true);
    restaurant.get_inventory().restock("Cheese", 10, true);
    restaurant.get_inventory().restock("Ice Cream", 10, true);
    restaurant.get_inventory().restock("Coffee Beans", 10, true);
    restaurant.get_inventory().restock("Tea Leaves", 10, true);
    restaurant.get_inventory().restock("Soda Syrup", 10, true);
    restaurant.get_inventory().restock("Milk", 10, true);
    restaurant.get_inventory().restock("Fruit", 10, true);
    restaurant.get_inventory().restock("Lemon", 10, true);
}

int main() {
    try {
        Restaurant myRestaurant;

        // Add food items to the menu without restocking the inventory automatically
        myRestaurant.add_menu_item(MenuItem("Pasta", 12.99, 15, "Pasta", 1));
        myRestaurant.add_menu_item(MenuItem("Burger", 8.99, 10, "Beef Patty", 1));
        myRestaurant.add_menu_item(MenuItem("Salad", 6.99, 5, "Salad Greens", 1));
        myRestaurant.add_menu_item(MenuItem("Garlic Bread", 3.99, 5, "Bread", 1));
        myRestaurant.add_menu_item(MenuItem("Pizza", 14.99, 20, "Dough", 1));
        myRestaurant.add_menu_item(MenuItem("Sushi", 19.99, 25, "Rice", 1));
        myRestaurant.add_menu_item(MenuItem("Tacos", 7.99, 10, "Tortilla", 1));
        myRestaurant.add_menu_item(MenuItem("Spring Rolls", 6.99, 10, "Cabbage", 1));
        myRestaurant.add_menu_item(MenuItem("French Fries", 4.99, 7, "Potatoes", 1));
        myRestaurant.add_menu_item(MenuItem("Chicken Wings", 9.99, 15, "Chicken", 1));
        myRestaurant.add_menu_item(MenuItem("Burrito", 12.99, 12, "Tortilla", 1));
        myRestaurant.add_menu_item(MenuItem("Quesadilla", 7.99, 12, "Tortilla", 1));
        myRestaurant.add_menu_item(MenuItem("Grilled Cheese Sandwich", 5.99, 8, "Bread", 1));

        // Add some desserts
        myRestaurant.add_menu_item(MenuItem("Chocolate Cake", 8.99, 15, "Chocolate", 1));
        myRestaurant.add_menu_item(MenuItem("Cheesecake", 5.99, 20, "Cheese", 1));
        myRestaurant.add_menu_item(MenuItem("Ice Cream Sundae", 4.99, 10, "Ice Cream", 1));

        // Add some drinks to the menu
        myRestaurant.add_menu_item(MenuItem("Coffee", 2.99, 5, "Coffee Beans", 1));
        myRestaurant.add_menu_item(MenuItem("Tea", 2.49, 4, "Tea Leaves", 1));
        myRestaurant.add_menu_item(MenuItem("Soda", 1.99, 2, "Soda Syrup", 1));
        myRestaurant.add_menu_item(MenuItem("Milkshake", 4.99, 8, "Milk", 1));
        myRestaurant.add_menu_item(MenuItem("Smoothie", 5.99, 7, "Fruit", 1));
        myRestaurant.add_menu_item(MenuItem("Lemonade", 3.49, 6, "Lemon", 1));

        // Initialize inventory with default stock
        initialize_inventory(myRestaurant);

        // Add employees
        std::unique_ptr<Chef> chef = std::make_unique<Chef>("Gordon Ramsay", 101);
        std::unique_ptr<HeadChef> head_chef = std::make_unique<HeadChef>("Jamie Oliver", 102);
        std::unique_ptr<Waiter> waiter = std::make_unique<Waiter>("John Smith", 201);
        std::unique_ptr<Manager> manager = std::make_unique<Manager>("Lisa Johnson", 301);

        myRestaurant.add_employee(chef.get());
        myRestaurant.add_employee(head_chef.get());
        myRestaurant.add_employee(waiter.get());
        myRestaurant.add_employee(manager.get());

        std::unique_ptr<Customer> currentCustomer = nullptr;
        const std::string orders_file = "orders.txt";  // File to store orders
        int option;

        do {
            display_menu();      // Display the main menu
            std::cin >> option;  // Get the user's option choice

            // Check for input failure (non-integer input)
            if (std::cin.fail()) {
                std::cin.clear();  // Clear the input state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
                std::cout << "Invalid input, please enter a number.\n";
                continue;  // Skip the rest of the loop
            }

            try {
                switch (option) {
                    case 1: {
                        if (currentCustomer != nullptr) {
                            std::cout << "A customer is already seated. Please serve them first.\n";
                            break;
                        }

                        // Add customer and seat them
                        std::string name;
                        int table_number;
                        std::cout << "Enter customer name: ";
                        std::cin.ignore();  // Clear buffer
                        std::getline(std::cin, name);
                        std::cout << "Enter table number: ";
                        std::cin >> table_number;

                        currentCustomer = std::make_unique<Customer>(name, table_number);
                        myRestaurant.seat_customer(*currentCustomer);
                        break;
                    }
                    case 2: {
                        // Place customer order
                        if (currentCustomer == nullptr) {
                            std::cout << "No customer is seated. Please seat a customer first.\n";
                            break;
                        }
                        myRestaurant.process_order(*currentCustomer);
                        break;
                    }
                    case 3: {
                        // Serve customer order and save it to file
                        if (currentCustomer == nullptr) {
                            std::cout << "No customer is seated. Please seat a customer first.\n";
                            break;
                        }
                        myRestaurant.serve_order(*currentCustomer, orders_file);
                        currentCustomer = nullptr;  // Remove the customer after serving
                        break;
                    }
                    case 4: {
                        // Restock inventory
                        std::string ingredient;
                        int quantity;

                        // Keep asking for a valid ingredient or exit if 0 is entered
                        while (true) {
                            try {
                                std::cin.ignore();  // Clear buffer before getting input
                                std::cout << "Enter ingredient to restock (or 0 to go back): ";
                                std::getline(std::cin, ingredient);

                                // Trim whitespace from user input
                                ingredient = trim(ingredient);

                                // Convert the input to lowercase for case-insensitive matching
                                std::transform(ingredient.begin(), ingredient.end(), ingredient.begin(), ::tolower);

                                // Check if the user wants to go back to the main menu
                                if (ingredient == "0") {
                                    std::cout << "Returning to main menu...\n";
                                    break;
                                }

                                // Check if the ingredient exists in the inventory by converting the stored ingredients to lowercase
                                bool ingredient_found = false;
                                std::string matched_ingredient;
                                for (const auto& item : myRestaurant.get_inventory().get_stock()) {
                                    std::string lower_item = item.first;
                                    std::transform(lower_item.begin(), lower_item.end(), lower_item.begin(), ::tolower);
                                    if (lower_item == ingredient) {
                                        ingredient_found = true;
                                        matched_ingredient = item.first;
                                        break;
                                    }
                                }

                                // If ingredient does not exist, show the inventory and prompt again
                                if (!ingredient_found) {
                                    std::cout << "Ingredient does not exist. Available ingredients are:\n";
                                    myRestaurant.get_inventory().display_inventory();
                                    throw std::invalid_argument("Please enter a valid ingredient.");
                                }

                                // Input the quantity
                                while (true) {
                                    std::cout << "Enter quantity (or 0 to go back): ";
                                    if (!(std::cin >> quantity)) {  // Check if the input is a valid integer
                                        std::cin.clear();  // Clear the error state
                                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
                                        std::cout << "Invalid input. Please enter a valid number for quantity.\n";
                                        continue;  // Ask again
                                    }

                                    // If quantity is 0, go back to the main menu
                                    if (quantity == 0) {
                                        std::cout << "Returning to main menu...\n";
                                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the newline character from the input buffer
                                        break;
                                    }

                                    // Check the maximum stock before restocking
                                    if (myRestaurant.get_inventory().get_stock().at(matched_ingredient).get_quantity() + quantity > 15) {
                                        std::cout << "Warning: Stock for " << matched_ingredient << " capped at 15 units. ";
                                        std::cout << "Please enter a valid quantity to restock (up to " << (15 - myRestaurant.get_inventory().get_stock().at(matched_ingredient).get_quantity()) << "): \n";
                                        continue;  // Ask for the quantity again
                                    }

                                    // Restock the ingredient with the matched name from the inventory
                                    myRestaurant.get_inventory().restock(matched_ingredient, quantity);
                                    std::cout << "Restocked " << matched_ingredient << " with " << quantity << " units.\n";
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the newline character from the input buffer
                                    break;  // Exit the loop when successful
                                }

                                break;  // Exit the outer loop after successful restocking

                            } catch (const std::invalid_argument& e) {
                                std::cout << e.what() << "\n";  // Display the error message
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ensure the input buffer is cleared
                            }
                        }
                        break;
                    }
                    case 5: {
                        // View inventory
                        myRestaurant.get_inventory().display_inventory();
                        break;
                    }
                    case 6: {
                        // Track performance
                        myRestaurant.track_performance();
                        break;
                    }
                    case 7: {
                        // View menu
                        myRestaurant.view_menu();
                        break;
                    }
                    case 8: {
                        // Save inventory and menu to file
                        myRestaurant.get_inventory().save_to_file("inventory.txt");
                        myRestaurant.get_menu().save_to_file("menu.txt");
                        break;
                    }
                    case 9: {
                        // Load inventory and menu from file
                        myRestaurant.get_inventory().load_from_file("inventory.txt");
                        myRestaurant.get_menu().load_from_file("menu.txt");
                        break;
                    }
                    case 10: {
                        // View saved orders
                        display_saved_orders(orders_file);
                        break;
                    }
                    case 0: {
                        std::cout << "Exiting program...\n";
                        break;
                    }
                    default: {
                        std::cout << "Invalid option. Please try again.\n";
                        break;
                    }
                }
            } catch (const std::exception& e) {
                std::cerr << "An error occurred: " << e.what() << "\n";
            }

        } while (option != 0);

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}

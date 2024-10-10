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
#include <fstream>  // For reading saved orders

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

int main() {
    try {
        Restaurant myRestaurant;

        // Add items to the menu and automatically add associated ingredients to the inventory
        myRestaurant.add_menu_item(MenuItem("Pasta", 12.99, 15, "Pasta", 1));
        myRestaurant.add_menu_item(MenuItem("Burger", 8.99, 10, "Beef Patty", 1));
        myRestaurant.add_menu_item(MenuItem("Salad", 6.99, 5, "Salad Greens", 1));

        // Add employees
        Chef* chef = new Chef("Gordon Ramsay", 101);
        HeadChef* head_chef = new HeadChef("Jamie Oliver", 102);
        Waiter* waiter = new Waiter("John Smith", 201);
        Manager* manager = new Manager("Lisa Johnson", 301);

        myRestaurant.add_employee(chef);
        myRestaurant.add_employee(head_chef);
        myRestaurant.add_employee(waiter);
        myRestaurant.add_employee(manager);

        Customer* currentCustomer = nullptr;
        const std::string orders_file = "orders.txt";  // File to store orders
        int option;

        do {
            display_menu();
            std::cin >> option;

            switch (option) {
                case 1: {
                    // Add customer and seat them
                    std::string name;
                    int table_number;
                    std::cout << "Enter customer name: ";
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    std::cout << "Enter table number: ";
                    std::cin >> table_number;

                    currentCustomer = new Customer(name, table_number);
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
                    delete currentCustomer;
                    currentCustomer = nullptr;
                    break;
                }
                case 4: {
                    // Restock inventory
                    std::string ingredient;
                    int quantity;
                    std::cout << "Enter ingredient to restock: ";
                    std::cin.ignore();
                    std::getline(std::cin, ingredient);
                    std::cout << "Enter quantity: ";
                    std::cin >> quantity;

                    myRestaurant.get_inventory().restock(ingredient, quantity);
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

        } while (option != 0);

        // Cleanup dynamically allocated objects
        delete chef;
        delete head_chef;
        delete waiter;
        delete manager;
        if (currentCustomer != nullptr) {
            delete currentCustomer;
        }

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}

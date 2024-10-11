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
// Function to initialize the inventory with some default items
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
            display_menu();      // Display the main menu
            std::cin >> option;  // Get the user's option choice

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

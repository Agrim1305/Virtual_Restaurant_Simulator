#include "Restaurant.h"
#include "Chef.h"
#include "HeadChef.h"
#include "Waiter.h"
#include "Manager.h"
#include "Customer.h"
#include <iostream>
#include <limits>

void display_menu() {
    std::cout << "==== Virtual Restaurant Simulator ====\n";
    std::cout << "1. Add Customer and Seat Them\n";
    std::cout << "2. Place Customer Order\n";
    std::cout << "3. Serve Customer Order\n";
    std::cout << "4. Restock Inventory\n";
    std::cout << "5. View Inventory\n";
    std::cout << "6. Track Performance\n";
    std::cout << "0. Exit\n";
    std::cout << "Select an option: ";
}

int main() {
    try {
        Restaurant myRestaurant;

        // Add items to the menu
        myRestaurant.get_menu().add_item(MenuItem("Pasta", 12.99, 15, "Pasta", 1));
        myRestaurant.get_menu().add_item(MenuItem("Burger", 8.99, 10, "Beef Patty", 1));
        myRestaurant.get_menu().add_item(MenuItem("Salad", 6.99, 5, "Salad Greens", 1));

        Chef* chef = new Chef("Gordon Ramsay", 101);
        HeadChef* head_chef = new HeadChef("Jamie Oliver", 102);
        Waiter* waiter = new Waiter("John Smith", 201);
        Manager* manager = new Manager("Lisa Johnson", 301);

        myRestaurant.add_employee(chef);
        myRestaurant.add_employee(head_chef);
        myRestaurant.add_employee(waiter);
        myRestaurant.add_employee(manager);

        Customer* currentCustomer = nullptr;
        int option;

        do {
            display_menu();
            std::cin >> option;

            switch (option) {
                case 1: {
                    // Add customer and seat them
                    if (currentCustomer != nullptr) {
                        std::cout << "A customer is already seated. Complete their order first.\n";
                        break;
                    }
                    std::string name;
                    int table_number;
                    std::cout << "Enter customer name: ";
                    std::cin.ignore(); // Clear the newline character from the input buffer
                    std::getline(std::cin, name);
                    std::cout << "Enter table number: ";
                    std::cin >> table_number;

                    currentCustomer = new Customer(name, table_number);  // Seat the customer
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
                    // Serve customer order
                    if (currentCustomer == nullptr) {
                        std::cout << "No customer is seated. Please seat a customer first.\n";
                        break;
                    }
                    myRestaurant.serve_order(*currentCustomer);
                    if (currentCustomer->is_order_completed()) {
                        delete currentCustomer;
                        currentCustomer = nullptr;
                    }
                    break;
                }
                case 4: {
                    // Restock inventory
                    std::string ingredient;
                    int quantity;
                    std::cout << "Enter ingredient to restock: ";
                    std::cin.ignore(); // Clear the input buffer
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
                case 0: {
                    std::cout << "Exiting program...\n";
                    break;
                }
                default: {
                    std::cout << "Invalid option. Please try again.\n";
                    break;
                }
            }

            // After each action, print customer order status (if any customer is seated)
            if (currentCustomer != nullptr) {
                std::cout << *currentCustomer;
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

    } catch (const std::length_error& e) {
        std::cerr << "Length error: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}

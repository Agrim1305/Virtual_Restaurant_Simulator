#include "Restaurant.h"
#include <iostream>

Restaurant::Restaurant() {
    // Constructor implementation (if any initialization is needed)
}

Menu& Restaurant::get_menu() {
    return menu;  // Assuming `menu` is a private member of the Restaurant class
}

Inventory& Restaurant::get_inventory() {
    return inventory;  // Assuming `inventory` is a private member of the Restaurant class
}

void Restaurant::add_employee(Employee* employee) {
    employees.push_back(employee);  // Assuming `employees` is a vector of Employee pointers
}

void Restaurant::seat_customer(Customer& customer) {
    std::cout << "Customer has been seated.\n";
}

void Restaurant::serve_order(Customer& customer) {
    std::cout << "Serving customer order...\n";
}

void Restaurant::track_performance() {
    std::cout << "Tracking performance of employees...\n";
    for (const auto& employee : employees) {
        employee->perform_task();
    }
}

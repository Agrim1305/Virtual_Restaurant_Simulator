#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Menu.h"
#include "Customer.h"
#include "Employee.h"
#include <vector>
#include <fstream>
using namespace std;

// Restaurant class
class Restaurant {
    Menu menu;
    vector<Employee*> employees;
public:
    Restaurant() {
        // Sample Menu Items
        menu.addItem(MenuItem("Pizza", 12.0f));
        menu.addItem(MenuItem("Burger", 8.0f));
    }
    void hireEmployee(Employee* emp) { employees.push_back(emp); }
    void displayEmployees() const {
        for (const auto& emp : employees) {
            cout << emp->getName() << " (" << emp->getRole() << ")" << endl;
        }
    }
    void processOrder(Customer& customer) {
        customer.placeOrder(menu);
        customer.displayOrder();
    }
    void manageRestaurant() {
        for (auto& emp : employees) {
            emp->performDuties();
        }
    }
    void saveData() {
        ofstream file("restaurant_data.txt");
        if (file.is_open()) {
            file << "Restaurant Data Saved!" << endl;
            file.close();
        }
    }
    void loadData() {
        ifstream file("restaurant_data.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        }
    }
};

#endif

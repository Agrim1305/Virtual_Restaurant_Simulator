#include "Restaurant.h"
#include "Employee.h"
#include "Customer.h"
#include <iostream>
using namespace std;

int main() {
    Restaurant restaurant;
    Customer customer("John Doe");

    Chef chef("Gordon Ramsay", 101);
    Waiter waiter("Alice", 102);
    Manager manager("Bob", 103);

    restaurant.hireEmployee(&chef);
    restaurant.hireEmployee(&waiter);
    restaurant.hireEmployee(&manager);

    int choice;
    do {
        cout << "1. Process Order\n2. Manage Restaurant\n3. Save Data\n4. Load Data\n5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        switch (choice) {
            case 1:
                restaurant.processOrder(customer);
                break;
            case 2:
                restaurant.manageRestaurant();
                break;
            case 3:
                restaurant.saveData();
                break;
            case 4:
                restaurant.loadData();
                break;
        }
    } while (choice != 5);

    return 0;
}

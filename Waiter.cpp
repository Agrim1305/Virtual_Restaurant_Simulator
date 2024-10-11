#include "Waiter.h"

// Initializes the Waiter's name and ID using the Employee base class constructor
Waiter::Waiter(const std::string& name, int id) : Employee(name, id) {}

// Outputs the Waiter's name and indicates that they are serving food to customers
void Waiter::perform_task() const {
    std::cout << "Waiter " << name << " is serving food to customers.\n";
}

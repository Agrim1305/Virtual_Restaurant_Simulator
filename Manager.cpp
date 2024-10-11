#include "Manager.h"

// Initializes the Manager's name and ID using the Employee base class constructor
Manager::Manager(const std::string& name, int id) : Employee(name, id) {}

// Outputs the Manager's name and indicates that they are supervising the restaurant
void Manager::perform_task() const {
    std::cout << "Manager " << name << " is supervising the restaurant.\n";
}

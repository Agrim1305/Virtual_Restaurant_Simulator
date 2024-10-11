#include "Chef.h"

//Chef class, initializes the Chef's name and ID
Chef::Chef(const std::string& name, int id) : Employee(name, id) {}

// Outputs the Chef's name and indicates that the Chef is preparing food
void Chef::perform_task() const {
    std::cout << "Chef " << name << " is preparing food.\n";
}

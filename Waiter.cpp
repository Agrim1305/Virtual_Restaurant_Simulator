#include "Waiter.h"
#include <iostream>

Waiter::Waiter(const std::string& name, int id) : Employee(name, id, "Waiter") {}

void Waiter::perform_task() const {
    std::cout << "Waiter " << name << " is serving the order..." << std::endl;
}

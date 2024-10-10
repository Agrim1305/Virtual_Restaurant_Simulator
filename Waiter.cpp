#include "Waiter.h"

Waiter::Waiter(const std::string& name, int id) : Employee(name, id) {}

void Waiter::perform_task() const {
    std::cout << "Waiter " << name << " is serving food to customers.\n";
}

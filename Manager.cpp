#include "Manager.h"

Manager::Manager(const std::string& name, int id) : Employee(name, id) {}

void Manager::perform_task() const {
    std::cout << "Manager " << name << " is supervising the restaurant.\n";
}

#include "Manager.h"
#include <iostream>

Manager::Manager(const std::string& name, int id)
    : Employee(name, id, "Manager") {}

void Manager::perform_task() const {
    std::cout << "Manager " << get_name() << " is managing the restaurant staff.\n";
}

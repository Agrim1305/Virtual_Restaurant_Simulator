#include "Manager.h"
#include <iostream>

Manager::Manager(const std::string& name, int id) : Employee(name, id, "Manager") {}

void Manager::perform_task() const {
    std::cout << "Manager " << name << " is overseeing the restaurant..." << std::endl;
}

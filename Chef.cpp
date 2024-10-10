#include "Chef.h"
#include <iostream>

Chef::Chef(const std::string& name, int id) : Employee(name, id, "Chef") {}

void Chef::perform_task() const {
    std::cout << "Chef " << name << " is preparing the order..." << std::endl;
}

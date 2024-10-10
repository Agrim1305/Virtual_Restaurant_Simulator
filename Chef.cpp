#include "Chef.h"

Chef::Chef(const std::string& name, int id) : Employee(name, id) {}

void Chef::perform_task() const {
    std::cout << "Chef " << name << " is preparing food.\n";
}

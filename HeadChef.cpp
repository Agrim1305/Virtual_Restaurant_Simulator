#include "HeadChef.h"

HeadChef::HeadChef(const std::string& name, int id) : Chef(name, id) {}

void HeadChef::perform_task() const {
    std::cout << "Head Chef " << name << " is managing the kitchen.\n";
}

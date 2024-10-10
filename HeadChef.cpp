#include "HeadChef.h"
#include <iostream>

HeadChef::HeadChef(const std::string& name, int id)
    : Chef(name, id) {}

void HeadChef::perform_task() const {
    std::cout << "HeadChef " << get_name() << " is overseeing the kitchen and planning the menu.\n";
}

void HeadChef::plan_menu() const {
    std::cout << "HeadChef is planning the menu for the next season.\n";
}

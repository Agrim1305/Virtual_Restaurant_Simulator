#include "Employee.h"

Employee::Employee(const std::string& name, int id) : name(name), id(id) {}

std::string Employee::get_name() const {
    return name;
}

int Employee::get_id() const {
    return id;
}

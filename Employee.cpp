#include "Employee.h"

Employee::Employee(const std::string& name, int id, const std::string& role)
    : Person(name, id), role(role) {}

std::string Employee::get_role() const {
    return role;
}

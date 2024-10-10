#include "Employee.h"

// Constructor for Employee, invoking the Person constructor
Employee::Employee(const std::string& name, int id, const std::string& position)
    : Person(name, id), position(position) {}

// Getter for position
std::string Employee::get_position() const {
    return position;
}

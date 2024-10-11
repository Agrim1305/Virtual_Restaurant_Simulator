#include "Employee.h"

//Employee's name and ID using the provided arguments
Employee::Employee(const std::string& name, int id) : name(name), id(id) {}

// Method to return the Employee's name
std::string Employee::get_name() const {
    return name;
}

// Method to return the Employee's ID
int Employee::get_id() const {
    return id;
}

#include "Employee.h"
#include <iostream>

Employee::Employee(std::string name, int id, std::string role)
    : name(name), id(id), role(role) {}

std::string Employee::get_name() const {
    return name;
}

std::string Employee::get_role() const {
    return role;
}

Chef::Chef(std::string name, int id) : Employee(name, id, "Chef") {}

void Chef::prepare_order(const Order& order) {
    std::cout << "Chef " << name << " is preparing the order..." << std::endl;
}

void Chef::perform_task() {
    std::cout << "Chef " << name << " is performing a task..." << std::endl;
}

Waiter::Waiter(std::string name, int id) : Employee(name, id, "Waiter") {}

void Waiter::serve_order(const Order& order) {
    std::cout << "Waiter " << name << " is serving the order..." << std::endl;
}

void Waiter::assign_table(int table_number) {
    std::cout << "Waiter " << name << " is assigning a customer to table " << table_number << std::endl;
}

void Waiter::perform_task() {
    std::cout << "Waiter " << name << " is performing a task..." << std::endl;
}

Manager::Manager(std::string name, int id) : Employee(name, id, "Manager") {}

void Manager::manage_staff(std::vector<Employee*>& staff) {
    std::cout << "Manager " << name << " is managing the staff..." << std::endl;
}

void Manager::perform_task() {
    std::cout << "Manager " << name << " is performing a task..." << std::endl;
}

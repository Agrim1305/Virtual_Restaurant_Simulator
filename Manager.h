#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"
#include <iostream>

// Declaration of the Manager class that inherits from the Employee class
class Manager : public Employee {
public:
    Manager(const std::string& name, int id); //Manager class that initializes the Manager's name and ID
    void perform_task() const override;  // This makes the Manager class provide its own implementation of perform_task
};

#endif

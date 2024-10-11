#ifndef CHEF_H
#define CHEF_H

#include "Employee.h"
#include <iostream>

// Declaration of the Chef class that inherits from Employee
class Chef : public Employee {
public:
// Constructor that takes the name and ID of the Chef
    Chef(const std::string& name, int id);

     // Overridden method to define the specific task a Chef performs
    void perform_task() const override;
};

#endif

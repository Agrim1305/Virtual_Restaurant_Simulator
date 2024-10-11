#ifndef WAITER_H
#define WAITER_H

#include "Employee.h"
#include <iostream>

// Declaration of the Waiter class that inherits from the Employee class
class Waiter : public Employee {
public:
// Waiter class that initializes the Waiter's name and ID
    Waiter(const std::string& name, int id);
    void perform_task() const override;
};

#endif

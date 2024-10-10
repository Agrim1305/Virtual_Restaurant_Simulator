#ifndef WAITER_H
#define WAITER_H

#include "Employee.h"
#include <iostream>

class Waiter : public Employee {
public:
    Waiter(const std::string& name, int id);
    void perform_task() const override;
};

#endif

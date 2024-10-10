#ifndef WAITER_H
#define WAITER_H

#include "Employee.h"

class Waiter : public Employee {
public:
    Waiter(const std::string& name, int id);

    // Override perform_task for Waiter
    void perform_task() const override;
};

#endif

#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee {
public:
    Manager(const std::string& name, int id);

    void perform_task() const override;  // Override the virtual function
};

#endif

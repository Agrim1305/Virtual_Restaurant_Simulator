#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee {
public:
    Manager(const std::string& name, int id);

    // Override perform_task for Manager
    void perform_task() const override;
};

#endif

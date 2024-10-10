#ifndef CHEF_H
#define CHEF_H

#include "Employee.h"

class Chef : public Employee {
public:
    Chef(const std::string& name, int id);

    // Override perform_task for Chef
    void perform_task() const override;
};

#endif

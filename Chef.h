#ifndef CHEF_H
#define CHEF_H

#include "Employee.h"
#include <iostream>

class Chef : public Employee {
public:
    Chef(const std::string& name, int id);
    void perform_task() const override;
};

#endif

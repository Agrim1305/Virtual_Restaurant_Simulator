#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
protected:
    std::string name;
    int id;

public:
    Employee(std::string name, int id);
    virtual void perform_task() = 0; // Abstract method to be defined by derived classes
    virtual ~Employee() = default; // Virtual destructor
};

#endif

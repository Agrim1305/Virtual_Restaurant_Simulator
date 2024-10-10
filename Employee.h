#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
protected:
    std::string role;

public:
    Employee(const std::string& name, int id, const std::string& role);

    virtual void perform_task() const = 0;  // Pure virtual function
    std::string get_role() const;

    virtual ~Employee() {}  // Ensure proper cleanup
};

#endif

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <string>

class Employee : public Person {
protected:
    std::string position;

public:
    // Constructor for Employee
    Employee(const std::string& name, int id, const std::string& position);

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Employee() = default;

    // Virtual function for task performance
    virtual void perform_task() const = 0;

    // Getter for position
    std::string get_position() const;
};

#endif
